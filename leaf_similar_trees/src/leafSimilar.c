/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leafSimilar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 01:11:48 by abelov            #+#    #+#             */
/*   Updated: 2024/09/02 01:11:48 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>


typedef struct TreeNode TreeNode;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
};

/**
 * 872. Leaf-Similar Trees
 *
 * Consider all the leaves of a binary tree, from left to right order,
 * the values of those leaves form a leaf value sequence.
 * Two binary trees are considered leaf-similar if their leaf value sequence
 * is the same.
 *
 * Return true if and only if the two given trees are leaf-similar.
 */
unsigned char leafSimilar(struct TreeNode *root1, struct TreeNode *root2);

#if !defined USE_TWO_STACKS

#define MAX_STACK_SIZE 10000

unsigned char leafSimilar(struct TreeNode *root1, struct TreeNode *root2)
{
	int sp = 0;
	int stack[MAX_STACK_SIZE];

	int msp = 0;
	int sp2 = 0;
	struct TreeNode *main_stack[MAX_STACK_SIZE];
	struct TreeNode *node;

	if (!root1 || !root2) return false;

	main_stack[msp++] = root1;
	while(msp)
	{
		node = main_stack[--msp];
		if (!node->left && !node->right) stack[sp++] = node->val;
		else
		{
			if (node->right) main_stack[msp++] = node->right;
			if (node->left) main_stack[msp++] = node->left;
		}
	}

	main_stack[msp++] = root2;
	while(msp)
	{
		node = main_stack[--msp];
		if (!node->left && !node->right)
		{
			if (sp2 > sp || stack[sp2++] != node->val)
				return false;
		}
		else
		{
			if (node->right) main_stack[msp++] = node->right;
			if (node->left) main_stack[msp++] = node->left;
		}
	}

	return (sp2 == sp ? true : false);
}

#else

#define MAX_STACK_SIZE 10000

unsigned char leafSimilar(struct TreeNode *root1, struct TreeNode *root2)
{
	int sp1 = 0;
	int stack1[MAX_STACK_SIZE];
	int sp2 = 0;
	int stack2[MAX_STACK_SIZE];

	int msp = 0;
	struct TreeNode *main_stack[MAX_STACK_SIZE];
	struct TreeNode *node;

	if (!root1 || !root2) return false;

	main_stack[msp++] = root1;
	while(msp)
	{
		node = main_stack[--msp];
		if (!node->left && !node->right) stack1[sp1++] = node->val;
		else
		{
			if (node->right) main_stack[msp++] = node->right;
			if (node->left) main_stack[msp++] = node->left;
		}
	}

	main_stack[msp++] = root2;
	while(msp)
	{
		node = main_stack[--msp];
		if (!node->left && !node->right) stack2[sp2++] = node->val;
		else
		{
			if (node->right) main_stack[msp++] = node->right;
			if (node->left) main_stack[msp++] = node->left;
		}
	}

	return (sp1 == sp2 ? !memcmp(stack1, stack2, sp1 * sizeof(int))  : false);
}
#endif
