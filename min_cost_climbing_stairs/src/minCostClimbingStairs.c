/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minCostClimbingStairs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:20:35 by abelov            #+#    #+#             */
/*   Updated: 2024/12/18 00:20:36 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <alloca.h>

#define min(a, b) (a < b ? a : b)

/**
 * 746. Min Cost Climbing Stairs
 *
 * You are given an integer array cost where cost[i] is the cost of ith step on
 * a staircase. Once you pay the cost, you can either climb one or two steps.
 *
 * You can either start from the step with index 0, or the step with index 1.
 *
 * Return the minimum cost to reach the top of the floor.
 */
int minCostClimbingStairs(int* cost, int costSize)
{
	int i;
	int ans;
	int *dp = (int *)alloca(costSize * sizeof(int));

	dp[0] = cost[0];
	dp[1] = cost[1];

	i = 1;
	while(++i < costSize)
		dp[i] = min(dp[i-1], dp[i-2]) + cost[i];

	ans = min(dp[costSize-1], dp[costSize-2]);
	return ans;
}
