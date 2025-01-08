/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearestExit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:45:45 by abelov            #+#    #+#             */
/*   Updated: 2025/01/05 22:45:46 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define MAX 101
#define MAX_QUEUE_SIZE 10000

typedef struct
{
	int row, col;
} Coord;

typedef struct
{
	Coord point;
	int distance;
} Node;

// Function to check if the point is valid
static inline int in_boundaries(int rows, int cols, int row, int col)
{
	return (row >= 0 && row < rows && col >= 0 && col < cols);
}

/**
 * 1926. Nearest Exit from Entrance in Maze
 *
 * You are given an m x n matrix mazewith empty cells ('.') and walls ('+').
 * You are also given the `entrance` of the maze: the row and column of the cell
 * you are initially standing at.
 *
 * Return the number of steps in the shortest path from the entrance
 * to the nearest exit, or -1 if no such path exists.
 *
 * Will use BFS to find the shortest path to the nearest exit
 */
int nearestExit(char **maze, int mazeSize, const int *mazeColSize,
				const int *entrance, int entranceSize)
{
	int retval = -1;
	int rows = mazeSize;
	int cols = mazeColSize[0];
	static int directions[4][2] = {{-1, 0},
								   {1,  0},
								   {0,  -1},
								   {0,  1}};

	char visited[MAX][MAX] = {0};

	Node queue[MAX_QUEUE_SIZE];
	int front = 0, rear = 0;

	queue[rear++] = (Node) {{entrance[0], entrance[1]}, 0};
	visited[entrance[0]][entrance[1]] = 1;

	// Perform BFS
	while (front < rear)
	{
		Node cur = queue[front++];
		front %= MAX_QUEUE_SIZE;
		Coord *p = &cur.point;

		/* Check if we're at an exit (not the entrance) and at a boundary */
		if ((p->row != entrance[0] || p->col != entrance[1]) &&
			(p->row == 0 || p->row == rows - 1 || p->col == 0 || p->col == cols - 1))
		{
			retval = cur.distance;
			break;
		}
		/* Explore neighbors */
		int i = -1;
		while (++i < 4)
		{
			Coord new = {p->row + directions[i][0], p->col + directions[i][1]};
			if (in_boundaries(rows, cols, new.row, new.col) && maze[new.row][new.col] == '.' &&
				!visited[new.row][new.col])
			{
				queue[rear++] = (Node) {new, cur.distance + 1};
				rear %= MAX_QUEUE_SIZE;
				visited[new.row][new.col] = 1;
			}
		}
	}

	return (retval);
}
