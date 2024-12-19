/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:07:53 by abelov            #+#    #+#             */
/*   Updated: 2024/12/19 17:07:54 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 1318. Minimum Flips to Make a OR b Equal to c
 *
 * Constraints:
 * 	1 <= a <= 10^9
 * 	1 <= b <= 10^9
 * 	1 <= c <= 10^9
 */
int minFlips(int a, int b, int c);

struct s_input
{
	Array *arr;
	int expected;
};

int ft_do_test(struct s_input *input)
{
	int	check_val;
	int	result;

	Array *a = input->arr;

	ft_print_array(a, NULL);

	result = minFlips(a->arr[0], a->arr[1], a->arr[2]);
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
			.arr = &(Array){ .arr = (int[]){2,6,5}, .size = 3},
			.expected = 3
		},
		{
			.arr = &(Array){ .arr = (int[]){4,2,7}, .size = 3},
			.expected = 1
		},
		{
			.arr = &(Array){ .arr = (int[]){1,2,3}, .size = 3},
			.expected = 0
		},
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
