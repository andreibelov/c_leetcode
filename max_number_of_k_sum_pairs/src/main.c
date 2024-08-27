/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:50:23 by abelov            #+#    #+#             */
/*   Updated: 2024/08/27 01:42:59 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

struct s_input
{
	int *nums;
	int numsSize;
	int k;
	int expected;
};

int maxOperations(int *nums, int numsSize, int k);

int ft_do_test(struct s_input *input)
{
	int result;
	int check_val;
	ft_print_int_tab(input->nums, input->numsSize, NULL);

	result = maxOperations(input->nums, input->numsSize, input->k);
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
			.k = 5,
			.nums = (int[]) {1, 2, 3, 4},
			.numsSize = 4,
			.expected = 2
		},
		{
			.k = 6,
			.numsSize = 5,
			.nums = (int[]) {3, 1, 3, 4, 3},
			.expected = 1
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
