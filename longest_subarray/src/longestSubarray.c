/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longestSubarray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:14:14 by abelov            #+#    #+#             */
/*   Updated: 2024/08/19 19:14:14 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * 1493. Longest Subarray of 1's After Deleting One Element
 */
#ifndef FIRST
#include <alloca.h>
#include <string.h>

int longestSubarray(const int *nums, int numsSize)
{
	int	i = 0;
	int max = 0;
	int curr;
	size_t	size = numsSize * sizeof(int);
	int	*left = alloca(size);
	int *right = alloca(size);

	memset(left, 0, size);
	memset(right, 0, size);
	while (++i < numsSize)
		if (nums[i - 1] == 1)
			left[i] = left[i - 1] + 1;
	i = numsSize - 1;
	while (--i >= 0)
		if (nums[i + 1] == 1)
			right[i] = right[i + 1] + 1;
	i = -1;
	while (++i < numsSize)
	{
		curr = left[i] + right[i];
		if (curr > max) max = curr;
	}
	return (max);
}
#else
int longestSubarray(const int *nums, int numsSize)
{
	int tail = 0, head = -1;
	int max = 0, curr, k = 0;

	while (++head < numsSize)
	{
		if (nums[head] == 0) k++;
		while (k > 1)
			if (nums[tail++] == 0) k--;
		curr = (head - tail);
		if (curr > max) max = curr;
	}
	return (max);
}
#endif
