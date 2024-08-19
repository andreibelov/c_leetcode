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
 * As very lower and upper case vowels have the same 5 LSBs.
 * We need a number 0x208222 which gives 1 in its LSB after right-shift
 * 1, 5, 19, 15 otherwise gives 0.
 */
#define MAGIC 0x208222 // 1000001000001000100010

#define SHIFT_MASK 0x1f // 00011111

/**
 * code be more efficient for checking if an input character is a vowel.
 * https://stackoverflow.com/a/36122634/6501644
 * c++ fastest way to check if char is vowel or consonant
 * https://stackoverflow.com/questions/47846406/
 * pre-condition: `c` is alphabetic ASCII, upper or lower case
 * lower and upper case characters have the same 5 lowest bits
 * https://www.geeksforgeeks.org/program-find-character-vowel-consonant/
 */
static inline unsigned char is_vowel(const char c)
{
	return (MAGIC >> (c & SHIFT_MASK)) & 1;
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
