/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:25:20 by abelov            #+#    #+#             */
/*   Updated: 2024/08/18 14:25:21 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

int maxVowels(const char *s, int k);

struct s_input
{
	const char	*str;
	const int	k;
	const int	expected;
};

int ft_do_test(const struct s_input *const input)
{
	int	result;
	int	check_val;

	printf("%s\n", input->str);
	result = maxVowels(input->str, input->k);
	check_val = (result != input->expected);
	if (check_val)
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   result, input->expected);
	check(!check_val);
	return (0);
}

int main(void)
{
	int				i;
	struct s_input	inputs[] = {
		{
			.k = 3,
			.str = "abciiidef",
			.expected = 3
		},
		{
			.k = 2,
			.str = "aeiou",
			.expected = 2
		},
		{
			.k = 3,
			.str = "leetcode",
			.expected = 2
		},
		{
			.k = 4,
			.str = "rhythms",
			.expected = 0
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
