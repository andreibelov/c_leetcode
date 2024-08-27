/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:23:25 by abelov            #+#    #+#             */
/*   Updated: 2024/08/26 23:51:25 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

void moveZeroes(int *nums, int numsSize);

struct s_input
{
	int *nums;
	int numsSize;
	int *expected;
};

int ft_do_test(struct s_input	*input)
{
	int				check_val;
	ft_print_int_tab(input->nums, input->numsSize, NULL);

	moveZeroes(input->nums, input->numsSize);
	check_val = memcmp(input->nums, input->expected, (sizeof(int) * input->numsSize));
	if (check_val)
	{
		printf("got ");
		ft_print_int_tab(input->nums, input->numsSize, " whilst ");
		ft_print_int_tab(input->expected, input->numsSize, "");
		printf(" was to be expected \n");
	}
	check(!check_val);
	return (0);
}

int main(void)
{
	int				i;
	struct s_input	inputs[] = {
		{
			.nums = (int[]) {0,1,0,3,12},
			.numsSize = 5,
			.expected = (int[]) {1,3,12,0,0}
		},
		{
			.numsSize = 1,
			.nums = (int[]) {0},
			.expected = (int[]) {0}
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
