/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:08:35 by abelov            #+#    #+#             */
/*   Updated: 2024/08/18 14:08:35 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

char *mergeAlternately(const char *word1, const char *word2);

struct s_input
{
	const char	*str1;
	const char	*str2;
	const char	*expected;
};

int ft_do_test(struct s_input *input)
{
	char	*result;
	int		check_val;

	result = mergeAlternately(input->str1, input->str2);
	check_val = strcmp(input->expected, result);
	if (check_val)
		printf("got \"%s\" whilst \"%s\" was to be expected\n",
			   result, input->expected);
	check(!check_val);
	free(result);
	return (0);
}


int main(void)
{
	int				i;
	struct s_input	inputs[] = {
		{
			.str1 = "abc",
			.str2 = "pqr",
			.expected = "apbqcr"
		},
		{
			.str1 = "ab",
			.str2 = "pqrs",
			.expected = "apbqrs"
		},
		{
			.str1 = "abcd",
			.str2 = "pq",
			.expected = "apbqcd"
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
