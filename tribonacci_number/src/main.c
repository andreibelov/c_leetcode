/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:40:44 by abelov            #+#    #+#             */
/*   Updated: 2024/09/26 00:40:44 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 1137. N-th Tribonacci Number
 *
 * Constraints:
 * 	0 <= n <= 37
 * 	The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
 */
int tribonacci(int n);

struct s_input
{
	int n;
	int expected;
};

int ft_do_test(struct s_input *input)
{
	int result;
	int check_val;

	result = tribonacci(input->n);
	check_val = (input->expected == result);
	if (!check_val)
		printf("got [\"%d\"] whilst \"%d\" was to be expected\n",
			   result, input->expected);
	check(check_val);
	return (0);
}

int main(void)
{
	int i;
	struct s_input inputs[] = {
		{
			.n = 4,
			.expected = 4
		},
		{
			.n = 25,
			.expected = 1389537
		},
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}

