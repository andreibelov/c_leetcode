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

#define ALPHABET_SIZE ('z' - 'a' + 1)

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
	int 		i;
	const int	len1 = (int)strlen(word1);
	const int	len2 = (int)strlen(word2);
	int			*hashset1 = (int *)alloca(ALPHABET_SIZE * sizeof(int));
	int			*hashset2 = (int *)alloca(ALPHABET_SIZE * sizeof(int));

	if (len1 == len2)
	{
		memset(hashset1, 0, sizeof(int) * ALPHABET_SIZE);
		memset(hashset2, 0, sizeof(int) * ALPHABET_SIZE);
		i = -1;
		while (++i < len1)
		{
			hashset1[word1[i] - 'a']++;
			hashset2[word2[i] - 'a']++;
		}
		i = -1;
		while (++i < ALPHABET_SIZE)
			if ((hashset1[i] == 0 && hashset2[i] != 0)
				|| (hashset2[i] == 0 && hashset1[i] != 0))
				return (false);
		qsort(hashset1, ALPHABET_SIZE, sizeof(int), (__compar_fn_t) intcmp);
		qsort(hashset2, ALPHABET_SIZE, sizeof(int), (__compar_fn_t) intcmp);
		if (!memcmp(hashset1, hashset2, ALPHABET_SIZE * sizeof(int)))
			return (true);
	}
	return (false);
}
