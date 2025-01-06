/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orangesRotting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:11:59 by abelov            #+#    #+#             */
/*   Updated: 2025/01/06 17:11:59 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * 994. Rotting Oranges
 *
 * You are given an m x n grid where each cell can have one of three values:
 * 	0 representing an empty cell,
 *  1 representing a fresh orange, or
 *  2 representing a rotten orange.
 * Every minute, any fresh orange that is 4-directionally adjacent
 * to a rotten orange becomes rotten.
 *
 * Return the minimum number of minutes that must elapse until no cell has
 * a fresh orange. If this is impossible, return -1
 */
int orangesRotting(int **grid, int gridSize, const int *gridColSize);

int rotting_process(int **grid, int rows, int cols, int timestamp)
{
	int continue_process = 0;
	static int directions[4][2] = {{-1, 0},
								   {0,  1},
								   {1,  0},
								   {0,  -1}};

	int row = -1;
	while(++row < rows)
	{
		int col = -1;
		while (++col < cols)
		{
			if (grid[row][col] == timestamp)
			{
				int i = -1;
				while (++i < 4)
				{
					int r = row + directions[i][0];
					int c = col + directions[i][1];
					if (rows > r && r >= 0 && cols > c && c >= 0)
					{
						if (grid[r][c] == 1)
						{
							grid[r][c] = timestamp + 1;
							continue_process = 1;
						}
					}
				}
			}
		}
	}
	return continue_process;
}

int orangesRotting(int **grid, int gridSize, const int *gridColSize)
{

	int rows = gridSize;
	int cols = gridColSize[0];

	int timestamp = 2;
	while (rotting_process(grid, rows, cols, timestamp))
		timestamp += 1;
	int row = -1;
	while(++row < rows)
	{
		int col = -1;
		while (++col < cols)
			if (grid[row][col] == 1) return -1;
	}
	return timestamp - 2;
}
