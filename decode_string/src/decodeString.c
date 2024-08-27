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
char *decodeString(const char *s);

__attribute__((no_sanitize_undefined))
char *decodeString(const char *str)
{
	int		i;
	char	c;
	char	tempStack[1000];
	char	*buf = (char *)malloc(10000 * sizeof(char));
	char	*buf_ptr = buf;
	char	*temp_ptr = tempStack + 999;
	size_t	len = strlen(str);
	size_t	segmentLen = 0;
	int		nbr = 0;
	char    *tmp;

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
				{
					tmp = strncat(buf_ptr, temp_ptr, segmentLen) + segmentLen;
					*tmp = '\0';
					buf_ptr = tmp;
				}
			}
			temp_ptr = tempStack + 999;
		}
		else
			*buf_ptr++ = c;
	}
	*buf_ptr = '\0';
	temp_ptr = strdup(buf);
	free(buf);
	return (temp_ptr);
}
