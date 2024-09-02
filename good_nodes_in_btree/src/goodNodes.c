/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goodNodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 02:14:21 by abelov            #+#    #+#             */
/*   Updated: 2024/09/02 02:14:22 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/**
 * 1448. Count Good Nodes in Binary Tree
 *
 * Given a binary tree root, a node X in the tree is named good if in the path
 * from root to X there are no nodes with a value greater than X.
 *
 * Return the number of good nodes in the binary tree.
 */
int goodNodes(struct TreeNode* root);

#define MAX_STACK_SIZE 1000

typedef struct TreeNode TreeNode;

typedef struct s_stack_el
{
	TreeNode *node;
	int mx;
} stack_el;

int goodNodes(struct TreeNode* root)
{
	int mx = -1000000;
	int count = 0;
	stack_el el;
	stack_el stack[MAX_STACK_SIZE];
	int sp = 0;

	if (root == NULL) return (0);

	stack[sp++] = (stack_el) {root, mx};

	while (sp)
	{
		el = stack[--sp];
		if (el.node->val >= el.mx) count++;
		mx = (el.node->val >= el.mx ? el.node->val : el.mx);
		if (el.node->right != NULL)
			stack[sp++] = (stack_el) {el.node->right, mx};
		if (el.node->left != NULL)
			stack[sp++] = (stack_el) {el.node->left, mx};
	}
	return (count);
}
