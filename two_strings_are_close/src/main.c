/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:06:19 by abelov            #+#    #+#             */
/*   Updated: 2024/08/24 23:06:20 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

bool closeStrings(char *word1, char *word2);

struct s_input
{
	const char	*str1;
	const char	*str2;
	bool		expected;
};

int ft_do_test(struct s_input *input)
{
	bool	result;
	int		check_val;
	char	*str1 = strdup(input->str1);
	char	*str2 = strdup(input->str2);

	result = closeStrings(str1, str2);
	check_val = (input->expected != result);
	if (check_val)
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   result, input->expected);
	check(!check_val);
	return (free(str1), free(str2), 0);
}

int main(void)
{
	int				i;
	struct s_input	inputs[] = {
		{
			.str1 = "abc",
			.str2 = "bca",
			.expected = true
		},
		{
			.str1 = "a",
			.str2 = "aa",
			.expected = false
		},
		{
			.str1 = "cabbba",
			.str2 = "abbccc",
			.expected = true
		},
		{
			.str1 = "ababzzc",
			.str2 = "babzzcz",
			.expected = false
		},
		{
			.str1 = "svotbsgqiqmeqjwdqqtkucrzqphqxqtqqlyfan",
			.str2 = "aapyhufaaaalkqsvtjnaaoewxkrgsbsazadmci",
			.expected = true
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
