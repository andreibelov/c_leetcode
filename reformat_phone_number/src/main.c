/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:57:33 by abelov            #+#    #+#             */
/*   Updated: 2024/08/06 11:57:33 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "leetcode75.h"

char *reformatNumber(char *s);

struct s_input
{
	const char	*str;
	const char	*expected;
};

int ft_do_test(struct s_input *input)
{
	char	*result;
	int		check_val;

	result = reformatNumber(strcpy(alloca(strlen(input->str) + 1), input->str));
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
			.str = "1-23-45 6",
			.expected = "123-456"
		},
		{
			.str = "123 4-567",
			.expected = "123-45-67"
		},
		{
			.str = "123 4-5678",
			.expected = "123-456-78"
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
