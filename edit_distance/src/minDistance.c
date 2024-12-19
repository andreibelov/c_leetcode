/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minDistance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:37:20 by abelov            #+#    #+#             */
/*   Updated: 2024/12/19 16:54:05 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <alloca.h>

static inline int min(int a, int b)
{ return a < b ? a : b; }

/**
 * 72. Edit Distance
 *
 * Given two strings word1 and word2, return the minimum number of operations
 * required to convert word1 to word2.
 */
int minDistance(const char* word1, const char* word2)
{
	int i, j;
	int l1 = (int)strlen(word1);
	int l2 = (int)strlen(word2);
	int *table = (int *)alloca((l1 + 1) * (l2 + 1) * sizeof(int));
	int **tab = (int **)alloca((l1 + 1) * sizeof(int *));

	i = -1;
	while(++i < l1 + 1)
		tab[i] = table + i * (l2 + 1);

	tab[0][0] = 0;
	i = 0;
	while (++i <= l2)
		tab[0][i] = i;
	i = 0;
	while (++i <= l1)
		tab[i][0] = i;

	i = 0;
	while (++i <= l1)
	{
		j = 0;
		while (++j <= l2)
		{
			if (word1[i - 1] == word2[j - 1]) tab[i][j] = tab[i - 1][j - 1];
			else tab[i][j] = 1 + min(tab[i - 1][j - 1],
									 min(tab[i - 1][j], tab[i][j - 1]));
		}
	}

	return tab[l1][l2];
}
