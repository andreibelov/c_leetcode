/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:23:47 by abelov            #+#    #+#             */
/*   Updated: 2024/08/11 16:23:48 by abelov           ###   ########.fr       */
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

bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n);

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

void ft_print_int_tab(int tab[], size_t size, char *eol)
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

int ft_do_test(int *flowerbed, int flowerbedSize, int n, unsigned char expected)
{
	ft_print_int_tab(flowerbed, flowerbedSize, NULL);
	return (canPlaceFlowers(flowerbed, flowerbedSize, n) == expected);
}

int main(void)
{
	signal(SIGSEGV, sigsegv);
	check(ft_do_test((int[]) {1, 0, 0, 0, 1}, 5, 1, true));
	check(ft_do_test((int[]) {1, 0, 0, 0, 1}, 5, 2, false));
	return (EXIT_SUCCESS);
}
