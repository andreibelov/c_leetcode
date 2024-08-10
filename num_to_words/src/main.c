/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:59:49 by abelov            #+#    #+#             */
/*   Updated: 2024/08/07 11:59:49 by abelov           ###   ########.fr       */
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

char	*numberToWords(int num);

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

int main(void)
{
	const char	*str;

	printf("%d, %d, %d, %d\n", 10 % 3, 10 / 3, 9 % 3, 9 / 3);

	signal(SIGSEGV, sigsegv);
	check(!ft_strcmp(numberToWords(0), "Zero"));
	check(!ft_strcmp(numberToWords(1000000), "One Million"));
	check(!ft_strcmp(numberToWords(1000), "One Thousand"));
	str = "One Hundred Twenty Three";
	check(!ft_strcmp(numberToWords(123), str));
	str = "Twelve Thousand Three Hundred Forty Five";
	check(!ft_strcmp(numberToWords(12345), str));
	str = "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven";
	check(!ft_strcmp(numberToWords(1234567), str));
	str = "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One";
	check(!ft_strcmp(numberToWords(1234567891), str));
	check(!ft_strcmp(numberToWords(10), "Ten"));
	check(!ft_strcmp(numberToWords(7), "Seven"));
	check(!ft_strcmp(numberToWords(17), "Seventeen"));
	check(!ft_strcmp(numberToWords(20), "Twenty"));

	return (EXIT_SUCCESS);
}
