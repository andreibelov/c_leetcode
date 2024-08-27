/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asteroidCollision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:52:09 by abelov            #+#    #+#             */
/*   Updated: 2024/08/26 21:52:09 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <string.h>
#include <stdlib.h>

/**
 * 735. Asteroid Collision
 *
 * We are given an array asteroids of integers representing asteroids in a row.
 * For each asteroid, the absolute value represents its size, and the sign
 * represents its direction (positive meaning right, negative meaning left).
 * Each asteroid moves at the same speed.
 *
 * Find out the state of the asteroids after all collisions.
 * If two asteroids meet, the smaller one will explode.
 * If both are the same size, both will explode.
 * Two asteroids moving in the same direction will never meet.
 *
 * Constraints:
 * 	2 <= asteroids.length <= 104
 * 	-1000 <= asteroids[i] <= 1000
 * 	asteroids[i] != 0
 *
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *asteroidCollision(int *asteroids, int asteroidsSize, int *returnSize);
#if !defined BETTER
int *asteroidCollision(int *asteroids, int asteroidsSize, int *returnSize)
{
	int	*stack = (int *)malloc(asteroidsSize * sizeof(int));
	int stackSize = 0;
	int i, curr, prev;

	if (asteroidsSize < 2)
	{
		memcpy(stack, asteroids, asteroidsSize * sizeof(int));
		*returnSize = stackSize;
		return (stack);
	}

	i = -1;
	while(++i < asteroidsSize)
	{
		stack[stackSize++] = asteroids[i];
		if (stackSize > 1)
		{
			curr = stack[stackSize - 1];
			prev = stack[stackSize - 2];
			while (prev > 0 && curr < 0)
			{
				if (abs(curr) == abs(prev))
				{
					// Both asteroids explode
					stackSize = stackSize - 2;
					break ;
				}
				else if (abs(curr) > abs(prev))
				{
					// The previous asteroid is destroyed
					stack[--stackSize - 1] = curr;
				}
				else stackSize--; // The current asteroid is destroyed
				if (stackSize < 2) break ;
				curr = stack[stackSize - 1];
				prev = stack[stackSize - 2];
			}
		}
	}
	*returnSize = stackSize;
	return (stack);
}

#else
int *asteroidCollision(int *asteroids, int asteroidsSize, int *returnSize)
{
	int	*stack = (int *)malloc(asteroidsSize * sizeof(int));
	int stackSize = 0;
	int i, curr, prev;

	if (asteroidsSize < 2)
	{
		memcpy(stack, asteroids, asteroidsSize * sizeof(int));
		*returnSize = stackSize;
		return (stack);
	}

	i = -1;
	while(++i < asteroidsSize)
	{
		curr = asteroids[i];
		while (stackSize > 0 && stack[stackSize - 1] > 0 && curr < 0)
		{
			prev = stack[stackSize - 1];
			if (abs(prev) == abs(curr))
			{
				stackSize--; // Both asteroids explode
				curr = 0;    // No asteroid remains
				break;
			}
			else if (abs(prev) > abs(curr)) curr = 0; // The current asteroid is destroyed
			else stackSize--; // The previous asteroid is destroyed
		}
		if (curr != 0) stack[stackSize++] = curr; // If the current asteroid is still alive
	}
	*returnSize = stackSize;
	return (stack);
}
#endif
