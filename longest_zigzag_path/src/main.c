/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 00:02:53 by abelov            #+#    #+#             */
/*   Updated: 2024/09/04 00:02:53 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

typedef struct TreeNode TreeNode;

/**
 * 1372. Longest ZigZag Path in a Binary Tree
 *
 * Zigzag length is defined as the number of nodes visited - 1.
 * (A single node has a length of 0).
 *
 * Return the longest ZigZag path contained in that tree.
 */
int longestZigZag(struct TreeNode *root);

struct s_input
{
	int *arr;
	int arrSize;
	int targetSum;
	int expected;
};

typedef struct s_stack_el
{
	TreeNode *node;
	int idx;
} stack_el;

static int ft_do_test(struct s_input *input)
{
	TreeNode *root;
	int result;
	int check_val;

	ft_print_int_tab_null(input->arr, input->arrSize, null, NULL);

	root = deserialize_level_order(input->arr, input->arrSize);
	print_tree(root);
	result = longestZigZag(root);
	check_val = (result == input->expected);
	if (!check_val)
	{
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   result, input->expected);
		check_val = false;
	}
	check(check_val);;
	free_tree(root);
	return (0);
}

int main(void)
{
	int i;
	struct s_input inputs[] = {
		{
			.arrSize = 0,
			.arr = (int[1]) {},
			.expected = 0
		},
		{
			.arrSize = 1,
			.arr = (int[1]) {1},
			.expected = 0
		},
		{
			.arrSize = 15,
			.arr = (int[15]) {1, null, 1, 1, 1, null, null, 1, 1, null, 1, null, null, null, 1},
			.expected = 3
		},
		{
			.arrSize = 11,
			.arr = (int[11]) {1, 1, 1, null, 1, null, null, 1, 1, null, 1},
			.expected = 4
		}
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);

	return (EXIT_SUCCESS);
}
