/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinationSum3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:10:15 by abelov            #+#    #+#             */
/*   Updated: 2024/09/25 00:10:16 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

/**
 * 216. Combination Sum III
 *
 * Find all valid combinations of k numbers that sum up to n such that
 * the following conditions are true:
 * 	Only numbers 1 through 9 are used.
 * 	Each number is used at most once.
 *
 * Return a list of all possible valid combinations.
 * The list must not contain the same combination twice, and the combinations
 * may be returned in any order.
 *
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 *
 * Note: Both returned array and *columnSizes array must be malloced,
 * assume caller calls free().
 */
int **combinationSum3(int k, int n, int *returnSize, int **returnColumnSizes);

#define MAX_RESULTS 100
#define MAX_STACK_SIZE 10000

typedef struct
{
	int solution[9]; // Current combination being built
	int len;         // Length of the current combination
	int start;       // Current start index for choosing numbers
	int target;      // Remaining target sum
} StackFrame;

int **combinationSum3(int k, int n, int *returnSize, int **returnColumnSizes)
{
	int i;
	int count = 0;
	int nums[9];
	int **result_ptr;
	// Statically allocate memory for results
	static int results[MAX_RESULTS][9];
	static int col_sizes[MAX_RESULTS];

	// Stack for backtracking simulation
	int sp = 0;
	StackFrame stack[MAX_STACK_SIZE];
	StackFrame frame;
	StackFrame new;

	*returnColumnSizes = col_sizes;
	// Fill the array with numbers 1 to 9
	i = -1;
	while (++i < 9)
		nums[i] = i + 1;

	// Push the initial frame to the stack
	stack[sp++] = (StackFrame){.len = 0, .start = 0, .target = n};

	while (sp)
	{
		frame = stack[--sp];

		if (frame.len == k)
		{
			if (frame.target == 0)
			{
				// Copy the solution into results
				memcpy(results[count], frame.solution, k * sizeof(int));
				col_sizes[count++] = k;
			}
		}
		else
		{
			i = frame.start - 1;
			while (++i < 9)
			{
				if (frame.target >= nums[i])
				{
					new = frame; // Copy current frame
					new.solution[frame.len] = nums[i]; // Add new number to solution
					new.len = frame.len + 1; // Increment length
					new.start = i + 1; // Move to the next index
					new.target = frame.target - nums[i]; // Decrease target
					stack[sp++] = new; // Push the new frame onto the stack
				}
			}
		}
	}

	*returnSize = count;

	/* Allocate and copy results into return format */
	result_ptr = (int **)malloc(count * sizeof(int *));
	i = -1;
	while (++i < count)
	{
		result_ptr[i] = (int *)malloc(k * sizeof(int));
		memcpy(result_ptr[i], results[i], k * sizeof(int));
	}

	return result_ptr;
}
