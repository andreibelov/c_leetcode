/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:04:02 by abelov            #+#    #+#             */
/*   Updated: 2024/12/20 21:04:03 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 198. House Robber
 *
 * Given an integer array nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight
 * without alerting the police.
 *
 * Constraints:
 * 	1 <= nums.length <= 100
 * 	0 <= nums[i] <= 400
 */
int rob(int *nums, int numsSize);

struct s_input
{
	Array *nums;
	int expected;
};

int ft_do_test(struct s_input *input)
{
	int	check_val;
	int	result;
	ft_print_array(input->nums, NULL);

	result = rob(input->nums->arr, input->nums->size);
	check_val = (result == input->expected);
	check(check_val);
	if (!check_val)
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   result, input->expected);
	return (0);
}

int main(void)
{
	int				i;
	struct s_input	inputs[] = {
		{
			.nums = &(Array){ .arr = (int[]){1,2}, .size = 2},
			.expected = 2
		},{
			.nums = &(Array){ .arr = (int[]){1,2,3,1}, .size = 4},
			.expected = 4
		},
		{
			.nums = &(Array){ .arr = (int[]){2,7,9,3,1}, .size = 5},
			.expected = 12
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}

