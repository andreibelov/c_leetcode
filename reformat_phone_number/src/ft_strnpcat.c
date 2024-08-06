/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnpcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 00:02:29 by abelov            #+#    #+#             */
/*   Updated: 2024/08/07 00:02:31 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stddef.h>

/**
 * https://www.joelonsoftware.com/2001/12/11/back-to-basics/
 */
char	*ft_strnpcat(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (*dest)
		dest++;
	while (*src && (i++ < n))
		*dest++ = *src++;
	while (i++ < n)
		*dest++ = '\0';
	return (--dest);
}