/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxProfit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:43:56 by abelov            #+#    #+#             */
/*   Updated: 2025/01/09 22:43:57 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#ifdef DYN_PROG

#include <alloca.h>
#include <string.h>

int maxProfit(int *prices, int pricesSize, int fee)
{

#ifdef USE_STRUCTS
	struct Profit{ int cash, hold; } *profits = alloca(pricesSize * sizeof(struct Profit));
	//	((struct Profit{ int cash, hold; } *)profits)[0] = (struct Profit){.cash = 0, .hold = -prices[0]};
#else
	/* f0: The maximum profit we can have up to the current day if we cash. */
	/* f1: The maximum profit we can have if we do hold stock */
	int (*profits)[2] = (int (*)[2]) alloca(pricesSize * sizeof(int[2]));
#endif


#ifdef USE_STRUCTS
	profits[0] = (struct Profit){.cash = 0, .hold = -prices[0]};
#else
	profits[0][0] = 0;
	profits[0][1] = -1 * prices[0];
#endif

	auto int max(int X, int Y);
	int max(int X, int Y) { return ((X) > (Y)) ? (X) : (Y); }

	int i = 0;
	while (++i < pricesSize)
	{
#ifdef USE_STRUCTS
		struct Profit *curr = &profits[i];
		struct Profit *prev = &profits[i - 1];
		curr->cash = max(prev->cash, prev->hold + prices[i] - fee);
		curr->hold = max(prev->hold, prev->cash - prices[i]);
#else
		profits[i][0] = max(profits[i - 1][0], profits[i - 1][1] + prices[i] - fee);
		profits[i][1] = max(profits[i - 1][1], profits[i - 1][0] - prices[i]);
#endif
	}
	return (((int (*)[2])profits)[i - 1][0]);
}

#else

int maxProfit(int *prices, int pricesSize, int fee)
{
	if (pricesSize == 0) return 0;

	int hold = -prices[0];
	int cash = 0;
	int i = 0;
	while (++i < pricesSize)
	{
		cash = cash > (hold + prices[i] - fee) ? cash : (hold + prices[i] - fee);
		hold = hold > (cash - prices[i]) ? hold : (cash - prices[i]);
	}
	return cash;
}

#endif
