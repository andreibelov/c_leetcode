/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:23:47 by abelov            #+#    #+#             */
/*   Updated: 2024/08/27 01:38:55 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 605. Can Place Flowers
 */
bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n);

struct s_input
{
	int *flowerbed;
	int flowerbedSize;
	int n;
	int expected;
};

int ft_do_test(struct s_input *input)
{
	int result;
	int check_val;
	ft_print_int_tab(input->flowerbed, input->flowerbedSize, NULL);

	result = canPlaceFlowers(input->flowerbed, input->flowerbedSize, input->n);
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
	struct s_input inputs[] = {
		{
			.flowerbedSize = 5,
			.flowerbed = (int[]) {1, 0, 0, 0, 1},
			.n = 1,
			.expected = true
		},
		{
			.flowerbedSize = 5,
			.flowerbed = (int[]) {1, 0, 0, 0, 1},
			.n = 2,
			.expected = false
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
