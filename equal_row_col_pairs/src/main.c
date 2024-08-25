/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:58:58 by abelov            #+#    #+#             */
/*   Updated: 2024/08/25 19:58:58 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

int equalPairs(int **grid, int gridSize, const int *gridColSize);

struct s_input
{
	int **grid;
	int gridSize;
	int *gridColSize;
	int expected;
};

int ft_do_test(struct s_input *input)
{
	int result;
	int check_val;
	int i;

	i = -1;
	while (++i < input->gridSize)
		ft_print_int_tab(input->grid[i], input->gridColSize[i], "\n");
	result = equalPairs(input->grid, input->gridSize, input->gridColSize);
	check_val = (input->expected == result);
	if (!check_val)
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   result, input->expected);
	check(check_val);
	return (0);
}

int main(void)
{
	int i;
	struct s_input inputs[] = {
		{
			.grid = (int *[3]) {(int[]) {3, 2, 1}, (int[]) {1, 7, 63}, (int[]) {2, 7, 7}},
			.gridSize = 3,
			.gridColSize = (int[3]) {3, 3, 3},
			.expected = 1,
		},
		{
			.grid = (int *[3]) {(int[]) {250,78,253}, (int[]) {334,252,253}, (int[]) {250,253,253}},
			.gridSize = 3,
			.gridColSize = (int[3]) {3, 3, 3},
			.expected = 0,
		},
		{
			.grid = (int *[3]) {(int[]) {1,11,21}, (int[]) {22,1,1}, (int[]) {20,1,1}},
			.gridSize = 3,
			.gridColSize = (int[3]) {3, 3, 3},
			.expected = 0,
		},
		{
			.grid = (int *[]) {(int[]) {3, 1, 2, 2}, (int[]) {1, 4, 4, 5}, (int[]) {2, 4, 2, 2}, (int[]) {2, 4, 2, 2}},
			.gridSize = 4,
			.gridColSize = (int[]) {4, 4, 4, 4},
			.expected = 3,
		}
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
