/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minReorder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:25:56 by abelov            #+#    #+#             */
/*   Updated: 2025/01/06 14:27:16 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * 1466. Reorder Routes to Make All Paths Lead to the City Zero
 *
 * There are n cities numbered from 0 to n - 1 and n - 1 roads such
 * that there is only one way to travel between two different cities
 * (this network form a tree).
 *
 * Last year, The ministry of transport decided to orient the roads
 * in one direction because they are too narrow.
 *
 * Roads are represented by connections where connections[i] = [ai, bi]
 * represents a road from city ai to city bi.
 *
 * This year, there will be a big event in the capital (city 0),
 * and many people want to travel to this city.
 *
 * Your task consists of reorienting some roads such that each city
 * can visit the city 0. Return the minimum number of edges changed.
 * It's guaranteed that each city can reach city 0 after reorder.
 */
int minReorder(int n, int **connections, int connectionsSize,
			   int *connectionsColSize);

#define MAX_NODES 100005
#define STACK_SIZE 1024

typedef struct
{
	int city;
	int direction;  /* 1 if it's the original direction */
} Edge;

void addEdge(int from, int to, int isOriginal, Edge *graph[MAX_NODES], int *degree)
{
	graph[from] = realloc(graph[from], (degree[from] + 1) * sizeof(Edge));
	graph[from][degree[from]].city = to;
	graph[from][degree[from]].direction = isOriginal;
	degree[from]++;
}

int dfs(int startNode, int startParent, Edge *graph[MAX_NODES], const int *degree)
{

	int stack[STACK_SIZE][2];
	int ss = 0;
	int reversals = 0;

	stack[ss][0] = startNode;
	stack[ss][1] = startParent;
	ss++;

	while(ss)
	{
		ss--;
		int node = stack[ss][0];
		int parent = stack[ss][1];

		int i = -1;
		while (++i < degree[node])
		{
			int nextCity = graph[node][i].city;
			int direction = graph[node][i].direction;

			if (nextCity == parent) continue;
			if (direction == 1) reversals++;

			stack[ss][0] = nextCity;
			stack[ss][1] = node;
			ss++;
		}
	}
	return reversals;
}

int minReorder(int n, int **connections, int connectionsSize,
			   int *connectionsColSize)
{
	Edge *graph[MAX_NODES] = {0};  /* Adjacency list representation */
	int degree[MAX_NODES] = {0};   /* Degree of each node (number of connections) */

	/* Build the graph: for each road, add the edge in both directions */
	int i = -1;
	while (++i < connectionsSize)
	{
		int from = connections[i][0];
		int to = connections[i][1];
		addEdge(from, to, 1, graph, degree); /* Add the original edge */
		addEdge(to, from, 0, graph, degree); /* Add the reverse edge (to -> from) */
	}

	int retval = dfs(0, -1, graph, degree);

	i = -1;
	while (++i < n)
	{
		Edge *edge = graph[i];
		if (edge)
		{
			graph[i] = NULL;
			free(edge);
		}
	}
	return (retval);
	(void)connectionsColSize;
}
