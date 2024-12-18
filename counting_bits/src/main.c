/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:39:27 by abelov            #+#    #+#             */
/*   Updated: 2024/09/27 19:39:27 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 338. Counting Bits
 *
 * Given an integer n, return an array ans of length n + 1 such that
 * for each i (0 <= i <= n), ans[i] is the number of 1's
 * in the binary representation of i.
 *
 * Constraints:
 * 	0 <= n <= 105
 */
int *countBits(int n, int *returnSize);

struct s_input
{
	int n;
	Array *expected;
};

int ft_do_test(struct s_input *input)
{
	Array result;
	int check_val;

	result.arr = countBits(input->n, &result.size);
	check_val = (input->expected->size == result.size);
	if (!check_val)
		printf("got arra of size [\"%d\"] whilst \"%d\" was to be expected\n",
			   result.size, input->expected->size);
	else
	{
		check_val = (arraycmp(&result, input->expected) == 0);
		if (!check_val)
		{
			check(check_val);
			printf("got ");
			ft_print_array(&result, " whilst ");
			ft_print_array(input->expected, "");
			printf(" was to be expected \n");
		}
		free(result.arr);
	}
	check(check_val);
	return (0);
}

int main(void)
{
	int i;
	struct s_input inputs[] = {
		{
			.n = 2,
			.expected = &(Array){ .arr = (int[3]){0,1,1}, .size = 3}
		},
		{
			.n = 5,
			.expected = &(Array){ .arr = (int[6]){0,1,1,2,1,2}, .size = 6}
		},
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
