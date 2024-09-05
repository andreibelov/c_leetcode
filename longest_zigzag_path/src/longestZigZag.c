/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longestZigZag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 00:04:56 by abelov            #+#    #+#             */
/*   Updated: 2024/09/04 00:04:57 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct TreeNode TreeNode;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
};

/**
 * 1372. Longest ZigZag Path in a Binary Tree
 *
 * Zigzag length is defined as the number of nodes visited - 1.
 * (A single node has a length of 0).
 *
 * Return the longest ZigZag path contained in that tree.
 */
int longestZigZag(struct TreeNode *root);

#define STACK_SIZE 100000   // Size of the stack

typedef struct s_stack_el
{
	struct TreeNode *node;
	int leftSteps;
	int rightSteps;
} stack_el;

int longestZigZag(struct TreeNode *root)
{
	int longestPath = 0;
	int currentPathLength;
	struct s_stack_el el;
	struct s_stack_el stack[STACK_SIZE];
	int sp = 0;

	if (root)
		stack[sp++] = (struct s_stack_el) {root, 0, 0};
	while (sp)
	{
		el = stack[--sp];
		currentPathLength = el.leftSteps ? el.leftSteps : el.rightSteps;
		if (currentPathLength > longestPath) longestPath = currentPathLength;
		if (el.node->right)
			stack[sp++] = (struct s_stack_el) {el.node->right, 0, el.leftSteps + 1};
		if (el.node->left)
			stack[sp++] = (struct s_stack_el) {el.node->left, el.rightSteps + 1, 0};
	}
	return (longestPath);
}
