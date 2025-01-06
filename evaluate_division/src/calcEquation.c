/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcEquation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:48:37 by abelov            #+#    #+#             */
/*   Updated: 2025/01/06 11:48:38 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

/**
 * 399. Evaluate Division
 *
 * You are given an array of variable pairs equations and
 * an array of real numbers values, where equations[i] = [Ai, Bi] and values[i]
 * represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string
 * that represents a single variable.
 *
 * You are also given some queries, where queries[j] = [Cj, Dj] represents
 * the jth query where you must find the answer for Cj / Dj = ?.
 *
 * Return the answers to all queries.
 * If a single answer cannot be determined, return -1.0.
 */
double *calcEquation(char ***equations, int equationsSize,
					 const int *equationsColSize, const double *values,
					 int valuesSize, char ***queries, int queriesSize,
					 const int *queriesColSize, int *returnSize);

typedef struct GraphNode
{
	char *key;
	struct GraphNode **neighbors;
	double *weights;
	int size;
} GraphNode;

typedef struct
{
	GraphNode *node;
	double value;
} QueueNode;

typedef struct HashMap
{
	GraphNode **nodes;
	int size;
} HashMap;

#define HASH_SIZE 100
#define QUEUE_SIZE 1024
#define STACK_SIZE 10000

int hashFunc(const char *key)
{
	unsigned long hash = 5381;
	while (*key)
		hash = ((hash << 5) + hash) + *key++;
	return (int)(hash % HASH_SIZE);
}

HashMap *createHashMap()
{
	HashMap *map = (HashMap *) malloc(sizeof(HashMap));
	map->size = 0;
	map->nodes = (GraphNode **) calloc(HASH_SIZE, sizeof(GraphNode *));
	return (map);
}

GraphNode *createGraphNode(char *key)
{
	GraphNode *node = (GraphNode *) malloc(sizeof(GraphNode));
	node->key = strdup(key);
	node->size = 0;
	node->neighbors = NULL;
	node->weights = NULL;
	return (node);
}

void insertNode(HashMap *map, char *key)
{
	int index = hashFunc(key);
	while (map && map->nodes[index] != NULL && strcmp(map->nodes[index]->key, key) != 0)
		index = (index + 1) % HASH_SIZE;
	if (map && map->nodes[index] == NULL)
	{
		map->nodes[index] = createGraphNode(key);
		map->size++;
	}
}

GraphNode *getNode(HashMap *map, char *key)
{
	int index = hashFunc(key);
	while (map && map->nodes[index] != NULL && strcmp(map->nodes[index]->key, key) != 0)
		index = (index + 1) % HASH_SIZE;
	return (map ? map->nodes[index] : NULL);
}

void cleanGraph(GraphNode *startNode)
{
	if (startNode == NULL)
		return;

	GraphNode *stack[STACK_SIZE];
	int ss = 0;
	int i;

	stack[ss++] = startNode;

	while (ss)
	{
		GraphNode *node = stack[--ss];
		free(node->key);
		if (node->neighbors)
		{
			i = -1;
			while (++i < node->size)
				if (node->neighbors[i]) stack[ss++] = node->neighbors[i];
			free(node->neighbors);
		}
		if (node->weights) free(node->weights);
		free(node);
	}
}

void addEdge(HashMap *map, char *start, char *end, double value)
{
	GraphNode *startNode = getNode(map, start);
	GraphNode *endNode = getNode(map, end);

	if (startNode)
	{
		startNode->neighbors = (GraphNode **) realloc(startNode->neighbors,
													  (startNode->size + 1) * sizeof(GraphNode *));
		startNode->weights = (double *) realloc(startNode->weights, (startNode->size + 1) * sizeof(double));

		startNode->neighbors[startNode->size] = endNode;
		startNode->weights[startNode->size] = value;
		startNode->size++;
	}
}

int bfs(GraphNode *start, GraphNode *end, double *result)
{
	int retval = 0;

	if (start == end)
	{
		*result = 1.0;
		retval = 1;
	}
	else
	{
		QueueNode queue[QUEUE_SIZE];
		int front = 0, rear = 0;
		queue[rear++] = (QueueNode) {start, 1.0};

		int visited[HASH_SIZE] = {0};
		visited[hashFunc(start->key)] = 1;

		while (front < rear)
		{
			QueueNode current = queue[front++];
			front %= QUEUE_SIZE;
			for (int i = 0; i < current.node->size; ++i)
			{
				GraphNode *neighbor = current.node->neighbors[i];
				double newValue = current.value * current.node->weights[i];
				if (neighbor == end)
				{
					*result = newValue;
					retval = 1;
					break;
				}
				int neighborIdx = hashFunc(neighbor->key);
				if (!visited[neighborIdx])
				{
					visited[neighborIdx] = 1;
					queue[rear++] = (QueueNode) {neighbor, newValue};
					rear %= QUEUE_SIZE;
				}
			}
		}
	}
	return (retval);
}

double *calcEquation(char ***equations, int equationsSize,
					 const int *equationsColSize, const double *values,
					 int valuesSize, char ***queries, int queriesSize,
					 const int *queriesColSize, int *returnSize)
{
	HashMap *map = createHashMap();

	int i = -1;
	while (++i < equationsSize)
	{
		char *u = equations[i][0];
		char *v = equations[i][1];
		double value = values[i];

		insertNode(map, u);
		insertNode(map, v);

		addEdge(map, u, v, value);
		addEdge(map, v, u, 1.0 / value);
	}
	*returnSize = queriesSize;
	double *results = (double *) malloc(queriesSize * sizeof(double));

	i = -1;
	while (++i < queriesSize)
	{
		char *u = queries[i][0];
		char *v = queries[i][1];

		GraphNode *startNode = getNode(map, u);
		GraphNode *endNode = getNode(map, v);

		if (startNode == NULL || endNode == NULL) results[i] = -1.0;
		else
		{
			double result = 1.0;
			if (bfs(startNode, endNode, &result)) results[i] = result;
			else results[i] = -1.0;
		}
	}

	i = -1;
	while (++i < HASH_SIZE)
	{
		GraphNode  *node = map->nodes[i];
		if (node)
		{
			free(map->nodes[i]->key);
			if (node->neighbors) free(node->neighbors);
			if (node->weights) free(node->weights);
			free(node);
		}
	}
	free(map->nodes);
	free(map);

	return (results);
	(void)valuesSize;
	(void)queriesColSize;
	(void)equationsColSize;
}
