/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numberToWords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:59:53 by abelov            #+#    #+#             */
/*   Updated: 2024/08/07 11:59:54 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>

const char *belowHundred[] = {
	"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};
const char *belowTwenty[] = {
	"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};
const char *belowTen[] = {
	"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"
};

const char *convertToWords(int nb, const char **wstack, size_t *curr)
{
	int stack[20];
	int stack_size = 0;

	stack[stack_size++] = nb;
	while (stack_size)
	{
		nb = stack[--stack_size];
		if (nb >= 10)
		{
			stack[stack_size++] = nb % 10;
			stack[stack_size++] = nb / 10;
		}
		else if (nb)
		{
			if (stack_size == 0)
				wstack[(*curr)++] = belowTen[nb];
			if (stack_size == 1)
			{
				if (nb == 1)
					wstack[(*curr)++] = belowTwenty[((nb * 10) + stack[--stack_size] - 10)];
				else
					wstack[(*curr)++] = belowHundred[nb];
			}
			if (stack_size == 2)
			{
				wstack[(*curr)++] = belowTen[nb];
				wstack[(*curr)++] = "Hundred";
			}
		}
	}
	return (NULL);
}

char *numberToWords(int num)
{
	static char str[120] = {0};
	int stack[20];
	int stack_size = 0;
	static const char *group[] = { "", "Thousand", "Million", "Billion" };
	size_t last;
	const char *word = NULL;
	const char *wstack[25];
	size_t curr = 0;
	size_t i = 0;

	*str = '\0';
	if (num == 0)
		strcpy(str, "Zero");
	else
	{
		stack[stack_size++] = num;
		while (stack_size)
		{
			num = stack[--stack_size];
			if (num >= 1000)
			{
				stack[stack_size++] = num % 1000;
				stack[stack_size++] = num / 1000;
			}
			else if (num)
			{
				convertToWords(num, wstack, &curr);
				wstack[curr++] = group[stack_size];
			}
		}
	}
	while (i < curr)
	{
		word = wstack[i++];
		if (strlen(word) != 0)
		{
			strcat(str, word);
			strcat(str, " ");
		}
	}
	last = strlen(str) - 1;
	if (str[last] == ' ')
		str[last] = '\0';
	return (str);
}
