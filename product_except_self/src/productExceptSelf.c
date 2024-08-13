/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   productExceptSelf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:23:59 by abelov            #+#    #+#             */
/*   Updated: 2024/08/13 13:24:00 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

/**
 * Given an integer array nums, return an array answer such that answer[i]
 * is equal to the product of all the elements of nums except nums[i].
 * Note: The returned array must be malloced, assume caller calls free().
 */
int	*productExceptSelf(const int *nums, int numsSize, int *returnSize)
{
	int	i;
	int	product2;
	int	*products;

	*returnSize = 0;
	products = (int *)malloc(sizeof(int) * numsSize);
	if (!products)
		return (NULL);
	*returnSize = numsSize;
	i = -1;
	int	product = 1;
	while (++i < numsSize)
	{
		products[i] = product;
		product *=  nums[i];
	}
	product2 = 1;
	while (numsSize--)
	{
		products[numsSize] *= product2;
		product2 *=  nums[numsSize];
	}
	return (products);
}
