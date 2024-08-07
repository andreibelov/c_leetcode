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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*gcdOfStrings(char *str1, char *str2);

int main(void)
{
	char	*str1;
	char	*str2;
	char	*gcd;

	str1 = "ABCABC";
	str2 = "ABC";
	gcd = gcdOfStrings(strdup(str1), str2);
	printf("s1: %s; s2: %s; gcd: %s\n", str1, str2, gcd);
	free(gcd);

	str1 = "FSUHYOFFSUHYOFFSUHYOFFSUHYOFFSUHYOF";
	str2 = "FSUHYOFFSUHYOFFSUHYOFFSUHYOFFSUHYOFFSUHYOFFSUHYOFFSUHYOFFSUHYOFFSUHYOFFSUHYOFFSUHYOFFSUHYOF";
	gcd = gcdOfStrings(strdup(str1), str2);
	printf("s1: %s; s2: %s; gcd: %s\n", str1, str2, gcd);
	free(gcd);
	return (EXIT_SUCCESS);
}
