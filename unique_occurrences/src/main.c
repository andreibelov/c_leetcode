/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:37:02 by abelov            #+#    #+#             */
/*   Updated: 2024/08/22 12:37:04 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

bool	uniqueOccurrences(int *arr, int arrSize);

struct s_input
{
	int *arr;
	int arrSize;
	bool expected;
};

int ft_do_test(struct s_input *input)
{
	int result;
	int check_val;
	ft_print_int_tab(input->arr, input->arrSize, NULL);

	result = uniqueOccurrences(input->arr, input->arrSize);
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
			.arrSize = 0,
			.expected = true,
			.arr = (int[]) {},
		},
		{
			.arrSize = 6,
			.arr = (int[6]) {1,2,2,1,1,3},
			.expected = true
		},
		{
			.arrSize = 2,
			.arr = (int[2]) {1,2},
			.expected = false
		},
		{
			.arrSize = 10,
			.arr = (int[10]) {-3,0,1,-3,1,1,1,-3,10,0},
			.expected = true
		}
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
