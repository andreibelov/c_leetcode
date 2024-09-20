/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:52:34 by abelov            #+#    #+#             */
/*   Updated: 2024/08/20 11:52:42 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

int pivotIndex(int *nums, int numsSize);

struct s_input
{
	int *nums;
	int numsSize;
	int expected;
};


int ft_do_test(struct s_input *input)
{
	int result;
	int check_val;
	ft_print_int_tab(input->nums, input->numsSize, NULL);

	result = pivotIndex(input->nums, input->numsSize);
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
			.numsSize = 0,
			.expected = -1,
			.nums = (int[]) {},
		},
		{
			.numsSize = 6,
			.nums = (int[6]) {1,7,3,6,5,6},
			.expected = 3
		},
		{
			.numsSize = 3,
			.nums = (int[3]) {1,2,3},
			.expected = -1
		},
		{
			.numsSize = 3,
			.nums = (int[3]) {2,1,-1},
			.expected = 0
		},
		{
			.numsSize = 6,
			.nums = (int[6]) {-1,-1,0,0,-1,-1},
			.expected = 2
		}
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
