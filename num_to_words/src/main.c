/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:59:49 by abelov            #+#    #+#             */
/*   Updated: 2024/08/27 01:52:54 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

char	*numberToWords(int num);

struct s_input
{
	const int 	num;
	const char	*expected;
};

int ft_do_test(struct s_input *input)
{
	char	*result;
	int		check_val;

	result = numberToWords(input->num);
	check_val = strcmp(input->expected, result);
	if (check_val)
		printf("got \"%s\" whilst \"%s\" was to be expected\n",
			   result, input->expected);
	check(!check_val);
	return (0);
}

int main(void)
{
	int				i;
	struct s_input	inputs[] = {
		{
			.num = 0,
			.expected = "Zero"
		},
		{
			.num = 1000000,
			.expected = "One Million"
		},
		{
			.num = 1000,
			.expected = "One Thousand"
		},
		{
			.num = 123,
			.expected = "One Hundred Twenty Three"
		},
		{
			.num = 12345,
			.expected = "Twelve Thousand Three Hundred Forty Five"
		},
		{
			.num = 1234567,
			.expected = "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
		},
		{
			.num = 1234567891,
			.expected = "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
		},
		{
			.num = 10,
			.expected = "Ten"
		},
		{
			.num = 7,
			.expected = "Seven"
		},
		{
			.num = 17,
			.expected = "Seventeen"
		},
		{
			.num = 20,
			.expected = "Twenty"
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
