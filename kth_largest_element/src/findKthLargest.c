/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findKthLargest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 01:05:58 by abelov            #+#    #+#             */
/*   Updated: 2024/09/21 01:05:59 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * 215. Kth Largest Element in an Array
 * Given an integer array nums and an integer k,
 * return the kth largest element in the array.
 */
int findKthLargest(int *nums, int numsSize, int k);

#include <stdlib.h>

static int compare_int(const void *p1, const void *p2)
{
	int a = *(const int *) p1;
	int b = *(const int *) p2;
	return (a > b) - (a < b);
}

int findKthLargest(int *nums, int numsSize, int k)
{
	qsort(nums, numsSize, sizeof(int), compare_int);
	return nums[numsSize - k];
}
