/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increasingTriplet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:41:09 by abelov            #+#    #+#             */
/*   Updated: 2024/08/26 23:50:32 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <limits.h>
#include <stdio.h>

/**
 * 334. Increasing Triplet Subsequence
 *
 * Given an integer array nums, return true if there exists a triple of indices
 * (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k].
 * If no such indices exists, return false.
 *
 * Constraints:
 *	1 <= nums.length <= 5 * 105
 *	-231 <= nums[i] <= 231 - 1
 */
bool increasingTriplet(int* nums, int numsSize)
{
	bool 	result = false;
	int		idx;
	int		curr;
	int 	i = INT_MAX;
	int 	j = INT_MAX;

	idx = -1;
	while (++idx < numsSize)
	{
		fprintf(stdout, "i = %d, j = %d, curr = %d\n", i, j, nums[idx]);
		fflush(stdout);
		curr = nums[idx];
		if (curr <= i) i = curr;
		else if (curr <= j) j = curr;
		else
		{
			result = true;
			break ;
		}
	}
	return (result);
}
