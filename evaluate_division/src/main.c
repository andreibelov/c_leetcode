/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:45:37 by abelov            #+#    #+#             */
/*   Updated: 2025/01/06 11:45:37 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 399. Evaluate Division
 *
 * You are given an array of variable pairs equations and
 * an array of real numbers values, where equations[i] = [Ai, Bi] and values[i]
 * represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string
 * that represents a single variable.
 *
 * You are also given some queries, where queries[j] = [Cj, Dj] represents
 * the jth query where you must find the answer for Cj / Dj = ?.
 *
 * Return the answers to all queries.
 * If a single answer cannot be determined, return -1.0.
 *
 * Constraints:
 * 	1 <= equations.length <= 20
 *  equations[i].length == 2
 *  1 <= Ai.length, Bi.length <= 5
 *  values.length == equations.length
 *  0.0 < values[i] <= 20.0
 *  1 <= queries.length <= 20
 *  queries[i].length == 2
 *  1 <= Cj.length, Dj.length <= 5
 *  Ai, Bi, Cj, Dj consist of lower case English letters and digits.
 */
double *calcEquation(char ***equations, int equationsSize,
					 const int *equationsColSize, const double *values,
					 int valuesSize, char ***queries, int queriesSize,
					 const int *queriesColSize, int *returnSize);

typedef struct s_input
{
	StringArrays	equations;
	StringArrays	queries;
	ArrayDouble 	values;
	ArrayDouble 	expected;
}	Input;

int ft_do_test(Input *input)
{
	ArrayDouble result = {0};
	int check_val;

	char ***equations = (char ***) alloca(input->equations.size * sizeof(char **));
	int *equationsColSize = (int *) alloca(input->equations.size * sizeof(int));

	char ***queries = (char ***) alloca(input->queries.size * sizeof(char **));
	int *queriesColSize = (int *) alloca(input->queries.size * sizeof(int));

	while (input->equations.ss < input->equations.size)
	{
		equationsColSize[input->equations.ss] = input->equations.arrays[input->equations.ss].size;
		equations[input->equations.ss] = input->equations.arrays[input->equations.ss].arr;
		input->equations.ss++;
	}

	while (input->queries.ss < input->queries.size)
	{
		queriesColSize[input->queries.ss] = input->queries.arrays[input->queries.ss].size;
		queries[input->queries.ss] = input->queries.arrays[input->queries.ss].arr;
		input->queries.ss++;
	}

	result.arr = calcEquation(equations, input->equations.size,
							  equationsColSize, input->values.arr,
							  input->values.size, queries, input->queries.size,
							  queriesColSize, &result.size);

	check_val = (input->expected.size == result.size);
	if (!check_val)
	{
		printf("resultTotalSize doesn't match expected value\n");
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   result.size, input->expected.size);
	}
	else
	{
		check_val = (darraycmp(&result, &input->expected) == 0);
		if (!check_val)
		{
			printf("got ");
			ft_print_darray(&result, " whilst ");
			ft_print_darray(&input->expected, "");
			printf(" was to be expected \n");
		}
		free(result.arr);
	}

	check(check_val);

	return (0);
}

int main(void)
{
	int i;
	struct s_input inputs[] = {
		{
			.equations = (StringArrays) {
				.arrays = (StringArray[]) {
					{.arr = (char **) (const char *[2]) {"a","b"}, .size = 2},
					{.arr = (char **) (const char *[2]) {"b","c"}, .size = 2},
				},
				.size = 2
			},
			.values = {(double []){2.0,3.0}, 2, .ss = 0},
			.queries = (StringArrays) {
				.arrays = (StringArray[]) {
					{.arr = (char **) (const char *[2]) {"a","c"}, .size = 2},
					{.arr = (char **) (const char *[2]) {"b","a"}, .size = 2},
					{.arr = (char **) (const char *[2]) {"a","e"}, .size = 2},
					{.arr = (char **) (const char *[2]) {"a","a"}, .size = 2},
					{.arr = (char **) (const char *[2]) {"x","x"}, .size = 2},
				},
				.size = 5
			},
			.expected = {(double []){6.00000,0.50000,-1.00000,1.00000,-1.00000}, 5, .ss = 0},
		},
		{
			.equations = (StringArrays) {
				.arrays = (StringArray[]) {
					{.arr = (char **) (const char *[2]) {"a","b"}, .size = 2},
					{.arr = (char **) (const char *[2]) {"b","c"}, .size = 2},
					{.arr = (char **) (const char *[2]) {"bc","cd"}, .size = 2},
				},
				.size = 3
			},
			.values = {(double [3]){1.5,2.5,5.0}, 3, .ss = 0},
			.queries = (StringArrays) {
				.arrays = (StringArray[]) {
					{.arr = (char **) (const char *[2]) {"a","c"}, .size = 2},
					{.arr = (char **) (const char *[2]) {"c","b"}, .size = 2},
					{.arr = (char **) (const char *[2]) {"bc","cd"}, .size = 2},
					{.arr = (char **) (const char *[2]) {"cd","bc"}, .size = 2},
				},
				.size = 4
			},
			.expected = {(double []){3.75000,0.40000,5.00000,0.20000}, 4, .ss = 0},
		},
		{
			.equations = (StringArrays) {
				.arrays = (StringArray[]) {
					{.arr = (char **) (const char *[2]) {"a","b"}, .size = 2},
				},
				.size = 1
			},
			.values = {(double [1]){0.5}, 1, .ss = 0},
			.queries = (StringArrays) {
				.arrays = (StringArray[]) {
					{.arr = (char **) (const char *[2]) {"a","b"}, .size = 2},
					{.arr = (char **) (const char *[2]) {"b","a"}, .size = 2},
					{.arr = (char **) (const char *[2]) {"a","c"}, .size = 2},
					{.arr = (char **) (const char *[2]) {"x","y"}, .size = 2},
				},
				.size = 4
			},
			.expected = {(double []){0.50000,2.00000,-1.00000,-1.00000}, 4, .ss = 0},
		},
	};
	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}

