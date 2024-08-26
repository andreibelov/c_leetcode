/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removeStars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:48:30 by abelov            #+#    #+#             */
/*   Updated: 2024/08/26 20:48:31 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * 2390. Removing Stars From a String
 *
 * Given a string s, which contains stars *.
 * In one operation, you can:
 * 	Choose a star in s.
 * 	Remove the closest non-star character to its left,
 * 	as well as remove the star itself.
 *
 * 	Constraints:
 * 		1 <= s.length <= 105
 * 		s consists of lowercase English letters and stars *.
 * 		The operation can be performed on s itself.
 */
char *removeStars(char *s);

char *removeStars(char *s)
{
	char 		c;
	char *const	ostr = s;
	size_t		stackSize = 0;

	while (*s)
	{
		c = *s++;
		if (c != '*') ostr[stackSize++] = c;
		else if (stackSize != 0) stackSize--;
	}
	ostr[stackSize] = '\0';
	return (ostr);
}
