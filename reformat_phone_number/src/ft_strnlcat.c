/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 00:02:50 by abelov            #+#    #+#             */
/*   Updated: 2024/08/07 00:02:51 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>

size_t	ft_strnlcat(char *dest, const char *src, size_t dst_size, size_t n)
{
	const size_t		osize = dst_size;
	char *const			odest = dest;
	const char *const	osrc = src;
	size_t				dest_len;
	size_t				i;

	while (*dest && dst_size--)
		dest++;
	dest_len = dest - odest;
	if (dest_len >= osize)
		return (osize + strlen(src));
	i = 0;
	if (dst_size > 0)
	{
		while ((1 < dst_size--) && *src && (i++ < n))
			*dest++ = *src++;
		while ((1 < dst_size--) && (i++ < n))
			*dest++ = '\0';
		*dest = '\0';
	}
	while (*src)
		src++;
	return ((dest_len + (src - osrc)));
}
