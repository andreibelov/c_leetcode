/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:26:05 by abelov            #+#    #+#             */
/*   Updated: 2024/09/21 17:26:06 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 162. Find Peak Element
 *
 * Constraints:
 * 	1 <= nums.length <= 10^3
 * 	-2^31 <= nums[i] <= 2^31 - 1
 * 	nums[i] != nums[i + 1] for all valid i.
 */
int findPeakElement(int *nums, int numsSize);

struct s_test_case
{
	Array	nums;
	int expected;
};

int ft_do_test(struct s_test_case *input)
{
	int result;
	int check_val;
	ft_print_int_tab(input->nums.arr, input->nums.size, NULL);

	result = findPeakElement(input->nums.arr, input->nums.size);
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
			.nums = {(int[4]) {1,2,3,1}, .size = 4},
			.expected = 2
		},
		{
			.nums = {(int[7]) {1,2,1,3,5,6,4}, .size = 7},
			.expected = 5
		}
	};
	size_t inputs_size = (sizeof(cases) / sizeof(cases[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&cases[i]);
	return (EXIT_SUCCESS);
}
