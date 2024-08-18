/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeAlternately.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:51:54 by abelov            #+#    #+#             */
/*   Updated: 2024/08/17 21:51:54 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <malloc.h>

/**
 * 1768. Merge Strings Alternately
 */
char *mergeAlternately(const char *word1, const char *word2)
{

	char	*new,*onew = NULL;
	size_t	len1, len2;

	if (!word1 || !word2)
		return (NULL);
	len1 = strlen(word1);
	len2 = strlen(word2);
	new = (char *)malloc(sizeof(char) * ((len1 >= len2 ? len1 : len2) * 2 + 1));
	if (!new)
		return (NULL);
	onew = new;
	if (len1 >= len2) {
		while (*word2) {
			*new++ = *word1++;
			*new++ = *word2++;
		}
		while (*word1)
			*new++ = *word1++;
	}
	else {
		while (*word1) {
			*new++ = *word1++;
			*new++ = *word2++;
		}
		while (*word2)
			*new++ = *word2++;
	}
	*new = '\0';
	return (onew);
}
