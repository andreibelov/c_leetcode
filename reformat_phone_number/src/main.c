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

char	*reformatNumber(char *s);
char	*reformatNumber1(char *s);
char	*reformatNumber2(char *s);

int main(void)
{
	char	*number;
	char	*new;

	number = strdup("4564561-23-45 78");
	printf("number is: %s\n", number);
	new = reformatNumber2(number);
	printf("reformatted: %s\n", new);
	free(number);
	free(new);
	return (EXIT_SUCCESS);
}
