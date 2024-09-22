/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:46:17 by abelov            #+#    #+#             */
/*   Updated: 2024/09/22 21:46:18 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 875. Koko Eating Bananas
 *
 * Constraints:
 * 	1 <= piles.length <= 10^4
 * 	piles.length <= h <= 10^9
 * 	1 <= piles[i] <= 10^9
 */
int minEatingSpeed(int *piles, int pilesSize, int h);

struct s_test_case
{
	int h;
	Array	piles;
	int expected;
};

int ft_do_test(struct s_test_case *input)
{
	int result;
	int check_val;
	ft_print_int_tab(input->piles.arr, input->piles.size, NULL);

	result = minEatingSpeed(input->piles.arr, input->piles.size, input->h);
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
			.h = 8,
			.piles = {(int[4]) {3,6,7,11}, .size = 4},
			.expected = 4
		},
		{
			.h = 5,
			.piles = {(int[5]) {30,11,23,4,20}, .size = 5},
			.expected = 30
		},
		{
			.h = 6,
			.piles = {(int[5]) {30,11,23,4,20}, .size = 5},
			.expected = 23
		},
		{
			.h = 1000000000,
			.piles = {(int[3]) {805306368,805306368,805306368}, .size = 3},
			.expected = 3
		}
	};
	size_t inputs_size = (sizeof(cases) / sizeof(cases[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&cases[i]);
	return (EXIT_SUCCESS);
}
