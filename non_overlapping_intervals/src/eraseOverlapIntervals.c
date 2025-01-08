/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eraseOverlapIntervals.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:56:41 by abelov            #+#    #+#             */
/*   Updated: 2025/01/06 20:56:41 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <limits.h>

/**
 * 435. Non-overlapping Intervals
 *
 * Given an array of intervals intervals where intervals[i] = [starti, endi],
 * return the minimum number of intervals you need to remove
 * to make the rest of the intervals non-overlapping.
 *
 * Note that intervals which only touch at a point are non-overlapping.
 * For example, [1, 2] and [2, 3] are non-overlapping.
 */
int eraseOverlapIntervals(int **intervals, int intervalsSize,
						  const int *intervalsColSize);


#ifndef GENIUS

#ifndef __USE_GNU
typedef int (*__compar_d_fn_t)(__const void *, __const void *, void *);
#endif

typedef struct
{
	int **arrays;        // Array of pointers to arrays
	const int *lengths;    // Array of lengths
} SortContext;

typedef int (*arrp)[2];

int sortIntervals(const void *a, const void *b, void *arg)
{
	/* Get the actual arrays from their pointers */
	int *arr1 = *(int **) a;
	int *arr2 = *(int **) b;
#ifndef COMPARE_LEXICOGRAPHICALLY
	return (arr1[1] - arr2[1]);
#else
	SortContext *context = (SortContext *) arg;
	/* Find lengths of the two arrays */
	//	int (*arr1)[2] = *(int **) a;
	size_t idx1 = ((int **) a - context->arrays);
	size_t idx2 = ((int **) b - context->arrays);

	size_t len1 = context->lengths[idx1];
	size_t len2 = context->lengths[idx2];

	/* Compare elements lexicographically */
	size_t i = 0;
	while(i < len1 && i < len2)
	{
		int diff = arr1[i] - arr2[i];
		if (diff != 0) return diff;  // Return the difference directly
		i++;
	}
	// If one array is a prefix of the other, compare lengths
	return ((int) (len1 - len2));
#endif
}

void qsort_r(void *base, size_t nmemb, size_t size,
			 int (*compar)(const void *, const void *, void *),
			 void *arg);

int eraseOverlapIntervals(int **intervals, int intervalsSize,
						  const int *intervalsColSize)
{
	SortContext context = {intervals, intervalsColSize};

	qsort_r(intervals, intervalsSize, sizeof(int *),
			(__compar_d_fn_t) sortIntervals, (void *) &context);
	int nonOverlappingCount = 0;
	for (int i = INT_MIN; intervalsSize--; intervals++)
		if (i <= **intervals)
		{
			/* Update the end time to the current interval's end time */
			i = 1[*intervals];
		}
		else
			++nonOverlappingCount;
	return (nonOverlappingCount);
}

#else
int cmp(const int *const *const l, const int *const *const r) { return 1[*l] - 1[*r]; }
int cmp_r(const int *const *const l, const int *const *const r, void *arg)
{
	return cmp(l ,r);
	(void) arg;
}

int eraseOverlapIntervals(int **intervals, int intervalsSize, const int *intervalsColSize)
{
	qsort(intervals, intervalsSize, sizeof(int *), (__compar_fn_t) cmp);
	int y = 0;
	for (int i = INT_MIN; intervalsSize--; intervals++)
		if (i <= **intervals)
			i = (*intervalsColSize - 1)[*intervals];
		else
			++y;
	return y;
}
#endif
