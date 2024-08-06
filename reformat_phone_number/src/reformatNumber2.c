/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reformatNumber2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 23:57:06 by abelov            #+#    #+#             */
/*   Updated: 2024/08/07 00:00:05 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>

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

/**
 * Given is a phone number as a string number.
 * Number consists of digits, spaces ' ', and/or dashes '-'.
 * reformatNumber() reformats the phone number so that is removes all spaces
 * and dashes. Then, groups the digits from left to right into blocks
 * of length 3 until there are 4 or fewer digits.
 * The final digits are then grouped.
 * Return the phone number after formatting.
 */
char	*reformatNumber2(char *s)
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
