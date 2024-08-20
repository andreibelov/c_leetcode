/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivotIndex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:53:00 by abelov            #+#    #+#             */
/*   Updated: 2024/08/20 11:53:01 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <alloca.h>
#include <malloc.h>

#ifdef FIRST
int pivotIndex(const int *nums, int numsSize)
{
	int	*left = __builtin_alloca((numsSize + 1) * sizeof(int));
	int	*right = __builtin_alloca((numsSize + 1) * sizeof(int));
	int i;
	int pivot = -1;

	if (!nums)
		return (0);
	*left = 0;
	right[numsSize] = 0;
	i = 0;
	while (++i <= numsSize)
		left[i] = left[i - 1] + nums[i - 1];
	i = numsSize;
	while (--i >= 0)
		right[i] = right[i + 1] + nums[i];
	i = -1;
	while (++i < numsSize)
		if (left[i + 1] == right[i])
		{
			pivot = i;
			break ;
		}
	return (pivot);
}
#else
int pivotIndex(const int *nums, int numsSize)
{
	int i;
	int pivot = -1;
	const int *const onums = nums;
	int total_sum = 0;
	int	*const oleft = malloc(numsSize * sizeof(int));
	int	*const oright = malloc(numsSize * sizeof(int));
	int *left = oleft;
	int *right = oright;

	i = -1;
	while (++i < numsSize)
	{
		*left++ = total_sum;
		total_sum += *nums++;
	}
	nums = onums;
	left = oleft;
	i = -1;
	while (++i < numsSize)
		*right++ = total_sum - *left++ - *nums++;
	i = -1;
	left = oleft;
	right = oright;
	while (++i < numsSize)
		if (*left++ == *right++)
		{
			pivot = i;
			break;
		}
	return (free(oleft), free(oright), pivot);
}
#endif