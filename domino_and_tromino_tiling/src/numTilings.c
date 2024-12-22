/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numTilings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:39:31 by abelov            #+#    #+#             */
/*   Updated: 2024/12/22 16:39:32 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * 790. Domino and Tromino Tiling
 *
 * Given an integer n, return the number of ways to tile an 2 x n board.
 * Since the answer may be very large, return it modulo 109 + 7.
 *
 * In a tiling, every square must be covered by a tile.
 * Two tilings are different if and only if there are two 4-directionally
 * adjacent cells on the board such that exactly one of the tilings has both
 * squares occupied by a tile.
 */
int numTilings(int n);

#ifndef RECURSIVE

static const int MOD = 1e9 + 7;

typedef struct s_tw
{ long i, j, k, z; } t_tw;

int numTilings(int n)
{
	int i = 0;
	long ntw[4] = {};
	long tw[4] = {1, 0, 0, 0};

	while(++i <= n)
	{
		*(t_tw *)ntw = (t_tw){0, 0, 0, 0};
		ntw[0] = (tw[0] + tw[1] + tw[2] + tw[3]) % MOD;
		ntw[1] = (tw[2] + tw[3]) % MOD;
		ntw[2] = (tw[1] + tw[3]) % MOD;
		ntw[3] = tw[0];
		*(t_tw *)tw = *(t_tw *)ntw;
	}
	return ((int)tw[0]);
}

#else

static const int MOD = 1e9 + 7;
int g_n;


int dfs(int i, int j)
{
	if (i > g_n || j > g_n)
		return (0);
	if (i == g_n && j == g_n)
		return (1);

	long ways = 0;
	if (i == j) //  both rows are equally tiled thus far.
		ways = dfs(i + 2, j + 2) +  // Place a 2x2 square.
			   dfs(i + 1, j + 1) +  // Place two 2x1 tiles, one in each row.
			   dfs(i + 2, j + 1) +  // Place a 'L' shaped tromino.
			   dfs(i + 1, j + 2);   // Place an inverted 'L' shaped tromino.
	else if (i > j)
		ways = dfs(i, j + 2) +
			   dfs(i + 1, j + 2);
	else
		ways = dfs(i + 2, j) +
			   dfs(i + 2, j + 1);
	return (ways % MOD);
}


int numTilings(int n)
{
	g_n = n;
	return (dfs(0,0));
}


#endif

