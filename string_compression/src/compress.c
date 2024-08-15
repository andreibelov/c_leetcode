/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:33:43 by abelov            #+#    #+#             */
/*   Updated: 2024/08/15 11:33:44 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <limits.h>

char	*put_nbr(char *ptr, unsigned int nbr)
{
	unsigned int	stack[20];
	unsigned int	stack_size = 0;

	stack[stack_size++] = nbr;
	while (stack_size)
	{
		nbr = stack[--stack_size];
		if (nbr >= 10)
		{
			stack[stack_size++] = nbr % 10;
			stack[stack_size++] = nbr / 10;
		}
		else
			*ptr++ = (char) ('0' + nbr);
	}
	return (ptr);
}

int compress(char *chars, int charsSize)
{
	unsigned int	tab[2000] = {0};
	unsigned char 	stack[2000];
	int 			stackSize = 0;
	int				i;
	char			*ptr = chars;
	unsigned char	c;

	i = -1;
	if (charsSize > 0)
	{
		tab[stackSize]++;
		stack[stackSize++] = chars[++i];
	}
	while (++i < charsSize)
	{
		c = chars[i];
		if (c == stack[stackSize - 1])
			tab[stackSize - 1]++;
		else
		{
			tab[stackSize]++;
			stack[stackSize++] = c;
		}
	}
	i = -1;
	while (++i < stackSize)
	{
		*ptr++ = (char)stack[i];
		if (tab[i] > 1)
			ptr = put_nbr(ptr, tab[i]);
	}
	return ((int)(ptr - chars));
}
