/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:58:15 by abelov            #+#    #+#             */
/*   Updated: 2024/08/26 21:06:05 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

char	*reverseWords(char *s);

struct s_input
{
	const char	*str;
	const char	*expected;
};

int ft_do_test(struct s_input *input)
{
	char	*result;
	int		check_val;

	result = reverseWords(strcpy(alloca(strlen(input->str) + 1), input->str));
	check_val = strcmp(input->expected, result);
	if (check_val)
		printf("got \"%s\" whilst \"%s\" was to be expected\n",
			   result, input->expected);
	check(!check_val);
	return (0);
}

int main(void)
{
	int				i;
	struct s_input	inputs[] = {
		{
			.str = "the sky is blue",
			.expected = "blue is sky the"
		},
		{
			.str = "  hello world  ",
			.expected = "world hello"
		},
		{
			.str = "a good   example",
			.expected = "example good a"
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
