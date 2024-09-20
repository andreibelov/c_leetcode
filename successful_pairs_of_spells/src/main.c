/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 21:52:01 by abelov            #+#    #+#             */
/*   Updated: 2024/09/20 21:52:02 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 2300. Successful Pairs of Spells and Potions
 *
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *successfulPairs(int *spells, int spellsSize,
					 int *potions, int potionsSize,
					 long long success, int *returnSize);

struct s_test_case
{
	Array spells;
	Array potions;
	long long success;
	Array expected;
};

typedef struct s_stack_el
{
	TreeNode *node;
	int idx;
} stack_el;

static int ft_do_test(struct s_test_case *input)
{
	Array result;
	int check_val;

	ft_print_int_tab_null(input->spells.arr, input->spells.size, null, NULL);
	ft_print_int_tab_null(input->potions.arr, input->potions.size, null, NULL);
	result.arr = successfulPairs(input->spells.arr, input->spells.size,
							 input->potions.arr, input->potions.size,
							 input->success, &result.size);
	check_val = (result.size == input->expected.size);
	if (!check_val)
	{
		printf("got \"%d\" elements whilst \"%d\" was to be expected\n",
			   result.size, input->expected.size);
	}
	else if (result.size != 0)
	{
		check_val = !memcmp(result.arr,
							input->expected.arr,
							(sizeof(int) * input->expected.size));
		if (!check_val)
		{
			printf("got ");
			ft_print_int_tab_null(result.arr, result.size, null, " whilst ");
			ft_print_int_tab_null(input->expected.arr, input->expected.size, null, "");
			printf(" was to be expected \n");
		}
	}
	free(result.arr);
	check(check_val);
	return (0);
}

int main(void)
{
	int i;
	struct s_test_case inputs[] = {
		{
			.spells = {(int[3]) {5,1,3}, .size = 3},
			.potions = {(int[5]) {1,2,3,4,5}, .size = 5},
			.success = 7,
			.expected = {(int[3]) {4,0,3}, .size = 3}
		},
		{
			.spells = {(int[3]) {15,8,19}, .size = 3},
			.potions = {(int[3]) {38,36,23}, .size = 3},
			.success = 328,
			.expected = {(int[3]) {3,0,3}, .size = 3}
		},
		{
			.spells = {(int[3]) {3,1,2}, .size = 3},
			.potions = {(int[3]) {8,5,8}, .size = 3},
			.success = 16,
			.expected = {(int[3]) {2,0,2}, .size = 3}
		},
		{
			.spells = {(int[7]) {1,2,3,4,5,6,7}, .size = 7},
			.potions = {(int[7]) {1,2,3,4,5,6,7}, .size = 7},
			.success = 25,
			.expected = {(int[7]) {0,0,0,1,3,3,4}, .size = 7}
		},
		{
			.spells = {(int[90]) {13,22,21,13,11,9,13,35,7,38,10,10,38,19,3,16,13,24,16,27,20,24,32,5,16,35,24,2,25,32,20,22,22,3,35,39,27,26,25,21,27,40,15,17,24,40,35,27,20,40,9,35,27,19,15,34,35,37,17,40,8,3,33,39,29,22,30,1,37,2,16,30,32,31,24,6,34,26,36,4,21,2,29,31,3,27,6,24,40,18}, .size = 90},
			.potions = {(int[59]) {33,16,35,14,26,23,23,2,37,23,15,20,25,34,23,29,4,18,26,24,16,37,15,11,33,24,12,13,7,24,3,26,1,3,38,33,19,3,34,22,30,39,18,7,21,4,33,18,39,5,34,14,32,5,20,22,5,25,15}, .size = 59},
			.success = 533,
			.expected = {(int[90]) {0,21,19,0,0,0,0,39,0,42,0,0,42,16,0,9,0,28,9,33,16,28,37,0,9,39,28,0,30,37,16,21,21,0,39,44,33,31,30,19,33,44,5,14,28,44,39,33,16,44,0,39,33,16,5,39,39,42,14,44,0,0,37,44,34,21,37,0,42,0,9,37,37,37,28,0,39,31,42,0,19,0,34,37,0,33,0,28,44,15}, .size = 90}
		}
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
