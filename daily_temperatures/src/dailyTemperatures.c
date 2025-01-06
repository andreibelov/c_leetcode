/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dailyTemperatures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:10:35 by abelov            #+#    #+#             */
/*   Updated: 2025/01/06 19:16:24 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <alloca.h>

/**
 * 739. Daily Temperatures
 *
 * Given an array of integers temperatures represents the daily temperatures,
 * return an array answer such that answer[i] is the number of days you have to
 * wait after the ith day to get a warmer temperature.
 * If there is no future day for which this is possible,
 * keep answer[i] == 0 instead.
 *
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *dailyTemperatures(int *temperatures, int temperaturesSize, int *returnSize);

int *dailyTemperatures(int *temperatures, int temperaturesSize, int *returnSize)
{
	int *answer = (int *)calloc(temperaturesSize, sizeof(int));

	int *stack = (int *)alloca(temperaturesSize * sizeof(int));
	int top = -1;

	int i = -1;
	/* Iterate over each day in temperatures */
	while (++i < temperaturesSize)
	{
		while(top >=0 && temperatures[i] > temperatures[stack[top]])
		{
			int previousDayIndex = stack[top--];
			answer[previousDayIndex] = i - previousDayIndex;
		}
		stack[++top] = i;
	}

	*returnSize = temperaturesSize;
	return (answer);
}
