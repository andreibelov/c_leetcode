/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kids_with_candies.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:29:32 by abelov            #+#    #+#             */
/*   Updated: 2024/08/09 14:29:33 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <malloc.h>


int get_max(int a, int b)
{
	return a > b ? a : b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool	*kidsWithCandies(int *candies, int candiesSize, int extraCandies, int *returnSize)
{
	bool *result;
	int maxCandies;

	maxCandies = -1;
	*returnSize = candiesSize;
	while (candiesSize--)
		maxCandies = get_max(maxCandies, candies[candiesSize]);
	candiesSize = *returnSize;
	result = (bool *)malloc(sizeof(int) * candiesSize);
	if (!result)
		return (*returnSize = 0, NULL);
	while (candiesSize--)
		result[candiesSize] = candies[candiesSize] + extraCandies >= maxCandies;
	return (result);
}
