/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 01:02:30 by abelov            #+#    #+#             */
/*   Updated: 2024/09/05 01:02:30 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

typedef struct TreeNode TreeNode;

/**
 * 236. Lowest Common Ancestor of a Binary Tree
 *
 * Constraints:
 * 	The number of nodes in the tree is in the range [2, 105].
 * 	-109 <= Node.val <= 109
 * 	All Node.val are unique.
 * 	p != q
 * 	p and q will exist in the tree.
 */
struct TreeNode *lowestCommonAncestor(struct TreeNode *root,
									  struct TreeNode *p, struct TreeNode *q);
struct s_input
{
	int *arr;
	int arrSize;
	int p;
	int q;
	int expected;
};

typedef struct s_stack_el
{
	TreeNode *node;
	int idx;
} stack_el;

static struct TreeNode *find_node(int to_find, struct TreeNode *root)
{
	int sp = 0;
	struct TreeNode *stack[MAX_STACK_SIZE];
	struct TreeNode *node;

	if (root) stack[sp++] = root;
	while (sp)
	{
		node = stack[--sp];
		if (node->val == to_find) return node;
		if (node->right) stack[sp++] = node->right;
		if (node->left) stack[sp++] = node->left;
	}
	return NULL;
}


static int ft_do_test(struct s_input *input)
{
	TreeNode *root;
	TreeNode *found;
	int result = 0;
	int check_val;

	ft_print_int_tab_null(input->arr, input->arrSize, null, NULL);

	root = deserialize_level_order(input->arr, input->arrSize);
	print_tree(root);

	found = lowestCommonAncestor(root,
								  find_node(input->p, root),
								  find_node(input->q, root));
	if (found) result = found->val;
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
			.p = 1,
			.q = 2,
			.expected = 0
		},
		{
			.arrSize = 2,
			.arr = (int[2]) {1, 2},
			.p = 1,
			.q = 2,
			.expected = 1
		},
		{
			.arrSize = 11,
			.arr = (int[11]) {3,5,1,6,2,0,8,null,null,7,4},
			.p = 5,
			.q = 1,
			.expected = 3
		},
		{
			.arrSize = 11,
			.arr = (int[11]) {3,5,1,6,2,0,8,null,null,7,4},
			.p = 5,
			.q = 4,
			.expected = 5
		},
		{
			.arrSize = 8,
			.arr = (int[8]) {-1,0,3,-2,4,null,null,8},
			.p = 3,
			.q = 8,
			.expected = -1
		},
		{
			.arrSize = 19,
			.arr = (int[19]) {37,-34,-48,null,-100,-101,48,null,null,null,null,-54,null,-71,-22,null,null,null,8},
			.p = -71,
			.q = 8,
			.expected = -54
		}
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);

	return (EXIT_SUCCESS);
}
