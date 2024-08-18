/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findMaxAverage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:32:02 by abelov            #+#    #+#             */
/*   Updated: 2024/08/18 11:32:02 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

double findMaxAverage(int *nums, int numsSize, int k)
{
	double	max = INT_MIN;
	double	curr_avg = 0;
	double	acc = 0;
	int	left_idx = 0;
	int	right_idx = k;
	int i = -1;

	while (++i < k)
		acc += nums[i];
	max = acc / k;
	while (right_idx < numsSize)
	{
		acc -= nums[left_idx++];
		acc += nums[right_idx++];
		curr_avg = acc / k;
		if (curr_avg > max) max = curr_avg;
	}
	return (max);
}

