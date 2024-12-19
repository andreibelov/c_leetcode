/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:35:35 by abelov            #+#    #+#             */
/*   Updated: 2024/12/18 00:35:35 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 72. Edit Distance
 *
 * Given two strings word1 and word2, return the minimum number of operations
 * required to convert word1 to word2.
 *
 * Constraints:
 * 	0 <= word1.length, word2.length <= 500
 * 	word1 and word2 consist of lowercase English letters.
 */
int minDistance(const char* word1, const char* word2);

struct s_input
{
	const char	*word1;
	const char	*word2;
	int expected;
};

int ft_do_test(struct s_input *input)
{
	int result;
	int check_val;

	result = minDistance(input->word1, input->word2);
	check_val = (input->expected == result);
	if (!check_val)
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   result, input->expected);
	check(check_val);
	return (0);
}

int main(void)
{
	int				i;
	struct s_input	inputs[] = {
		{
			.word1 = "horse",
			.word2 = "ros",
			.expected = 3
		},
		{
			.word1 = "intention",
			.word2 = "execution",
			.expected = 5
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
