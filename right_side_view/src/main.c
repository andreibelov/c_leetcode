/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 23:47:35 by abelov            #+#    #+#             */
/*   Updated: 2024/09/05 23:47:36 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

typedef struct TreeNode TreeNode;

/**
 * 199. Binary Tree Right Side View
 *
 * Constraints:
 * 	The number of nodes in the tree is in the range [0, 100].
 * 	-100 <= Node.val <= 100
 */
int *rightSideView(struct TreeNode *root, int *returnSize);

struct s_input
{
	int *nums;
	int numsSize;
	int *expected;
	int expectedSize;
};

typedef struct s_stack_el
{
	TreeNode *node;
	int idx;
} stack_el;

static int ft_do_test(struct s_input *input)
{
	TreeNode *root;
	int *result;
	int resultSize;
	int check_val;

	ft_print_int_tab_null(input->nums, input->numsSize, null, NULL);

	root = deserialize_level_order(input->nums, input->numsSize);
	print_tree(root);
	result = rightSideView(root, &resultSize);
	check_val = (resultSize == input->expectedSize);
	if (!check_val)
	{
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   resultSize, input->expectedSize);
	}
	else if (resultSize != 0)
	{
		check_val = !memcmp(result,
						   input->expected,
						   (sizeof(int) * input->expectedSize));
		if (!check_val)
		{
			printf("got ");
			ft_print_int_tab(result, resultSize, " whilst ");
			ft_print_int_tab(input->expected, input->expectedSize, "");
			printf(" was to be expected \n");
		}
	}
	free(result);
	check(check_val);
	free_tree(root);
	return (0);
}

int main(void)
{
	int i;
	struct s_input inputs[] = {
		{
			.nums = (int[7]) {1,2,3,null,5,null,4},
			.numsSize = 7,
			.expected = (int[3]) {1,3,4},
			.expectedSize = 3
		},
		{
			.nums = (int[3]) {1,null,3},
			.numsSize = 3,
			.expected = (int[3]) {1,3},
			.expectedSize = 2
		},
		{
			.numsSize = 0,
			.nums = (int[]) {0},
			.expected = (int[]) {0},
			.expectedSize = 0
		},
		{
			.numsSize = 2,
			.nums = (int[2]) {1,2},
			.expected = (int[2]) {1,2},
			.expectedSize = 2
		},
		{
			.numsSize = 4,
			.nums = (int[4]) {1,2,3,4},
			.expected = (int[3]) {1,3,4},
			.expectedSize = 3
		},
		{
			.numsSize = 8,
			.nums = (int[8]) {1,2,3,null,5,6,null,4},
			.expected = (int[4]) {1,3,6,4},
			.expectedSize = 4
		}
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);

	return (EXIT_SUCCESS);
}
