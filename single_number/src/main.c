/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:58:26 by abelov            #+#    #+#             */
/*   Updated: 2024/12/19 16:58:26 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 136. Single Number
 *
 * Given a non-empty array of integers nums, every element appears twice except
 * for one. Find that single one.
 */
int singleNumber(int *nums, int numsSize);

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

	result = singleNumber(input->cost->arr, input->cost->size);
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
			.cost = &(Array){ .arr = (int[]){2,3,1}, .size = 3},
			.expected = 1
		},
		{
			.cost = &(Array){ .arr = (int[]){4,1,2,1,2}, .size = 5},
			.expected = 4
		},
		{
			.cost = &(Array){ .arr = (int[]){1}, .size = 1},
			.expected = 1
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}


