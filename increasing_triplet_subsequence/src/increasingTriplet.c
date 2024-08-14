/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increasingTriplet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:41:09 by abelov            #+#    #+#             */
/*   Updated: 2024/08/14 10:41:10 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <limits.h>
#include <stdio.h>

/**
 * Given an integer array nums, return true if there exists a triple of indices
 * (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k].
 * If no such indices exists, return false.
 */
bool increasingTriplet(int* nums, int numsSize)
{
	bool 	result = false;
	int		idx;
	int 	i = INT_MAX;
	int 	j = INT_MAX;

	idx = -1;
	while (++idx < numsSize)
	{
//		fprintf(stdout, "i = %d, j = %d, curr = %d\n", i, j, nums[idx]);
//		fflush(stdout);
		if (nums[idx] < i)
			i = nums[idx];
		else if (nums[idx] < j && nums[idx] > i)
			j = nums[idx];
		else if (nums[idx] > j && nums[idx] > i)
		{
			result = true;
			break ;
		}
		else
			continue;
	}
	return (result);
}
