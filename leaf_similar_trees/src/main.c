/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:37:01 by abelov            #+#    #+#             */
/*   Updated: 2024/08/31 12:37:02 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

#define MAX_STACK_SIZE 10000

/**
 * 872. Leaf-Similar Trees
 *
 * Constraints:
 * 	The number of nodes in each tree will be in the range [1, 200].
 * 	Both of the given trees will have values in the range [0, 200].
 */
unsigned char leafSimilar(struct TreeNode* root1, struct TreeNode* root2);

struct s_input
{
	int *serTree1;
	int serTree1Size;
	int *serTree2;
	int serTree2Size;
	int expected;
};

typedef struct s_stack_el
{
	TreeNode *node;
	int idx;
} stack_el;

void free_tree(TreeNode *root)
{
	TreeNode *node;
	TreeNode *stack[MAX_STACK_SIZE];
	int stackSize = 0;

	if (root == NULL) return;

	stack[stackSize++] = root;

	while (stackSize != 0)
	{
		node = stack[--stackSize];
		if (node->right != NULL)
			stack[stackSize++] = node->right;
		if (node->left != NULL)
			stack[stackSize++] = node->left;
		free(node);
	}
}

TreeNode *getTree(const int *arr, int size)
{
	TreeNode *root;
	TreeNode *node;
	int left_index;
	int right_index;

	int sp = 0;
	stack_el el;
	stack_el stack[MAX_STACK_SIZE];

	/* Edge case for an empty tree */
	if (size == 0 || arr[0] == -1)
		return NULL;

	root = new_node(arr[0]);

	stack[sp++] = (stack_el) {root, 0};
	while (sp != 0)
	{
		el = stack[--sp];  // Pop the stack

		node = el.node;
		left_index = 2 * el.idx + 1;
		right_index = 2 * el.idx + 2;

		if (left_index < size && arr[left_index] != null)
		{
			node->left = new_node(arr[left_index]);
			stack[sp++] = (stack_el) {node->left, left_index};
		}

		if (right_index < size && arr[right_index] != null)
		{
			node->right = new_node(arr[right_index]);
			stack[sp++] = (stack_el) {node->right, right_index};
		}
	}
	return (root);
}

static int ft_do_test(struct s_input *input)
{
	TreeNode *root1;
	TreeNode *root2;
	int result;
	int check_val;

	ft_print_int_tab_null(input->serTree1, input->serTree1Size, null, "\n");
	ft_print_int_tab_null(input->serTree2, input->serTree2Size, null, "\n");

	root1 = deserialize_level_order(input->serTree1, input->serTree1Size);
	root2 = deserialize_level_order(input->serTree2, input->serTree2Size);

	print_tree(root1);
	printf("===================\n");
	print_tree(root2);

	result = leafSimilar(root1, root2);
	check_val = (result == input->expected);
	if (!check_val)
	{
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   result, input->expected);
		check_val = false;
	}
	check(check_val);
	free_tree(root1);
	free_tree(root2);
	return (0);
}

int main(void)
{
	int i;
	struct s_input inputs[] = {
		{
			.serTree1 = (int[11]) {3,5,1, 6,2,9, 8,null,null, 7,4},
			.serTree1Size = 11,
			.serTree2 = (int[15]) {3,5,1,6,7,4,2,null,null,null,null,null,null,9,8},
			.serTree2Size = 15,
			.expected = 1
		},
		{
			.serTree1 = (int[3]) {1,2,3},
			.serTree1Size = 3,
			.serTree2 = (int[3]) {1,3,2},
			.serTree2Size = 3,
			.expected = 0
		},
		{
			.serTree1 = (int[19]) {3,5,1,6,7,4,2,null,null,null,null,null,null,9,11,null,null,8,10},
			.serTree1Size = 19,
			.serTree2 = (int[11]) {3,5,1,6,2,9,8,null,null,7,4},
			.serTree2Size = 11,
			.expected = 0
		}
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
