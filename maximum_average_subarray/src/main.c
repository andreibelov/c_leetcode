/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:31:16 by abelov            #+#    #+#             */
/*   Updated: 2024/08/18 11:31:17 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

struct s_input
{
	int *nums;
	int numsSize;
	int k;
	double expected;
};

double findMaxAverage(int *nums, int numsSize, int k);

int ft_do_test(struct s_input *input)
{
	double result;
	int check_val;
	ft_print_int_tab(input->nums, input->numsSize, NULL);

	result = findMaxAverage(input->nums, input->numsSize, input->k);
	check_val = (input->expected == result);
	if (!check_val)
		printf("got \"%f\" whilst \"%f\" was to be expected\n",
			   result, input->expected);
	check(check_val);
	return (0);
}


int main(void)
{
	int i;
	struct s_input inputs[] = {
		{
			.k = 4,
			.nums = (int[]) {1, 12, -5, -6, 50, 3},
			.numsSize = 6,
			.expected = 12.75
		},
		{
			.k = 1,
			.numsSize = 1,
			.nums = (int[]) {5},
			.expected = 5.0
		},
		{
			.k = 1,
			.numsSize = 1,
			.nums = (int[]) {-1},
			.expected = -1
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}


