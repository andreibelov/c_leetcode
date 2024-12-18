/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tribonacci.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:40:55 by abelov            #+#    #+#             */
/*   Updated: 2024/09/26 00:40:56 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <alloca.h>

/**
 * 1137. N-th Tribonacci Number
 */
int tribonacci(int n)
{
	int i;
	int *dp = (int *) alloca((n + 1) * sizeof(int));

	if (n < 3)
		return (n != 0);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	i = 2;
	while (++i <= n)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	return dp[n];
}
