/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:42:24 by abelov            #+#    #+#             */
/*   Updated: 2025/01/09 22:42:25 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 714. Best Time to Buy and Sell Stock with Transaction Fee
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the ith day, and an integer fee representing a transaction fee.
 *
 * Find the maximum profit you can achieve.
 * You may complete as many transactions as you like, but you need to pay the
 * transaction fee for each transaction.
 *
 * Note:
 *  You may not engage in multiple transactions simultaneously.
 *  The transaction fee is only charged once for each stock purchase and sale.
 */
int maxProfit(int *prices, int pricesSize, int fee);

typedef struct s_input
{
	Array	*prices;
	int		fee;
	int		expected;
} Input;

int ft_do_test(Input *input)
{
	int	check_val;
	int	result;
	ft_print_array(input->prices, NULL);

	result = maxProfit(input->prices->arr, input->prices->size, input->fee);
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
	Input	inputs[] = {
		{
			.prices = &(Array){ .arr = (int[6]){1,3,2,8,4,9}, .size = 6},
			.fee = 2,
			.expected = 8
		},
		{
			.prices = &(Array){ .arr = (int[6]){1,3,7,5,10,3}, .size = 6},
			.fee = 3,
			.expected = 6
		},
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
