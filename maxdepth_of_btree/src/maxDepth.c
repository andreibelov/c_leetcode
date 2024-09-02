/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxDepth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:37:22 by abelov            #+#    #+#             */
/*   Updated: 2024/08/31 12:37:23 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

typedef struct TreeNode TreeNode;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
};

/**
 * 104. Maximum Depth of Binary Tree
 *
 * Given the root of a binary tree, return its maximum depth.
 * A binary tree's maximum depth is the number of nodes along
 * the longest path from the root node down to the farthest leaf node.
 */
int maxDepth(struct TreeNode *root);


#if defined USE_RECURSIVE

static inline int max(int a, int b)
{ return (a >= b ? a : b); }

int maxDepth(struct TreeNode *root)
{
	int ret_val = 0;
	int leftHeight;
	int rightHeight;

	if (root != NULL)
	{
		leftHeight = maxDepth(root->left);
		rightHeight = maxDepth(root->right);
		ret_val = max(leftHeight, rightHeight) + 1;
	}
	return (ret_val);
}
#else
#define MAX_STACK_SIZE 1000

typedef struct s_stack_el
{
	TreeNode *node;
	int depth;
} stack_el;

int maxDepth(struct TreeNode *root)
{
	int max_depth = 0;

	if (root == NULL) return (0);

	stack_el el;
	stack_el stack[MAX_STACK_SIZE];
	int sp = 0;

	stack[sp++] = (stack_el) {root, 1};

	while (sp)
	{
		el = stack[--sp];
		if (el.depth > max_depth) max_depth = el.depth;
		if (el.node->right != NULL)
			stack[sp++] = (stack_el) {el.node->right, el.depth + 1};
		if (el.node->left != NULL)
			stack[sp++] = (stack_el) {el.node->left, el.depth + 1};
	}
	return (max_depth);
}

#endif
