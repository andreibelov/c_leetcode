/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leetcode75.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:16:30 by abelov            #+#    #+#             */
/*   Updated: 2024/08/18 14:16:31 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEETCODE75_H
#define LEETCODE75_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>

# define FT_RED   "\033[0;31m"
# define FT_GREEN "\033[0;32m"
# define FT_CYAN  "\033[36m"
# define FT_RESET "\e[0m"

void sigsegv(int signal)
{
	(void) signal;
	printf("> "FT_CYAN".SIGSEGV"FT_RESET"\n");
	exit(EXIT_SUCCESS);
}

void check(bool succes)
{
	if (succes)
		printf("> "FT_GREEN".OK "FT_RESET"\n");
	else
		printf("> "FT_RED".KO "FT_RESET"\n");
}

void ft_print_int_tab(int tab[], size_t size, const char *eol)
{
	size_t pos;

	pos = 0;
	printf("[");
	if (pos < size)
		printf("%d", tab[pos++]);
	while (pos < size)
		printf(", %d", tab[pos++]);
	printf("]");
	if (!eol)
		printf("\n");
	else
		printf("%s", eol);
}

void ft_print_int_tab_null(int tab[], size_t size, int nil, const char *eol)
{
	size_t pos;
	int val;

	pos = 0;
	printf("[");
	if (pos < size)
	{
		val = tab[pos++];
		if (val == nil)
			printf("%s", "null");
		else
			printf("%d", val);
	}
	while (pos < size)
	{
		val = tab[pos++];
		if (val == nil)
			printf(", %s", "null");
		else
			printf(", %d", val);
	}
	printf("]");
	if (!eol)
		printf("\n");
	else
		printf("%s", eol);
}

#endif //LEETCODE75_H
