/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   successfulPairs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:46:02 by abelov            #+#    #+#             */
/*   Updated: 2024/09/20 22:46:03 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * 2300. Successful Pairs of Spells and Potions
 *
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *successfulPairs(const int *spells, int spellsSize,
					 int *potions, int potionsSize,
					 long long success, int *returnSize);

static int compare_int(const void *p1, const void *p2)
{
	int a = *(const int*) p1;
	int b = *(const int*) p2;
	return (a > b) - (a < b);
}

int binarySearch(const int *arr, int high, long long target)
{
	int mid;
	int res;
	int low = 0;

	res = high + 1;  /* Initialize with one beyond the upper bound */
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		/* >= because we need the first potion that meets the condition */
		if (arr[mid] >= target)
		{
			res = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return res;
}

int *successfulPairs(const int *spells, int spellsSize,
					 int *potions, int potionsSize,
					 long long success, int *returnSize)
{
	int i;
	int idx;
	int *result;
	long long minPotion;

	result = (int *) malloc(spellsSize * sizeof(int));
	qsort(potions, potionsSize, sizeof(int), (__compar_fn_t) compare_int);
	i = -1;
	while (++i < spellsSize)
	{
		/* Calculate the min potion strength required for the current spell */
		minPotion = (success + spells[i] - 1) / spells[i]; // Ceiling division

		/* Use binary search to find the first potion that is >= minPotion */
		idx = binarySearch(potions, potionsSize - 1, minPotion);

		/* The number of successful pairs for the current spell is the number
		 * of potions from 'idx' onward */
		result[i] = potionsSize - idx;
	}
	*returnSize = spellsSize;
	return (result);
}
