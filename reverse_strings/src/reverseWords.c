/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseWords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:59:05 by abelov            #+#    #+#             */
/*   Updated: 2024/08/12 22:59:06 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*reverseWords(char *s)
{
	char	*stack[100000] = {0};
	static char	buf[1000000] = {0};
	int		stackSize = 0;
	char	*str;
	char	*save_ptr;

	str = strtok_r(s, " ", &save_ptr);
	if (str)
		stack[stackSize++] = str;
	while(*save_ptr)
	{
		str = strtok_r(NULL, " ", &save_ptr);
		if (str)
			stack[stackSize++] = str;
	}
	*buf = '\0';
	if (stackSize != 0)
		strcat(buf, stack[--stackSize]);
	while (stackSize)
	{
		strcat(buf, " ");
		strcat(buf, stack[--stackSize]);
	}
	return (buf);
}