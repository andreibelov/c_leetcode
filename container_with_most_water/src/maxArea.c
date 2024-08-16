/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxArea.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:13:12 by abelov            #+#    #+#             */
/*   Updated: 2024/08/16 14:13:13 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int maxArea(int *height, int heightSize)
{
	unsigned int capacity = 0;
	unsigned int tmp;
	unsigned int left;
	unsigned int left_idx = 0;
	unsigned int right;
	unsigned int right_idx = heightSize - 1;

	while (left_idx < right_idx)
	{
		left = height[left_idx];
		right = height[right_idx];
		if (left < right)
			tmp = left * (right_idx - left_idx++);
		else
			tmp = right * (right_idx-- - left_idx);
		if (tmp > capacity) capacity = tmp;
	}
	return ((int)capacity);
}
