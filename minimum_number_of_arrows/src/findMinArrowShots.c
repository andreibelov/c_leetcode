/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findMinArrowShots.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:04:15 by abelov            #+#    #+#             */
/*   Updated: 2025/01/08 12:04:16 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <search.h>
#include <stdlib.h>
#include <limits.h>

/**
 * 452. Minimum Number of Arrows to Burst Balloons
 *
 * There are some spherical balloons taped onto a flat wall that represents
 * the XY-plane. The balloons are represented as a 2D integer array points
 * where points[i] = [Xstart, Xend] denotes a balloon whose horizontal diameter
 * stretches between Xstart and Xend.
 * You do not know the exact y-coordinates of the balloons.
 *
 * Arrows can be shot up directly vertically (in the positive y-direction)
 * from different points along the x-axis. A balloon with Xstart and Xend
 * is burst by an arrow shot at x if Xstart <= x <= Xend.
 * There is no limit to the number of arrows that can be shot. A shot arrow
 * keeps traveling up infinitely, bursting any balloons in its path.
 *
 * Given the array points, return the minimum number of arrows
 * that must be shot to burst all balloons.
 */
int findMinArrowShots(int **points, int pointsSize, int *pointsColSize);

int cmp(const int *const *const l, const int *const *const r)
{ return (*l)[1] - (*r)[1]; }

int cmp2(const int *const *const l, const int *const *const r)
{
	int left = (*l)[1];
	int right = (*r)[1];
	/* Checking for overflow before subtracting */
	/* If overflow would occur, return based on the signs */
	if ((left > 0 && right < INT_MIN + left) || (left < 0 && right > INT_MAX + left))
		return ((left > right) ? 1 : -1);
	else return(left - right);
}

int findMinArrowShots(int **points, int pointsSize, int *pointsColSize)
{
	/* we sort the balloons by their ending points (x_end): */
	qsort(points, pointsSize, sizeof(int *), (__compar_fn_t)({
		/**
		 * @see: https://gcc.gnu.org/onlinedocs/gcc/Nested-Functions.html
		 */
		auto int __lambda_fun(const int *const *const l, const int *const *const r);
		int __lambda_fun(const int *const *const l, const int *const *const r)
		{
			long long diff = (long long)(*l)[1] - (*r)[1];
			return (diff > 0) - (diff < 0); // Compact way to return -1, 0, or 1
		}
		__lambda_fun;
	}));
	long long last = LLONG_MIN; // -(1LL << 60)
	int arrow_count = 0;
	int i = -1;
	while (++i < pointsSize)
	{
		struct balloon {
			int x_start, x_end;
		} *curr = (struct balloon *)points[i];
		if (curr->x_start > last)
		{
			arrow_count++;
			last = curr->x_end;
		}
	}
	return (arrow_count);
}
