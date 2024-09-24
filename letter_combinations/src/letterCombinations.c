/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letterCombinations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 00:16:41 by abelov            #+#    #+#             */
/*   Updated: 2024/09/24 19:11:20 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

/**
 * 17. Letter Combinations of a Phone Number
 *
 * Given a string containing digits from 2-9 inclusive,
 * return all possible letter combinations that the number could represent.
 * Return the answer in any order.
 */
char **letterCombinations(char *digits, int *returnSize);

#if defined USE_BREADTH_FIRST

#define MAX_QUEUE_SIZE 10000
#define MAX_DIGITS 10

typedef struct queue_el
{
	int index;              // Current index in the digits string
	char combination[MAX_DIGITS + 1]; // Current combination of letters
} queue_el;

static const char *keyboard[10] = {
	"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void letterCombinationsIterative(const char *digits, int n, char **result, int *count)
{
	int i;
	int front = 0, rear = 0;  // Queue front and rear pointers
	queue_el current, next;
	queue_el queue[MAX_QUEUE_SIZE];  // Queue for breadth-first traversal

	// Initialize the queue with an empty combination and starting index 0
	queue[rear].combination[0] = '\0';  // Initialize the first combination as empty
	queue[rear++].index = 0;  // Set the first index to 0

	while (front != rear)
	{
		current = queue[front++];  // Dequeue the front element

		// If the current combination is complete, add it to the result
		if (current.index == n)
			result[(*count)++] = strdup(current.combination);
		else
		{
			// Get the possible letters for the current digit
			const char *letters = keyboard[digits[current.index] - '0'];

			// Enqueue new combinations with each letter appended
			i = -1;
			while (letters[++i] != '\0')
			{
				next = current;
				next.combination[current.index] = letters[i];
				next.combination[current.index + 1] = '\0';  // Ensure null-termination
				next.index++;  // Move to the next digit

				// Enqueue the updated combination
				queue[rear++] = next;
			}
		}
	}
}

char **letterCombinations(char *digits, int *returnSize)
{
	int i, maxSize = 1, n = (int) strlen(digits);
	char **result = NULL;

	*returnSize = 0;
	if (n == 0)
		return NULL;

	// Dynamically calculate maxSize based on actual digits
	for (i = 0; i < n; i++)
		maxSize *= strlen(keyboard[digits[i] - '0']);

	result = (char **) malloc(maxSize * sizeof(char *));
	if (result != NULL)
		letterCombinationsIterative(digits, n, result, returnSize);

	return result;
}

#else
#define MAX_STACK_SIZE 10000
#define MAX_DIGITS 10

typedef struct stack_el
{
	int index; // Current index in the digits string
	char combination[MAX_DIGITS];
} stack_el;

static const char *keyboard[10] = {
	"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void backtrack(const char *digits, int n, char **result, int *count)
{
	int i;
	int sp = 0;
	stack_el current;
	stack_el stack[MAX_STACK_SIZE];
	const char *letters;

	stack[sp].combination[n] = '\0';
	stack[sp++].index = 0;

	while (sp)
	{
		current = stack[--sp];

		if (current.index == n)
			result[(*count)++] = strdup(current.combination);
		else
		{
			letters = keyboard[digits[current.index] - '0'];
			i = -1;
			while (letters[++i] != '\0')
			{
				stack[sp] = current;
				stack[sp].combination[current.index] = letters[i];
				stack[sp++].index++;
			}
		}
	}
}

char **letterCombinations(char *digits, int *returnSize)
{
	int i;
	int n = (int)strlen(digits);
	int maxSize = 1; // can be just `pow(4, n)`
	char **result = NULL;

	*returnSize = 0;
	if (n == 0)
		return NULL;

	i = -1;
	while (++i < n)
		maxSize *= 4;

	result = (char **) malloc(maxSize * sizeof(char *));
	if (result != NULL)
		backtrack(digits, n, result, returnSize);

	return result;
}
#endif
