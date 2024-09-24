/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 00:13:02 by abelov            #+#    #+#             */
/*   Updated: 2024/09/24 00:13:03 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 17. Letter Combinations of a Phone Number
 *
 * Constraints:
 * 	0 <= digits.length <= 4
 * 	digits[i] is a digit in the range ['2', '9'].
 */
char **letterCombinations(const char *digits, int *returnSize);

struct s_test_case
{
	const char *digits;
	StringArray	expected;
};

int ft_do_test(struct s_test_case *input)
{
	int i;
	char **result;
	int resultSize;
	int check_val;

	printf("\"%s\"\n", input->digits);

	result = letterCombinations(input->digits, &resultSize);
	check_val = (input->expected.size == resultSize);
	if (!check_val)
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   resultSize, input->expected.size);
	else
	{
		i = -1;
		while(++i < resultSize)
		{
			check_val = !strcmp(input->expected.arr[i], result[i]);
			if (!check_val) break;
		}

		if (!check_val)
		{
			printf("got ");
			ft_print_str_tab(result, resultSize, " whilst ");
			ft_print_str_tab(input->expected.arr, input->expected.size, "");
			printf(" was to be expected \n");
		}
	}
	check(check_val);
	i = -1;
	while (++i < resultSize)
		free(result[i]);
	free(result);
	return (0);
}

int main(void)
{
	int i;
	struct s_test_case cases[] = {
		{
			.digits = "23",
			.expected = {(char **) (const char *[9]) {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}, .size = 9}
		},
		{
			.digits = "",
			.expected = {(char **) (const char *[1]) {""}, .size = 0}
		},
		{
			.digits = "2",
			.expected = {(char **) (const char *[3]) {"a","b","c"}, .size = 3}
		}
	};
	size_t inputs_size = (sizeof(cases) / sizeof(cases[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&cases[i]);
	return (EXIT_SUCCESS);
}
