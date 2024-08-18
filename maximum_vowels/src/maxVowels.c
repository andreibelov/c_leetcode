/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxVowels.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:07:39 by abelov            #+#    #+#             */
/*   Updated: 2024/08/18 14:07:40 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/**
 * c++ fastest way to check if char is vowel or consonant
 * https://stackoverflow.com/questions/47846406/
 */
static inline unsigned char is_vowel(const char c)
{
	return (0x208222>>(c&0x1f))&1;
}

/**
 * 1456. Maximum Number of Vowels in a Substring of Given Length
 */
int maxVowels(const char *s, int k)
{
	int		i;
	int		max, curr = 0;
	size_t	left_idx = 0;
	size_t	right_idx = k;
	size_t	size = strlen(s);

	i = -1;
	while (++i < k)
		if (is_vowel(*(s + i))) curr++;
	max = curr;
	while (right_idx < size)
	{
		if (is_vowel(*(s + left_idx++))) curr--;
		if (is_vowel(*(s + right_idx++))) curr++;
		if (curr > max) max = curr;
	}
	return (max);
}
