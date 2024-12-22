/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rob.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:04:19 by abelov            #+#    #+#             */
/*   Updated: 2024/12/20 21:04:20 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static inline int MAX(int X, int Y)
{ return ((X) > (Y)) ? (X) : (Y); }

/**
 * 198. House Robber
 *
 * You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed, the only constraint
 * stopping you from robbing each of them is that adjacent houses have security
 * systems connected and it will automatically contact the police if two
 * adjacent houses were broken into on the same night.
 */
int rob(int *nums, int numsSize)
{
	int i;
	int f = 0, g = 0, tmp;

	i = -1;
	while(++i < numsSize)
	{
		tmp = MAX(f, g);
		g = f + nums[i];
		f = tmp;
	}

	return (MAX(f, g));
}
