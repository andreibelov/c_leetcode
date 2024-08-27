/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:39:03 by abelov            #+#    #+#             */
/*   Updated: 2024/08/27 01:42:25 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

int longestOnes(int *nums, int numsSize, int k);

struct s_input
{
	int k;
	int *nums;
	int numsSize;
	int expected;
};

int ft_do_test(struct s_input *input)
{
	int result;
	int check_val;
	ft_print_int_tab(input->nums, input->numsSize, NULL);

	result = longestOnes(input->nums, input->numsSize, input->k);
	check_val = (input->expected == result);
	if (!check_val)
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   result, input->expected);
	check(check_val);
	return (0);
}

int main(void)
{
	int				i;
	struct s_input	inputs[] = {
		{
			.k = 1,
			.numsSize = 0,
			.expected = 0,
			.nums = (int[]) {},
		},
		{
			.k = 2,
			.numsSize = 11,
			.nums = (int[11]) {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0},
			.expected = 6
		},
		{
			.k = 3,
			.numsSize = 19,
			.nums = (int[19]) {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1},
			.expected = 10
		},
		{
			.k = 1,
			.numsSize = 4,
			.nums = (int[4]) {1, 1, 0, 1},
			.expected = 4
		},
		{
			.k = 1,
			.numsSize = 4,
			.nums = (int[4]) {1, 1, 1, 1},
			.expected = 4
		},
		{
			.k = 0,
			.numsSize = 1,
			.nums = (int[1]) {0},
			.expected = 0
		},
		{
			.k = 1,
			.numsSize = 1,
			.nums = (int[1]) {0},
			.expected = 1
		}
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int)inputs_size)
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
