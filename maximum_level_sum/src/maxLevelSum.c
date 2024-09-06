/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxLevelSum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 01:22:30 by abelov            #+#    #+#             */
/*   Updated: 2024/09/06 01:22:43 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stddef.h>
#include <malloc.h>
#include <string.h>
#include <limits.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/**
 * 1161. Maximum Level Sum of a Binary Tree
 *
 * Return the smallest level x such that the sum of all the values of nodes
 * at level x is maximal.
 */
int maxLevelSum(struct TreeNode *root);

typedef struct TreeNode TreeNode;
typedef struct s_stack_el
{
	TreeNode *node;
	int level;
} stack_el;

#define MAX_STACK_SIZE 10033 // Size of the stack
#define MAX_N 10033 // Size of the stack

int maxLevelSum(struct TreeNode *root)
{
	TreeNode	*node = NULL;
	stack_el	el;
	stack_el	queue[MAX_STACK_SIZE];
	int			rear = 0;
	int			front = 0;
	int			currSum = 0;
	int			currLevel = 1;
	int			maxSum = INT_MIN;
	int			maxSumLevel = 0;

	if (root)
		queue[rear++] = (stack_el) {root, 1};
	while (front < rear)
	{
		el = queue[front++];
		node = el.node;
		if (el.level > currLevel)
		{
			if (currSum > maxSum)
			{
				maxSum = currSum;
				maxSumLevel = currLevel;
			}
			currSum = node->val;
			currLevel = el.level;
		}
		else
			currSum += node->val;
		if (node->left != NULL)
			queue[rear++] = (stack_el){node->left, el.level + 1};
		if (node->right != NULL)
			queue[rear++] = (stack_el){node->right, el.level + 1};
		if (front == rear)
		{
			if (currSum > maxSum)
			{
				maxSum = currSum;
				maxSumLevel = currLevel;
			}
		}
	}
	return (maxSumLevel);
}
