/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:29:06 by abelov            #+#    #+#             */
/*   Updated: 2024/08/09 14:29:07 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

# define FT_RED   "\033[0;31m"
# define FT_GREEN "\033[0;32m"
# define FT_CYAN  "\033[36m"
# define FT_RESET "\e[0m"

void sigsegv(int signal)
{
	(void) signal;
	printf("> "FT_CYAN".SIGSEGV"FT_RESET"\n");
	exit(EXIT_SUCCESS);
}

void check(bool succes)
{
	if (succes)
		printf("> "FT_GREEN".OK "FT_RESET"\n");
	else
		printf("> "FT_RED".KO "FT_RESET"\n");
}

bool *kidsWithCandies(int *candies,
					  int candiesSize,
					  int extraCandies,
					  int *returnSize);

struct s_input
{
	int *candies;
	int candiesSize;
	int extraCandies;
	int returnSize;
	bool *expected;
};

/**
 * There are n kids with candies. You are given an integer array candies,
 * where each candies[i] represents the number of candies the ith kid has,
 * and an integer extraCandies, denoting the number of extra candies
 * that you have.
 *
 * Return a boolean array result of length n, where result[i] is true if,
 * after giving the ith kid all the extraCandies, they will have
 * the greatest number of candies among all the kids, or false otherwise.
 *
 * multiple kids can have the greatest number of candies
 */
int main(void)
{
	struct s_input inputs[] = {
		{
			.extraCandies = 3,
			.candiesSize = 5,
			.candies = (int[]) {2, 3, 5, 1, 3},
			.expected = (bool[]) {true, true, true, false, true}
		},
		{
			.extraCandies = 1,
			.candiesSize = 5,
			.candies = (int[]) {4, 2, 1, 1, 2},
			.expected = (bool[]) {true, false, false, false, false}
		}
	};
	int i;
	struct s_input *input;
	bool *result;

	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
	{
		input = &inputs[i];
		result = kidsWithCandies(input->candies,
								 input->candiesSize,
								 input->extraCandies,
								 &input->returnSize);
		if (input->returnSize == input->candiesSize)
			check(!memcmp(result, input->expected, (sizeof(bool) * input->returnSize)));
		else
			check(false);
		free(result);
	}
	return (EXIT_SUCCESS);
}
