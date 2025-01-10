/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:37:43 by abelov            #+#    #+#             */
/*   Updated: 2025/01/10 10:37:43 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 1143. Longest Common Subsequence
 *
 * Given two strings text1 and text2, return the length of their longest common
 * subsequence. If there is no common subsequence, return 0.
 *
 * Constraints:
 *  1 <= text1.length, text2.length <= 1000
 *  text1 and text2 consist of only lowercase English characters.
 */
int longestCommonSubsequence(char *text1, char *text2);

typedef struct s_input
{
	const char	*str1;
	const char	*str2;
	int			expected;
}	Input;

int ft_do_test(Input *input)
{
	int		result;
	int		check_val;
	char	*text1 = strdup(input->str1);
	char	*text2 = strdup(input->str2);

	result = longestCommonSubsequence(text1, text2);
	check_val = (input->expected != result);
	if (check_val)
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   result, input->expected);
	check(!check_val);
	return (free(text1), free(text2), 0);
}

int main(void)
{
	int				i;
	Input	inputs[] = {
		{
			.str1 = "abcde",
			.str2 = "ace",
			.expected = 3
		},
		{
			.str1 = "abc",
			.str2 = "abc",
			.expected = 3
		},
		{
			.str1 = "abc",
			.str2 = "def",
			.expected = 0
		},
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}

