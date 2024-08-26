/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlpcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:17:35 by abelov            #+#    #+#             */
/*   Updated: 2024/08/26 21:17:35 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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
