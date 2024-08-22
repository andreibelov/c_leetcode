/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniqueOccurrences.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:40:35 by abelov            #+#    #+#             */
/*   Updated: 2024/08/22 12:40:36 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef enum bool {
	false = 0,
	true = 1
} bool;

/**
 * 1207. Unique Number of Occurrences
 *
 * Given an array of integers arr, return true if the number of
 * occurrences of each value in the array is unique or false otherwise.
 * Constraints:
 *     1 <= arr.length <= 1000
 *     -1000 <= arr[i] <= 1000
 */
bool	uniqueOccurrences(int *arr, int arrSize)
{
	int i;
	int *hashTable = (int *)alloca(2001 * sizeof(int));
	int *hashset = (int *)alloca(2001 * sizeof(int));
	int stack[1000] = {};
	int stackSize = 0;
	int *ptr;

	i = -1;
	while (++i < 2000)
	{
		hashTable[i] = 0;
		hashset[i] = 0;
	}
	i = -1;
	while (++i < arrSize)
		if (!hashTable[arr[i] + 1000]++) stack[stackSize++] = arr[i];
	i = -1;
	while (++i < stackSize)
	{
		ptr = &hashset[hashTable[stack[i] + 1000]];
		if (!*ptr) *ptr = 1;
		else return (false);
	}
	return (true);
}
