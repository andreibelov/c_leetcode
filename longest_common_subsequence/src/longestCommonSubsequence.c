/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longestCommonSubsequence.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:39:59 by abelov            #+#    #+#             */
/*   Updated: 2025/01/10 10:39:59 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <alloca.h>

/**
 * 1143. Longest Common Subsequence
 *
 * Given two strings text1 and text2, return the length of their longest common
 * subsequence. If there is no common subsequence, return 0.
 */
int longestCommonSubsequence(char *text1, char *text2);

int longestCommonSubsequence(char *text1, char *text2)
{
	int len1 = (int)strlen(text1), len2 = (int)strlen(text2);

	int (*dp)[len2 + 1] = (int (*)[len2 + 1])alloca((len1 + 1) * (len2 + 1) * sizeof(int));
	memset(dp, 0, (len1 + 1) * (len2 + 1) * sizeof(int));

	auto int max(int X, int Y);
	int max(int X, int Y) { return ((X) > (Y)) ? (X) : (Y); }

	for (int i = 1; i <= len1; ++i) for (int j = 1; j <= len2; ++j)
	{
		if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
		else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	}

	return (dp[len1][len2]);
}
