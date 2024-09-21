/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:58:57 by abelov            #+#    #+#             */
/*   Updated: 2024/09/21 00:58:57 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 215. Kth Largest Element in an Array
 *
 * Constraints:
 * 	1 <= k <= nums.length <= 10^5
 * 	-10^4 <= nums[i] <= 10^4
 */
int findKthLargest(int* nums, int numsSize, int k);

struct s_test_case
{
	Array	nums;
	int k;
	int expected;
};

int ft_do_test(struct s_test_case *input)
{
	int result;
	int check_val;
	ft_print_int_tab(input->nums.arr, input->nums.size, NULL);

	result = findKthLargest(input->nums.arr, input->nums.size, input->k);
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
			.nums = {(int[6]) {3,2,1,5,6,4}, .size = 6},
			.k = 2,
			.expected = 5
		},
		{
			.nums = {(int[9]) {3,2,3,1,2,4,5,5,6}, .size = 9},
			.k = 4,
			.expected = 4
		}
	};
	size_t inputs_size = (sizeof(cases) / sizeof(cases[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&cases[i]);
	return (EXIT_SUCCESS);
}
