/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canPlaceFlowers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:23:35 by abelov            #+#    #+#             */
/*   Updated: 2024/08/11 16:23:36 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	canPlaceFlowers(int *flowerbed, const int flowerbedSize, int n)
{
	int	i;
	int	count = 0;

	i = -1;
	while(++i < flowerbedSize)
	{
		if (!flowerbed[i])
		{
			if((!i || !flowerbed[i - 1]) && (i + 1 == flowerbedSize || !flowerbed[i + 1]))
			{
				flowerbed[i] = 1;
				if (++count >= n) break ;
			}
		}
	}
	return (count >= n);
}
