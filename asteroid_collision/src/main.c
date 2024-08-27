/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:51:38 by abelov            #+#    #+#             */
/*   Updated: 2024/08/26 21:51:46 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 735. Asteroid Collision
 */
int *asteroidCollision(int *asteroids, int asteroidsSize, int *returnSize);

struct s_input
{
	int *asteroids;
	int asteroidsSize;
	int *expected;
	int expectedSize;
};

int ft_do_test(struct s_input	*input)
{
	int	check_val;
	int	resultSize;
	int	*result;
	ft_print_int_tab(input->asteroids, input->asteroidsSize, NULL);

	result = asteroidCollision(input->asteroids, input->asteroidsSize, &resultSize);
	if (input->expectedSize != resultSize)
	{
		printf("resultSize doesn't match expected value\n");
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   resultSize, input->expectedSize);
		check(false);
	}
	else
	{
		check_val = !memcmp(input->expected, result, input->expectedSize * sizeof(int));
		if (!check_val)
		{
			printf("got ");
			ft_print_int_tab(result, resultSize, " whilst ");
			ft_print_int_tab(input->expected, input->expectedSize, "");
			printf(" was to be expected \n");
		}
		check(check_val);
	}
	free(result);
	return (0);
}

int main(void)
{
	int				i;
	struct s_input	inputs[] = {
		{
			.asteroids = (int[]) {5,10,-5},
			.asteroidsSize = 3,
			.expected = (int[]) {5,10},
			.expectedSize = 2,
		},
		{
			.asteroids = (int[]) {8,-8},
			.asteroidsSize = 2,
			.expected = (int[1]) {},
			.expectedSize = 0,
		},
		{
			.asteroids = (int[]) {10,2,-5},
			.asteroidsSize = 3,
			.expected = (int[1]) {10},
			.expectedSize = 1,
		},
		{
			.asteroids = (int[]) {-2,-1,1,2},
			.asteroidsSize = 4,
			.expected = (int[]) {-2,-1,1,2},
			.expectedSize = 4,
		},
		{
			.asteroids = (int[]) {-2,-2,-2,1},
			.asteroidsSize = 4,
			.expected = (int[]) {-2,-2,-2,1},
			.expectedSize = 4,
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
