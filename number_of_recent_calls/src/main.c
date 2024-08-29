/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:58:20 by abelov            #+#    #+#             */
/*   Updated: 2024/08/28 09:58:20 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

typedef struct rc RecentCounter;

/**
 * 933. Number of Recent Calls
 *
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 * recentCounterFree(obj);
*/
int recentCounterPing(RecentCounter *counter, int t);

RecentCounter *recentCounterCreate();

/* Function to free the memory used by the RecentCounter */
void recentCounterFree(RecentCounter *counter);

struct s_input
{
	int *array;
	int arraySize;
	int *expected;
	int expectedSize;
};

int ft_do_test(struct s_input *input)
{
	int i;
	int check_val;
	int resultSize = 0;
	int *result = (int *) malloc(input->arraySize * sizeof(int));

	RecentCounter *counter = recentCounterCreate();
	ft_print_int_tab(input->array, input->arraySize, NULL);
	i = -1;
	while (++i < input->arraySize)
		result[resultSize++] = recentCounterPing(counter, input->array[i]);
	if (input->expectedSize != resultSize)
	{
		printf("resultSize doesn't match expected value\n");
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   resultSize, input->expectedSize);
		check(false);
	}
	else
	{
		check_val = !memcmp(input->expected, result, input->expectedSize * sizeof(int));
		if (!check_val)
		{
			printf("got ");
			ft_print_int_tab(result, resultSize, " whilst ");
			ft_print_int_tab(input->expected, input->expectedSize, "");
			printf(" was to be expected \n");
		}
		check(check_val);
	}
	free(result);
	recentCounterFree(counter);
	return (0);
}

int main(void)
{
	int i;
	struct s_input inputs[] = {
		{
			.array = (int[]) {1, 100, 3001, 3002},
			.arraySize = 4,
			.expected = (int[]) {1, 2, 3, 3},
			.expectedSize = 4,
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
