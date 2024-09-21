/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPeakElement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:26:52 by abelov            #+#    #+#             */
/*   Updated: 2024/09/21 17:26:53 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * 162. Find Peak Element
 *
 * Given a 0-indexed integer array nums, find a peak element,
 * and return its index. If the array contains multiple peaks,
 * return the index to any of the peaks.
 */
int findPeakElement(const int *nums, int numsSize);

int findPeakElement(const int *nums, int numsSize)
{
	unsigned int mid;
	unsigned int left = 0;
	unsigned int right = numsSize - 1;

	if (numsSize == 1 || nums[0] > nums[1])
		return 0;

	if (nums[right] > nums[right - 1])
		return (int)right;

	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid] < nums[mid + 1])
			left = mid + 1;
		else
			right = mid;
	}
	return (int)left;
}
