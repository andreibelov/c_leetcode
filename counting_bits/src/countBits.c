/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countBits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:39:43 by abelov            #+#    #+#             */
/*   Updated: 2024/09/27 19:39:44 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * 338. Counting Bits
 *
 * Given an integer n, return an array ans of length n + 1 such that
 * for each i (0 <= i <= n), ans[i] is the number of 1's
 * in the binary representation of i.
 *
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countBits(int n, int *returnSize)
{
	int i;
	int idx;
	int *ans = calloc(++n, sizeof(int));
	*returnSize = n;

	i = 0;
	while (++i < n)
	{
		idx = i >> 1;
		ans[i] = ans[idx] + (i & 1);
	}
	return ans;
}
