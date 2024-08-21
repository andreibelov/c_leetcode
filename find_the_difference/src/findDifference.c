/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findDifference.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:54:06 by abelov            #+#    #+#             */
/*   Updated: 2024/08/21 10:54:06 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#ifndef HASMAP
int get_unique(const int *nums1, int nums1Size, int *set1)
{
	int set1Size = 0;

	int i = -1, j;
	while (++i < nums1Size)
	{
		int curr = nums1[i];
		j = -1;
		int found = 0;
		while (++j < set1Size)
		{
			if (curr == set1[j])
			{
				found = 1;
				break;
			}
		}
		if (!found) set1[set1Size++] = curr;
	}
	return set1Size;
}

int getUniqueSet(int set1Size, int set2Size, const int *set1, const int *set2, int *res1)
{
	int res1Size = 0;
	int i = -1;
	while (++i < set1Size)
	{
		int curr = set1[i];
		int j = -1;
		int found = 0;
		while (++j < set2Size)
		{
			if (curr == set2[j])
			{
				found = 1;
				break;
			}
		}
		if (!found) res1[res1Size++] = curr;
	}
	return res1Size;
}

/**
 * 2215. Find the Difference of Two Arrays
 *
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced,
 * assume caller calls free().
 */
int **findDifference(const int *nums1, int nums1Size,
					 const int *nums2, int nums2Size,
					 int *returnSize, int **returnColumnSizes)
{
	int **res;
	int *set1 = (int *) alloca(nums1Size * sizeof(int));
	int *set2 = (int *) alloca(nums2Size * sizeof(int));
	int set1Size = get_unique(nums1, nums1Size, set1);
	int set2Size = get_unique(nums2, nums2Size, set2);

	*returnSize = 2;
	res = (int **) malloc(*returnSize * sizeof(int *));
	res[0] = (int *) malloc(nums1Size * sizeof(int));
	res[1] = (int *) malloc(nums2Size * sizeof(int));

	*returnColumnSizes = (int *) malloc(*returnSize * sizeof(int));
	(*returnColumnSizes)[0] = getUniqueSet(set1Size, set2Size, set1, set2, res[0]);
	(*returnColumnSizes)[1] = getUniqueSet(set2Size, set1Size, set2, set1, res[1]);

	return (res);
}
#else
#endif
