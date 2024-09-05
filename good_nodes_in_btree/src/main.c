/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 02:13:32 by abelov            #+#    #+#             */
/*   Updated: 2024/09/02 02:13:33 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

#define MAX_STACK_SIZE 10000

/**
 * 1448. Count Good Nodes in Binary Tree
 *
 * Constraints:
 * 	The number of nodes in the binary tree is in the range [1, 10^5].
 * 	Each node's value is between [-10^4, 10^4].
 */
int goodNodes(struct TreeNode* root);

struct s_input
{
	int *arr;
	int arrSize;
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
	TreeNode *root;
	int result;
	int check_val;

	ft_print_int_tab_null(input->arr, input->arrSize, null, NULL);
	root = deserialize_level_order(input->arr, input->arrSize);

	result = goodNodes(root);
	check_val = (result == input->expected);
	if (!check_val)
	{
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   result, input->expected);
		check_val = false;
	}
	check(check_val);
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
			.arrSize = 7,
			.arr = (int[7]) {3,1,4,3,null,1,5},
			.expected = 4
		},
		{
			.arrSize = 5,
			.arr = (int[5]) {3,3,null,4,2},
			.expected = 3
		},
		{
			.arrSize = 1,
			.arr = (int[1]) {1},
			.expected = 1
		}
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
