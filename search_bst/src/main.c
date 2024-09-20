/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:18:04 by abelov            #+#    #+#             */
/*   Updated: 2024/09/06 14:18:04 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

typedef struct TreeNode TreeNode;

/**
 * 700. Search in a Binary Search Tree
 *
 * Constraints:
 * 	The number of nodes in the tree is in the range [1, 5000].
 * 	1 <= Node.val <= 107
 * 	root is a binary search tree.
 * 	1 <= val <= 107
 */
struct TreeNode* searchBST(struct TreeNode* root, int val);

struct s_input
{
	int *nums;
	int numsSize;
	int val;
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
	TreeNode *ans;
	int *result;
	int resultSize;
	int check_val;

	ft_print_int_tab_null(input->nums, input->numsSize, null, NULL);

	root = deserialize_level_order(input->nums, input->numsSize);
	print_tree(root);
	ans = searchBST(root, input->val);
	result = serialize_level_order(ans, &resultSize);
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
			ft_print_int_tab_null(result, resultSize, null, " whilst ");
			ft_print_int_tab_null(input->expected, input->expectedSize, null, "");
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
			.nums = (int[5]) {4,2,7,1,3},
			.numsSize = 5,
			.val = 2,
			.expected = (int[3]) {2,1,3},
			.expectedSize = 3
		},
		{
			.nums = (int[5]) {4,2,7,1,3},
			.numsSize = 5,
			.val = 5,
			.expected = (int[1]) {},
			.expectedSize = 0
		}
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
