/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:58:15 by abelov            #+#    #+#             */
/*   Updated: 2024/08/12 22:58:15 by abelov           ###   ########.fr       */
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

char	*reverseWords(char *s);

/**
 *
 */
int	main(void)
{
	signal(SIGSEGV, sigsegv);
	check(!ft_strcmp(reverseWords(strdup("the sky is blue")), "blue is sky the"));
	check(!ft_strcmp(reverseWords(strdup("  hello world  ")), "world hello"));
	check(!ft_strcmp(reverseWords(strdup("a good   example")), "example good a"));

	return (EXIT_SUCCESS);
}
