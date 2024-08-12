/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseVowels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:38:54 by abelov            #+#    #+#             */
/*   Updated: 2024/08/12 11:38:54 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/**
 * Given a string s, reverse only all the vowels in the string and return it.
 */
char* reverseVowels(char *const str)
{
	char stack[1000000] = {0};
	int stackSize = 0;
	char *s = str;

	while(*s)
	{
		if (strchr("aeiouAEIOU", *s) != 0)
			stack[stackSize++] = *s;
		s++;
	}
	s = str;
	while(*s && stackSize)
	{
		if (strchr("aeiouAEIOU", *s))
			*s = stack[--stackSize];
		s++;
	}
	return (str);
}
