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

char *strrpbrk(char *start, char *end, const char *accept)
{
	char *found = NULL;

	while(start < end)
	{
		found = strchr(accept, *(end--));
		if (found) break;
	}
	return (found);
}


/**
 * Given a string s, reverse only all the vowels in the string and return it.
 */
char* reverseVowels(char *const str)
{
	char stack[1000000] = {0};
	int stackSize = 0;
	char *s = str;
	char *left = strpbrk(s, "aeiouAEIOU");
//	char *right = strrpbrk(s, s + strlen(s) - 1,"aeiouAEIOU");

	while(*s)
	{
		left = strpbrk(s, "aeiouAEIOU");
		if (!left) break ;
		stack[stackSize++] = *left;
		s = ++left;
	}
	s = str;
	while(*s && stackSize)
	{
		left = strpbrk(s, "aeiouAEIOU");
		if (!left) break ;
		*left = stack[--stackSize];
		s = ++left;
	}
	return (str);
}

