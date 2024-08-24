/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closeStrings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:06:28 by abelov            #+#    #+#             */
/*   Updated: 2024/08/24 23:06:28 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef enum bool
{
	false = 0,
	true = 1
} bool;

int intcmp(const int *a, const int *b)
{
	return (*a > *b) - (*a < *b);
}

/**
 * 1657. Determine if Two Strings Are Close
 * Two strings are considered close if you can attain one from the other
 * using the following operations:
 * Operation 1: Swap any two existing characters.
 *      For example, abcde -> aecdb
 * Operation 2: Transform every occurrence of one existing character into
 * another existing character, and do the same with the other character.
 *      For example, aacabb -> bbcbaa
 *      (all a's turn into b's, and all b's turn into a's)
 */
bool closeStrings(char *word1, char *word2)
{
	int i;
	const int len1 = (int)strlen(word1);
	const int len2 = (int)strlen(word2);
	int		*hashset1 = (int *)alloca(UCHAR_MAX * sizeof(int));
	int		*hashset2 = (int *)alloca(UCHAR_MAX * sizeof(int));
	char	c;
	char	set1[27] = {0};
	int		set1Size = 0;
	char	set2[27] = {0};
	int		set2Size = 0;

	if (len1 != len2)
		return (false);

	i = -1;
	while (++i < UCHAR_MAX)
	{
		hashset1[i] = 0;
		hashset2[i] = 0;
	}

	i = -1;
	while (++i < len1)
	{
		c = word1[i];
		if (hashset1[(unsigned char)c]++ == 0)
			set1[set1Size++] = c;
	}
	set1[set1Size] = '\0';

	i = -1;
	while (++i < len2)
	{
		c = word2[i];
		if (hashset2[(unsigned char)c]++ == 0)
			set2[set2Size++] = c;
	}
	set2[set1Size] = '\0';
	qsort(set1, set1Size, sizeof(char), (__compar_fn_t) strcmp);
	qsort(set2, set2Size, sizeof(char), (__compar_fn_t) strcmp);
	qsort(hashset1, UCHAR_MAX, sizeof(int), (__compar_fn_t) intcmp);
	qsort(hashset2, UCHAR_MAX, sizeof(int), (__compar_fn_t) intcmp);
	if (!memcmp(hashset1, hashset2, UCHAR_MAX * sizeof(int)))
		if (strcmp(set1, set2) == 0) return (true);
	return (false);
}