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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>

# define FT_RED   "\033[0;31m"
# define FT_GREEN "\033[0;32m"
# define FT_CYAN  "\033[36m"
# define FT_RESET "\e[0m"

void	sigsegv(int signal)
{
	(void)signal;
	printf("> "FT_CYAN".SIGSEGV"FT_RESET"\n");
	exit(EXIT_SUCCESS);
}

void	check(bool succes)
{
	if (succes)
		printf("> "FT_GREEN".OK "FT_RESET"\n");
	else
		printf("> "FT_RED".KO "FT_RESET"\n");
}

int	ft_strcmp(const char *s1, const char *s2)
{
	printf("res: \"%s\"; exp: \"%s\"\n", s1, s2);
	return strcmp(s1,s2);
}

struct s_input
{
	char *chars;
	int charsSize;
	int returnSize;
	const char *expected;
	int expectedSize;
};


int	compress(char *chars, int charsSize);

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
