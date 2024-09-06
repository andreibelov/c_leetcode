/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rightSideView.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 23:47:50 by abelov            #+#    #+#             */
/*   Updated: 2024/09/05 23:47:50 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <malloc.h>
#include <string.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct TreeNode TreeNode;
typedef struct s_stack_el
{
	TreeNode *node;
	int level;
} stack_el;

/**
 * 199. Binary Tree Right Side View
 *
 * Given the root of a binary tree, imagine yourself standing on the right side
 * of it, return the values of the nodes you can see ordered from top to bottom.
 */
int *rightSideView(struct TreeNode *root, int *returnSize);

#define MAX_STACK_SIZE 10033 // Size of the stack
#define MAX_N 10033 // Size of the stack

/* Optional: Use ring buffer approach if needed
stack_el dequeue(stack_el *queue, const int *rear, int *front)
{
	stack_el el = {.level = -1};

	if(rear == front) return (el);
	el = queue[*front++];
	*front %= MAX_N;
	return (el);
}

void enqueue(stack_el *queue, stack_el el, int *rear, const int *front)
{
	if((*rear + 1) % MAX_N == *front) return;
	queue[*rear++] = el;
	*rear %= MAX_N;
}
*/

int *rightSideView(struct TreeNode *root, int *returnSize)
{
	TreeNode	*node = NULL;
	int			sp = 0;
	int			stack[MAX_STACK_SIZE];
	stack_el	el;
	stack_el	queue[MAX_STACK_SIZE];
	int			rear = 0;
	int			front = 0;
	int			*result = NULL;
	int			currLevel = -1;

	if (root)
		queue[rear++] = (stack_el) {root, 0};
	while (front < rear)
	{
		el = queue[front++];
		node = el.node;
		if (el.level > currLevel)
		{
			stack[sp++] = node->val;
			currLevel = el.level;
		}
		if (node->right != NULL)
			queue[rear++] = (stack_el){node->right, el.level + 1};
		if (node->left != NULL)
			queue[rear++] = (stack_el){node->left, el.level + 1};
	}
	*returnSize = 0;
	if (sp != 0)
	{
		result = (int *)malloc(sp * sizeof(int));
		memcpy(result, stack, sp * sizeof(int));
		*returnSize = sp;
	}
	return (result);
}
