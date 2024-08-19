/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longestOnes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:40:07 by abelov            #+#    #+#             */
/*   Updated: 2024/08/19 13:40:07 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * 1004. Max Consecutive Ones III
 * Given a binary array nums and an integer k, return the maximum number
 * of consecutive 1's in the array if you can flip at most k 0's.
 */
#ifdef FIRST
int longestOnesFirst(const int *const nums, const int numsSize, int k)
{
	int curr;
	int max = 0;
	int left_idx = -1;
	int right_idx = -1;

	while (right_idx < numsSize - 1)
	{
		if (nums[++right_idx] == 0) k--;
		while (k < 0)
			if (nums[++left_idx] == 0) k++;
		curr = right_idx - left_idx;
		if (curr > max) max = curr;
	}

	return (max);
}
#else
int longestOnes(const int *const nums, const int numsSize, int k)
{
	int left_idx = 0;
	int right_idx = 0;

	while (right_idx < numsSize && k > 0)
		if (nums[right_idx++] == 0) k--;
	while (right_idx < numsSize)
	{
		if (nums[right_idx++] == 0) k--;
		if (k < 0)
			if (nums[left_idx++] == 0) k++;
	}
	return (right_idx - left_idx);
}
#endif