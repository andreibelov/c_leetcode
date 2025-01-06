/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:09:59 by abelov            #+#    #+#             */
/*   Updated: 2025/01/06 19:10:01 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 739. Daily Temperatures
 *
 * Given an array of integers temperatures represents the daily temperatures,
 * return an array answer such that answer[i] is the number of days you have to
 * wait after the ith day to get a warmer temperature.
 * If there is no future day for which this is possible,
 * keep answer[i] == 0 instead.
 *
 * Constraints:
 * 	1 <= temperatures.length <= 105
 * 	30 <= temperatures[i] <= 100
 */
int *dailyTemperatures(int *temperatures, int temperaturesSize, int *returnSize);

typedef struct s_input
{
	Array temperatures;
	Array expected;
} Input;

int ft_do_test(Input *input)
{
	Array *temperatures;
	Array result = {0};
	int check_val;

	temperatures = &input->temperatures;
	result.arr = dailyTemperatures(temperatures->arr,
								   temperatures->size,
								   &result.size);

	check_val = (input->expected.size == result.size);
	if (!check_val)
	{
		printf("resultTotalSize doesn't match expected value\n");
		printf("got array of size [\"%d\"] whilst \"%d\" was to be expected\n",
			   result.size, input->expected.size);
	}
	else
	{
		check_val = (arraycmp(&result, &input->expected) == 0);
		if (!check_val)
		{
			check(check_val);
			printf("got ");
			ft_print_array(&result, " whilst ");
			ft_print_array(&input->expected, "");
			printf(" was to be expected \n");
		}
	}
	check(check_val);
	free(result.arr);
	return (0);
}

int main(void)
{
	int i;
	Input inputs[] = {
		{
			.temperatures = (Array) {.arr = (int[8]) {73,74,75,71,69,72,76,73}, .size = 8},
			.expected = (Array) {.arr = (int[8]) {1,1,4,2,1,1,0,0}, .size = 8}
		},
		{
			.temperatures = (Array) {.arr = (int[4]) {30,40,50,60}, .size = 4},
			.expected = (Array) {.arr = (int[4]) {1,1,1,0}, .size = 4}
		},
		{
			.temperatures = (Array) {.arr = (int[]) {30,60,90}, .size = 3},
			.expected = (Array) {.arr = (int[]) {1,1,0}, .size = 3}
		},
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
