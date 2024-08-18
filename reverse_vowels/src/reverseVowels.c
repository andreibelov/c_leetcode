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

static inline char	*strrpbrk(const char *start, const char *end, const char *c)
{
	char *found = NULL;

	while(start < end)
	{
		if (strchr(c, *end))
		{
			found = (char *)end;
			break;
		}
		end--;
	}
	return (found);
}

/**
 * 345. Reverse Vowels of a String
 * Given a string s, reverse only all the vowels in the string and return it.
 */
char* reverseVowels(char *const str)
{
	const char *vowels = "aeiouAEIOU";
	char c;
	size_t	len = strlen(str);
	char	*left = strpbrk(str, vowels);
	char	*right = strrpbrk(str, str + len - 1, vowels);

	while((left && right) && (left < right))
	{
		c = *left;
		*left = *right;
		*right = c;
		right = strrpbrk(left, --right, vowels);
		left = strpbrk(++left, vowels);
	}
	return (str);
}
