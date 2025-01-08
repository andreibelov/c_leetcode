/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniquePaths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:39:29 by abelov            #+#    #+#             */
/*   Updated: 2025/01/08 18:39:30 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

/**
 * 62. Unique Paths
 *
 * There is a robot on an m x n grid.
 * The robot is initially located at the top-left corner (i.e., grid[0][0]).
 * The robot tries to move to the bottom-right corner.
 * The robot can only move either down or right at any point in time.
 *
 * Given the two integers m and n, return the number of possible unique paths
 * that the robot can take to reach the bottom-right corner.
 *
 * The test cases are generated so that the answer will be less than or equal
 * to 2 * 10^9.
 */
int uniquePaths(int m, int n);

#ifdef DYN_PROG

int uniquePaths(int m, int n)
{
	if (m == 0 || n == 0) return (0);
	if (m == 1 || n == 1) return (1);
	if (m > n) { m ^= n; n ^= m; m ^= n; } // xor swap m with n

	int dp[101];
	for (int i = -1; ++i < n; dp[i] = i + 1);

	for (int i = 2; i < m; i++)
		/* straightforward approach */
//		for (int j = 1; j < n; j++) dp[j] += dp[j - 1];
		/* using Cholesky decomposition */
		for (int j = i; j < n; j++)
		{
			if (i == j) dp[j] *= 2;
			else dp[j] += dp[j - 1];
		}
	return (dp[n - 1]);
}

#elif defined DFS

#define MAX_QUEUE_SIZE 100000

typedef struct Point { int x, y; }	Point;
Point add(Point a, Point b) { return (Point){.x = a.x + b.x, .y = a.y + b.y}; }
int equ(Point a, Point b) { return (a.x == b.x && a.y == b.y); }
int check_boundaries(Point point, Point max) { return ((point.x >= 0 && point.y >= 0) && (point.x < max.x && point.y < max.y)); }

int uniquePaths(int m, int n)
{
	static const Point	view[2] = {
		{.x = 0, .y =  1}, // Down
		{.x = 1, .y =  0}  // Right
	};

	int ways = 0;
	Point end = {m - 1, n - 1};
	Point max = {m, n};

	int front = 0, rear = 0;  // Queue front and rear pointers
	Point queue[MAX_QUEUE_SIZE];
	Point p;
	queue[rear++] = (Point){0, 0};
	while(front != rear)
	{
		p = queue[front++];
		front %= MAX_QUEUE_SIZE;

		if (equ(p, end))
			ways++;
		else
		{
			int i = -1;
			while (++i < 2)
			{
				Point new = add(p, view[i]);
				if (check_boundaries(new, max))
				{
					queue[rear++] = new;
					rear %= MAX_QUEUE_SIZE;
				}
			}
		}
	}

	return (ways);
}

#else

int uniquePaths(int m, int n)
{
	// Initialize result to 1, as we'll calculate the combination iteratively
	long long result = 1;

	// We choose (m-1) or (n-1) steps to go down or right, whichever is smaller
	int totalSteps = m + n - 2;
	int stepsToChoose = (m - 1 < n - 1) ? m - 1 : n - 1;

	// Calculate the combination using iterative approach
	for (int i = 1; i <= stepsToChoose; i++)
		result = result * (totalSteps - (stepsToChoose - i)) / i;

	return (int) result;
}

#endif
