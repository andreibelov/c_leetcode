/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:31:21 by abelov            #+#    #+#             */
/*   Updated: 2024/08/20 11:31:22 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

int largestAltitude(const int *gain, int gainSize);

struct s_input
{
	int *gain;
	int gainSize;
	int expected;
};


int ft_do_test(struct s_input *input)
{
	int result;
	int check_val;
	ft_print_int_tab(input->gain, input->gainSize, NULL);

	result = largestAltitude(input->gain, input->gainSize);
	check_val = (input->expected == result);
	if (!check_val)
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   result, input->expected);
	check(check_val);
	return (0);
}

int main(void)
{
	int i;
	struct s_input inputs[] = {
		{
			.gainSize = 0,
			.expected = 0,
			.gain = (int[]) {},
		},
		{
			.gainSize = 5,
			.gain = (int[5]) {-5, 1, 5, 0, -7},
			.expected = 1
		},
		{
			.gainSize = 7,
			.gain = (int[7]) {-4,-3,-2,-1,4,3,2},
			.expected = 0
		}
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}

