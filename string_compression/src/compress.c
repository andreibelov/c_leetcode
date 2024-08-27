/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:33:43 by abelov            #+#    #+#             */
/*   Updated: 2024/08/27 13:53:29 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * 443. String Compression
 *
 * Given an array of characters chars,
 * compress it using the following algorithm:
 * 	Begin with an empty string s.
 * 	For each group of consecutive repeating characters in chars:
 * 		If the group's length is 1, append the character to s.
 * 		Otherwise, append the character followed by the group's length.
 * The compressed string s should not be returned separately, but instead,
 * be stored in the input character array chars.
 *
 * Note that group lengths that are 10 or longer will be split into multiple
 * characters in chars.
 * After you are done modifying the input array,
 * return the new length of the array.
 *
 * An algorithm should use only constant extra space.
 */
int compress(char *chars, int charsSize);

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
