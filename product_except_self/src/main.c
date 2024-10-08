/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:27:43 by abelov            #+#    #+#             */
/*   Updated: 2024/08/27 01:47:06 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

int	*productExceptSelf(const int *nums, int numsSize, int *returnSize);

struct s_input
{
	int *nums;
	int numsSize;
	int returnSize;
	int *expected;
};

int ft_do_test(struct s_input	*input)
{
	int				*result;
	int				check_val;
	ft_print_int_tab(input->nums, input->numsSize, NULL);

	result = productExceptSelf(input->nums,
							   input->numsSize,
							   &input->returnSize);
	if (input->returnSize == input->numsSize)
	{
		check_val = memcmp(result, input->expected, (sizeof(int) * input->returnSize));
		if (check_val)
		{
			printf("got ");
			ft_print_int_tab(result, input->returnSize, " vs expected ");
			ft_print_int_tab(input->expected, input->numsSize, NULL);
		}
		check(!check_val);
	}
	else
		check(false);
	free(result);
	return (0);
}

int main(void)
{
	int				i;
	struct s_input	inputs[] = {
		{
			.nums = (int[]) {1, 2, 3, 4},
			.numsSize = 4,
			.expected = (int[]) {24, 12, 8, 6}
		},
		{
			.numsSize = 5,
			.nums = (int[]) {-1, 1, 0, -3, 3},
			.expected = (int[]) {0, 0, 9, 0, 0}
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
