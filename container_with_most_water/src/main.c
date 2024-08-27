/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:13:16 by abelov            #+#    #+#             */
/*   Updated: 2024/08/27 01:38:02 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

int maxArea(int *height, int heightSize);

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

	result = maxArea(input->nums,
					 input->numsSize);
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
			.numsSize = 9,
			.nums = (int[9]) {1, 8, 6,  2, 5, 4,  8, 3, 7},
			.expected = 49
		},
		{
			.numsSize = 2,
			.nums = (int[2]) {1, 1},
			.expected = 1
		},
		{
			.numsSize = 3,
			.nums = (int[3]) {1,2,1},
			.expected = 2
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
