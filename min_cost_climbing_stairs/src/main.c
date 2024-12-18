/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:17:43 by abelov            #+#    #+#             */
/*   Updated: 2024/12/18 00:17:43 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 746. Min Cost Climbing Stairs
 *
 * Return the minimum cost to reach the top of the floor.
 *
 * Constraints:
 * 	2 <= cost.length <= 1000
 * 	0 <= cost[i] <= 999
 */
int minCostClimbingStairs(int* cost, int costSize);

struct s_input
{
	Array *cost;
	int expected;
};


int ft_do_test(struct s_input *input)
{
	int	check_val;
	int	result;
	ft_print_array(input->cost, NULL);

	result = minCostClimbingStairs(input->cost->arr, input->cost->size);
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
			.cost = &(Array){ .arr = (int[]){10,15,20}, .size = 3},
			.expected = 15
		},
		{
			.cost = &(Array){ .arr = (int[]){1,100,1,1,1,100,1,1,100,1}, .size = 10},
			.expected = 6
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
