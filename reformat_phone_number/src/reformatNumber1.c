/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reformatNumber1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 23:57:06 by abelov            #+#    #+#             */
/*   Updated: 2024/08/07 00:01:27 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <ctype.h>



char	*ft_strnlpcat(char *dest, const char *src, size_t *dst_size, size_t n)
{
	size_t			i;
	const size_t	osize = *dst_size;
	char *const		odest = dest;
	size_t			size;

	size = osize - 1;
	if (!dest)
		return (NULL);
	while (*dest && size--)
		dest++;
	if ((size_t)(dest - odest) >= osize)
		return (NULL);
	i = 0;
	if (size > 0)
	{
		while ((0 < size) && *src && (i++ < n))
			(size--, *dest++ = *src++);
		while ((0 < size) && (i++ < n))
			(size--, *dest++ = '\0');
		*dest = '\0';
	}
	*dst_size = ++size;
	return (dest);
}

static size_t	cleanup(char *s, char **p)
{
	size_t	len;
	char	*tmp;
	char	*new;
	char	c;

	*p = NULL;
	if (!s)
		return (0);
	len = strlen(s);
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (0);
	*new = '\0';
	tmp = new;
	while (*s)
	{
		c = *s++;
		if(isdigit(c))
			*new++ = c;
	}
	*new = '\0';
	*p = tmp;
	return (new - tmp);
}

/**
 * Given is a phone number as a string number.
 * Number consists of digits, spaces ' ', and/or dashes '-'.
 * reformatNumber() reformats the phone number so that is removes all spaces
 * and dashes. Then, groups the digits from left to right into blocks
 * of length 3 until there are 4 or fewer digits.
 * The final digits are then grouped.
 * Return the phone number after formatting.
 */
char	*reformatNumber1(char *s)
{
	char	*p;
	char	*new;
	int 	i;
	char	*clean;
	size_t	len = cleanup(s, &clean);
	size_t	buff_size = len + (len / 3) +  1;

	new = (char *)malloc(buff_size * sizeof(char));
	if (!new)
		return (free(clean), NULL);
	*new = '\0';

	i = 0;
	p = new;
	if (len <= 1)
		new = (free(new), NULL);
	if (len > 4)
	{
		while (len > 4)
		{
			p = ft_strnlpcat(p, clean + i, &buff_size, 3);
			p = ft_strnlpcat(p, "-", &buff_size, 1);
			len -= 3;
			i += 3;
		}
	}
	if (len == 2 || len == 3)
		ft_strnlpcat(p, clean + i, &buff_size, len);
	else if (len == 4)
	{
		p = ft_strnlpcat(p, clean + i, &buff_size, 2);
		p = ft_strnlpcat(p, "-", &buff_size, 1);
		ft_strnlpcat(p, clean + i + 2, &buff_size, 2);
	}
	free(clean);
	return (new);
}
