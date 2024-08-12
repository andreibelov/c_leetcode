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

char *strrpbrk(const char *start, const char *end, const char *accept)
{
	char *found = NULL;

	while(start < end)
	{
		if (strchr(accept, *end))
		{
			found = (char *)end;
			break;
		}
		end--;
	}
	return (found);
}

/**
 * Given a string s, reverse only all the vowels in the string and return it.
 */
char* reverseVowels(char *const str)
{
	char c;
	char	*s = str;
	size_t	len = strlen(s);
	char	*left = strpbrk(s, "aeiouAEIOU");
	char	*right = strrpbrk(s, s + len - 1, "aeiouAEIOU");

	while((left && right) && (left < right))
	{
		c = *left;
		*left = *right;
		*right = c;
		right = strrpbrk(++left, --right, "aeiouAEIOU");
		left = strpbrk(left, "aeiouAEIOU");
	}
	return (str);
}

