/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:54:09 by abelov            #+#    #+#             */
/*   Updated: 2024/09/22 19:54:09 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 547. Number of Provinces
 *
 * Constraints:
 * 	1 <= n <= 200
 * 	n == isConnected.length
 * 	n == isConnected[i].length
 * 	isConnected[i][j] is 1 or 0.
 * 	isConnected[i][i] == 1
 * 	isConnected[i][j] == isConnected[j][i]
 */
int findCircleNum(int **isConnected, int isConnectedSize, int *isConnectedColSize);

#define MAX_CITIES 1000

struct s_test_case
{
	TwoDArray	isConnected;
	int			expected;
};

int ft_do_test(struct s_test_case *input)
{
	int i;
	int *isConnected[MAX_CITIES];
	int *sizes;
	int result;
	int check_val;

	sizes = (int *)alloca(input->isConnected.size * sizeof(Array));
	i = -1;
	while (++i < input->isConnected.size)
	{
		sizes[i] = input->isConnected.arrays[i].size;
		isConnected[i] = input->isConnected.arrays[i].arr;
		ft_print_int_tab(isConnected[i], sizes[i], NULL);
	}

	result = findCircleNum(isConnected, input->isConnected.size, sizes);
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
	struct s_test_case cases[] = {
		{
			.isConnected = (TwoDArray){
				.arrays = (Array [3]){
					{(int [3]){1,1,0}, .size = 3},
					{(int [3]){1,1,0}, .size = 3},
					{(int [3]){0,0,1}, .size = 3}
				},
				.size = 3
			},
			.expected = 2
		},
		{
			.isConnected = (TwoDArray){
				.arrays = (Array [3]){
					{(int [3]){1,0,0}, .size = 3},
					{(int [3]){0,1,0}, .size = 3},
					{(int [3]){0,0,1}, .size = 3}
				},
				.size = 3
			},
			.expected = 3
		},
		{
			.isConnected = (TwoDArray){
				.arrays = (Array [4]){
					{(int [4]){1,1,0,0}, .size = 4},
					{(int [4]){1,1,0,0}, .size = 4},
					{(int [4]){0,0,1,1}, .size = 4},
					{(int [4]){0,0,1,1}, .size = 4}
				},
				.size = 4
			},
			.expected = 2
		}
	};
	size_t inputs_size = (sizeof(cases) / sizeof(cases[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&cases[i]);
	return (EXIT_SUCCESS);
}
