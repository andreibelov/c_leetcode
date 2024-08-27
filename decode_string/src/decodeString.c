/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decodeString.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:45:13 by abelov            #+#    #+#             */
/*   Updated: 2024/08/27 13:45:14 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * 394. Decode String
 *
 * Given an encoded string, return its decoded string.
 * The encoding rule is: k[encoded_string], where the encoded_string inside
 * the square brackets is being repeated exactly k times.
 *
 * Constraints:
 *     1 <= s.length <= 30
 *     s consists of lowercase English letters, digits, and square brackets '[]'.
 *     s is guaranteed to be a valid input.
 *     All the integers in s are in the range [1, 300].
 *
 * Note that k is guaranteed to be a positive integer.
 */
char *decodeString(char *s);

#if defined USE_TEMP_STACK

char *decodeString(const char *s)
{
	int		i;
	char	c;
	int		num = 0;  // For storing the current number

	char	*result = (char *)malloc(10000 * sizeof(char));
	char	*resultPtr = result;  // Position in the result array

	char	*segments[15];  // Stack to store pointers to parts of the result string
	int		counts[15] = {0};  // Stack to store repeat counts
	int		stackPos = 0;  // Stack pointer

	char	*segmentStart;
	int		repeatCount;
	int		segmentLength;

	const char *ptr = s;

	while (*ptr)
	{
		c = *ptr;
		if (isdigit(c))
			num = num * 10 + (c - '0');
		else if (c == '[')
		{
			counts[stackPos] = num;  /* Push the current number onto the stack */
			segments[stackPos++] = resultPtr;  /* Push the current position onto the stack */
			num = 0;  /* Reset the number */
		}
		else if (c == ']')
		{
			segmentStart = segments[--stackPos];
			repeatCount = counts[stackPos];
			segmentLength = (int)(resultPtr - segmentStart);
			i = -1; /* Repeat the segment `repeatCount` times */
			while (++i < repeatCount - 1)
				resultPtr = strncpy(resultPtr, segmentStart, segmentLength) + segmentLength;
		}
		else
			*resultPtr++ = c;
		ptr++;
	}
	*resultPtr = '\0';
	return result;
}

#else
#define TEMP_STACK_SIZE 1000
__attribute__((no_sanitize_undefined))
char *decodeString(char *str)
{
	int		i;
	char	c;
	int		nbr = 0;
	char	tempStack[TEMP_STACK_SIZE];
	char	*tempStackEnd = tempStack + TEMP_STACK_SIZE - 1;
	char	*temp_ptr = tempStackEnd;
	char	*buf = (char *)malloc(10000 * sizeof(char));
	char	*buf_ptr = buf;
	size_t	len = strlen(str);
	size_t	segmentLen = 0;

	*temp_ptr = '\0';
	*buf_ptr = '\0';
	i = -1;
	while (++i < (int)len)
	{
		c = str[i];
		if (c == ']')
		{
			c = *(--buf_ptr);
			while (c != '[')
			{
				*(--temp_ptr) = c;
				c = *(--buf_ptr);
			}
			*buf_ptr-- = '\0';
			while (buf_ptr >= buf && isdigit(*buf_ptr))
				buf_ptr--;
			buf_ptr++;
			nbr = (int)strtol(buf_ptr, (char **) NULL, 10);
			if (nbr > 0)
			{
				segmentLen = strlen(temp_ptr);
				strcpy(buf_ptr, temp_ptr);
				buf_ptr += segmentLen;
				while (--nbr)
					buf_ptr = strncpy(buf_ptr, temp_ptr, segmentLen) + segmentLen;
			}
			temp_ptr = tempStackEnd;
		}
		else
			*buf_ptr++ = c;
	}
	*buf_ptr = '\0';
	return (buf);
}
#endif
