/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxOperations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:50:38 by abelov            #+#    #+#             */
/*   Updated: 2024/08/17 21:50:40 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int intcmp(const int *a, const int *b)
{
	return (*a > *b) - (*a < *b);
}

int maxOperations(int *nums, int numsSize, int k)
{
	int answer = 0;
	int sum;
	int left_idx = 0;
	int right_idx = numsSize - 1;

	qsort(nums, numsSize, sizeof(int), (__compar_fn_t) intcmp);
	while (left_idx < right_idx)
	{
		sum = nums[left_idx] + nums[right_idx];
		if (sum > k)
			right_idx--;
		else if (sum < k)
			left_idx++;
		else
		{
			left_idx++;
			right_idx--;
			answer++;
		}

	}
	return (answer);
}
