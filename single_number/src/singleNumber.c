/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleNumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:00:05 by abelov            #+#    #+#             */
/*   Updated: 2024/12/19 17:00:05 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * 136. Single Number
 *
 * Given a non-empty array of integers nums, every element appears twice except
 * for one. Find that single one.
 */
int singleNumber(int *nums, int numsSize)
{
	int ans = 0;
	int i = -1;
	while (++i < numsSize)
		ans ^= nums[i];
	return ans;
}
