/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:10:00 by abelov            #+#    #+#             */
/*   Updated: 2024/09/25 00:10:01 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 216. Combination Sum III
 *
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 *
 * Note: Both returned array and *columnSizes array must be malloced,
 * assume caller calls free().
 *
 * Constraints:
 * 	2 <= k <= 9
 * 	1 <= n <= 60
 */
int **combinationSum3(int k, int n, int *returnSize, int **returnColumnSizes);

struct s_test_case
{
	int k;
	int n;
	TwoDArray	expected;
};

int ft_do_test(struct s_test_case *testcase)
{
	int i;
	int *sizes;
	int **arrays;
	Array pool[1024];

	TwoDArray res = {0};
	int check_val;

	res.arrays = pool;

	arrays = combinationSum3(testcase->k, testcase->n,
							 &res.size, &sizes);
	i = -1;
	while (++i < res.size)
		res.arrays[i] = (Array) {.arr = arrays[i], .size = sizes[i], .iter = 0};

	check_val = (res.size == testcase->expected.size);
	if (!check_val)
	{
		printf("got \"%d\" elements whilst \"%d\" was to be expected\n",
			   res.size, testcase->expected.size);
	}
	else if (res.size != 0)
	{
		i = -1;
		while(++i < res.size)
		{
			Array *p = &res.arrays[i];
			Array *q = &testcase->expected.arrays[i];
			check_val = (arraycmp(p, q) == 0);
			if (!check_val)
			{
				check(check_val);
				printf("at index [%d] got ", i);
				ft_print_array(p, " whilst ");
				ft_print_array(q, "");
				printf(" was to be expected \n");
				free(p->arr);
				while(++(i) < res.size)
					free(res.arrays[i].arr);
				break;
			}
			free(p->arr);
		}
	}
	if (check_val)
		check(check_val);
	free(arrays);
	return (0);
}

int main(void)
{
	int i;
	struct s_test_case cases[] = {
		{
			.k = 3,
			.n = 7,
			.expected = (TwoDArray){
				.arrays = (Array [1]){
					{(int [3]){1,2,4}, .size = 3}
				},
				.size = 1
			}
		},
		{
			.k = 3,
			.n = 9,
			.expected = (TwoDArray){
				.arrays = (Array [3]){
					{(int [3]){2,3,4}, .size = 3},
					{(int [3]){1,3,5}, .size = 3},
					{(int [3]){1,2,6}, .size = 3}
				},
				.size = 3
			}
		},
		{
			.k = 4,
			.n = 1,
			.expected = (TwoDArray){
				.arrays = (Array [1]){ {(int [1]){}, .size = 0}},
				.size = 0
			}
		},
	};
	size_t inputs_size = (sizeof(cases) / sizeof(cases[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&cases[i]);
	return (EXIT_SUCCESS);
}
