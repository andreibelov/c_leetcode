/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canPlaceFlowers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:23:35 by abelov            #+#    #+#             */
/*   Updated: 2024/08/27 01:38:52 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

/**
 * 605. Can Place Flowers
 *
 * You have a long flowerbed in which some of the plots are planted,
 * and some are not. However, flowers cannot be planted in adjacent plots.
 *
 * Given an integer array flowerbed containing 0's and 1's,
 * where 0 means empty and 1 means not empty, and an integer n,
 * return true if n new flowers can be planted in the flowerbed without
 * violating the no-adjacent-flowers rule and false otherwise.
 *
 * Constraints:
 *	1 <= flowerbed.length <= 2 * 104
 *	flowerbed[i] is 0 or 1.
 *	There are no two adjacent flowers in flowerbed.
 *	0 <= n <= flowerbed.length
 */
bool	canPlaceFlowers(int *flowerbed, int flowerbedSize, int n);

bool	canPlaceFlowers(int *flowerbed, const int flowerbedSize, int n)
{
	int	i;
	int	count = 0;

	i = -1;
	while(++i < flowerbedSize)
	{
		if (!flowerbed[i]
			&& (!i || !flowerbed[i - 1])
			&& (i + 1 == flowerbedSize || !flowerbed[i + 1]))
		{
			flowerbed[i] = 1;
			if (++count >= n) break ;
		}
	}
	return (count >= n);
}
