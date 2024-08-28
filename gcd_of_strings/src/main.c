/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:34:42 by abelov            #+#    #+#             */
/*   Updated: 2024/08/07 09:34:43 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

char	*gcdOfStrings(const char *s1, const char *s2);

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

	result = gcdOfStrings(input->str1, input->str2);
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
			.str1 = "ABCABC",
			.str2 = "ABC",
			.expected = "ABC"
		},
		{
			.str1 = "ABABAB",
			.str2 = "ABAB",
			.expected = "AB"
		},
		{
			.str1 = "LEET",
			.str2 = "CODE",
			.expected = ""
		},
		{
			.str1 = "FSUHYOFFSUHYOFFSUHYOFFSUHYOFFSUHYOF",
			.str2 = "FSUHYOFFSUHYOFFSUHYOFFSUHYOFFSUHYOFFSUHYOFFSUHYOFFSUHYOFFSUHYOFFSUHYOFFSUHYOFFSUHYOFFSUHYOF",
			.expected = "FSUHYOF"
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
