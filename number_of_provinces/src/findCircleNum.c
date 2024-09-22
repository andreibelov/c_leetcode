/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findCircleNum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:54:34 by abelov            #+#    #+#             */
/*   Updated: 2024/09/22 19:54:35 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * 547. Number of Provinces
 *
 * There are n cities. Some of them are connected, while some are not.
 * If city a is connected directly with city b,
 * and city b is connected directly with city c,
 * then city a is connected indirectly with city c.
 *
 * A province is a group of directly or indirectly connected cities
 * and no other cities outside of the group.
 *
 * You are given an n x n matrix isConnected.
 * Return the total number of provinces.
 */
int findCircleNum(int **isConnected, int isConnectedSize, const int *isConnectedColSize);

#define MAX_STACK_SIZE 10000

static void dfs(int **isConnected, int isConnectedSize, int city, int *visited)
{
	int neighbor;
	int sp = 0;
	int stack[MAX_STACK_SIZE];
	int current_city;

	stack[sp++] = city;  // Push the starting node
	visited[city] = 1;  // Mark the starting node as visited

	while (sp)
	{
		current_city = stack[--sp];

		neighbor = -1;  // Iterator for neighbors
		while (++neighbor < isConnectedSize)
		{
			/* If the node is connected and not visited */
			if (isConnected[current_city][neighbor] == 1 && !visited[neighbor])
			{
				stack[sp++] = neighbor; // Push the connected node to the stack
				visited[neighbor] = 1;  // Mark it as visited
			}
		}
	}
}

int findCircleNum(int **isConnected, int isConnectedSize,
				  const int *isConnectedColSize)
{
	int i;
	int city;
	int numberOfCities = isConnectedSize;
	int provinceCount = 0;
	int visited[numberOfCities];

	i = -1;
	/* Initialize visited array */
	while (++i < numberOfCities)
		visited[i] = 0;

	city = -1;
	while (++city < numberOfCities)
	{
		if (!visited[city])
		{
			dfs(isConnected, isConnectedSize, city, visited);
			provinceCount++;
		}
	}
	return provinceCount;
	(void)isConnectedColSize;
}
