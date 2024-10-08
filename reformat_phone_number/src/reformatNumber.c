/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reformatNumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 23:57:06 by abelov            #+#    #+#             */
/*   Updated: 2024/08/06 23:57:07 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * 1694. Reformat Phone Number
 *
 * Given is a phone number as a string number.
 * Number consists of digits, spaces ' ', and/or dashes '-'.
 * reformatNumber() reformats the phone number so that is removes all spaces
 * and dashes. Then, groups the digits from left to right into blocks
 * of length 3 until there are 4 or fewer digits.
 * The final digits are then grouped.
 */
char	*reformatNumber(char *s);

#if !defined USE_STRNLPCAT

static char	*ft_strnlpcat(char *dest, const char *src, size_t *dst_size, size_t n)
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

size_t	cleanup(char *s)
{
	char	*tmp;
	char	c;
	char *const optr = s;

	tmp = s;
	while (*s)
	{
		c = *s++;
		if(isdigit(c)) *tmp++ = c;
	}
	*tmp = '\0';
	return (tmp - optr);
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
char	*reformatNumber(char *s)
{
	char	*p;
	char	*new;
	int 	i;
	char	*clean = s;
	size_t	len = cleanup(s);
	size_t	buff_size = len + (len / 3) +  1;

	new = (char *)malloc(buff_size * sizeof(char));
	if (!new)
		return (NULL);
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
	return (new);
}

#else

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	size_t	buff_size;
	const size_t len1 = strlen(s1);
	const size_t len2 = strlen(s2);

	buff_size = len1 + len2 + 1;
	new = (char *)malloc(buff_size);
	if (!new)
		return (NULL);
	*new = '\0';
	strncpy(new, s1, buff_size);
	strncat(new, s2, buff_size);
	free((void *)s1);
	return (new);
}

char	*reformatNumber(char *s)
{
	char	*new;
	char	*tmp;
	char	*p;
	char	c;
	size_t	len;
	int 	i;

	if (!s)
		return (NULL);
	len = strlen(s);
	new = (char *)malloc(len * sizeof(char) + 1);
	if (!new)
		return (NULL);
	new[0] = '\0';
	tmp = new;
	while (*s)
	{
		c = *s++;
		if(!strchr(" -", c))
			*new++ = c;
	}
	*new = '\0';
	len = new - tmp;
	new = tmp;
	i = 0;
	tmp = strdup("");
	if (len <= 1)
		tmp = (free(tmp), NULL);
	if (len > 4)
	{

		while (len > 4)
		{
			p = strndup(new + i, 3);
			tmp = ft_strjoin(tmp, p);
			tmp = ft_strjoin(tmp, "-");
			free(p);
			len -= 3;
			i += 3;
		}
	}
	if (len == 2 || len == 3)
		tmp = ft_strjoin(tmp, new + i);
	else if (len == 4)
	{
		p = strndup(new + i, 2);
		tmp = ft_strjoin(tmp, p);
		free(p);
		tmp = ft_strjoin(tmp, "-");
		p = strndup(new + i + 2, 2);
		tmp = ft_strjoin(tmp, p);
		free(p);
	}
	free(new);
	return (tmp);
}
#endif
