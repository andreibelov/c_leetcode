/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:33:27 by abelov            #+#    #+#             */
/*   Updated: 2024/08/15 11:33:28 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

int	compress(char *chars, int charsSize);

struct s_input
{
	char *chars;
	int charsSize;
	int returnSize;
	const char *expected;
	int expectedSize;
};

int ft_do_test(struct s_input	*input)
{
	int				check_val;

	input->returnSize = compress(input->chars, input->charsSize);
	if (input->returnSize == input->expectedSize)
	{
		check_val = strncmp(input->chars, input->expected, input->returnSize);
		if (check_val)
			printf("got \"%s\" whilst \"%s\" was to be expected\n",
				   input->chars, input->expected);
		check(!check_val);
	}
	else
		check(false);
	free(input->chars);
	return (0);
}

/**
 *
 */
int	main(void)
{
	int				i;
	struct s_input	inputs[] = {
		{
			.chars = strdup("aabbccc"),
			.charsSize = 7,
			.expected = "a2b2c3",
			.expectedSize = 6
		},
		{
			.chars = strdup("a"),
			.charsSize = 1,
			.expected = "a",
			.expectedSize = 1
		},
		{
			.chars = strdup("abbbbbbbbbbbb"),
			.charsSize = strlen("abbbbbbbbbbbb"),
			.expected = "ab12",
			.expectedSize = 4
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
