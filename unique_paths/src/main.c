/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:33:30 by abelov            #+#    #+#             */
/*   Updated: 2025/01/08 16:33:31 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 62. Unique Paths
 *
 * Given the two integers m and n, return the number of possible unique paths
 * that the robot can take to reach the bottom-right corner.
 *
 * The test cases are generated so that the answer will be less than or equal
 * to 2 * 10^9.
 *
 * Constraints:
 * 	1 <= m, n <= 100
 */
int uniquePaths(int m, int n);

typedef struct s_test_case
{
	Point	point;
	int		expected;
} Input;


int ft_do_test(Input *input)
{
	int result;
	int check_val;

	result = uniquePaths(input->point.x, input->point.y);
	check_val = (input->expected == result);
	if (!check_val)
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   result, input->expected);
	check(check_val);
	return (0);
}

int main(void)
{
	Input cases[] = {
		{
			.point = {0, 0},
			.expected = 0
		},
		{
			.point = {1, 1},
			.expected = 1
		},
		{
			.point = {3, 3},
			.expected = 6
		},
		{
			.point = {3, 7},
			.expected = 28
		},
		{
			.point = {3, 2},
			.expected = 3
		},
		{
			.point = {10, 10},
			.expected = 48620
		},
		{
			.point = {23, 12},
			.expected = 193536720
		},
	};
	int i;
	size_t inputs_size = (sizeof(cases) / sizeof(cases[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&cases[i]);
	return (EXIT_SUCCESS);
}
