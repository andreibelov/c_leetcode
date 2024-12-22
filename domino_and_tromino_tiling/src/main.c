/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:38:00 by abelov            #+#    #+#             */
/*   Updated: 2024/12/22 16:38:01 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 790. Domino and Tromino Tiling
 *
 * Given an integer n, return the number of ways to tile an 2 x n board.
 * Since the answer may be very large, return it modulo 109 + 7.
 *
 * Constraints:
 * 	1 <= n <= 1000
 */
int numTilings(int n);

struct s_input
{
	int boeardSize;
	int expected;
};

int ft_do_test(struct s_input *input)
{
	int	check_val;
	int	result;

	result = numTilings(input->boeardSize);
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
			.boeardSize = 3,
			.expected = 5
		},
		{
			.boeardSize = 1,
			.expected = 1
		},
		{
			.boeardSize = 4,
			.expected = 11
		},
		{
			.boeardSize = 30,
			.expected = 312342182
		},
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}


