/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:08:26 by abelov            #+#    #+#             */
/*   Updated: 2025/01/06 17:08:27 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

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
 *
 * Constraints:
 * 	m == grid.length
 *  n == grid[i].length
 *  1 <= m, n <= 10
 *  grid[i][j] is 0, 1, or 2.
 */
int orangesRotting(int **grid, int gridSize, const int *gridColSize);

typedef struct s_input
{
	TwoDArray	grid;
	int			expected;
}	Input;

static int ft_do_test(Input *input)
{
	int result;
	int check_val;

	int **grid = (int **) alloca(input->grid.size * sizeof(int *));
	int *gridColSize = (int *) alloca(input->grid.size * sizeof(int));

	while (input->grid.iter < input->grid.size)
	{
		Array *ar = &input->grid.arrays[input->grid.iter];
		grid[input->grid.iter] = ar->arr;
		gridColSize[input->grid.iter] = ar->size;
		input->grid.iter++;
	}

	result =orangesRotting(grid, input->grid.size, gridColSize);
	check_val = (result == input->expected);
	if (!check_val)
	{
		printf("got \"%d\" elements whilst \"%d\" was to be expected\n",
			   result, input->expected);
	}
	check(check_val);
	return (0);
}

int main(void)
{
	int i;
	Input inputs[] = {
		{
			.grid = (TwoDArray){
				.arrays = (Array [5]){
					{(int []){2,1,1}, .size = 3},
					{(int []){1,1,0}, .size = 3},
					{(int []){0,1,1}, .size = 3},
				},
				.size = 3,
				.iter = 0
			},
			.expected = 4
		},
		{
			.grid = (TwoDArray){
				.arrays = (Array [5]){
					{(int []){2,1,1}, .size = 3},
					{(int []){0,1,1}, .size = 3},
					{(int []){1,0,1}, .size = 3},
				},
				.size = 3,
				.iter = 0
			},
			.expected = -1
		},
		{
			.grid = (TwoDArray){
				.arrays = (Array [5]){
					{(int []){0,2}, .size = 2},
				},
				.size = 1,
				.iter = 0
			},
			.expected = 0
		},
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
