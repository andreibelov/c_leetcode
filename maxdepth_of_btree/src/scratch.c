/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scratch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:22:46 by abelov            #+#    #+#             */
/*   Updated: 2024/09/02 00:22:47 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 10000
typedef struct Node TreeNode;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *new_node(int data)
{
	struct Node *node = (struct Node *) malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int height(struct Node *node)
{
	int ret_val = 0;
	int leftHeight;
	int rightHeight;

	if (node != NULL)
	{
		leftHeight = height(node->left);
		rightHeight = height(node->right);
		if (leftHeight > rightHeight)
			ret_val = leftHeight + 1;
		else
			ret_val = rightHeight + 1;
	}
	return (ret_val);
}

void free_tree(struct Node *root)
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

int get_array(struct Node *root, int **arr)
{
	int h = height(root);
	int arraySize = (1 << h) - 1;  // Size of the array = 2^h - 1

	(*arr) = (int *) malloc(arraySize * sizeof(int));
	if (root == NULL || arr == NULL)
		return (0);
	memset((*arr), -1, arraySize * sizeof(int));
	return (arraySize);
}

typedef struct rec
{
	TreeNode *node;
	int idx;
} stack_el;


int store_tree_in_array(struct Node *root, int **array_ptr)
{
	stack_el el;
	int stackSize = 0;
	stack_el stack[MAX_STACK_SIZE];

	int arraySize = get_array(root, array_ptr);
	int *arr = *array_ptr;

	stack[stackSize++] = (stack_el){root, 0};

	while (stackSize != 0)
	{
		el = stack[--stackSize];

		arr[el.idx] = el.node->data;
		if (el.node->right != NULL)
			stack[stackSize++] = (stack_el) {el.node->right, 2 * el.idx + 2};
		if (el.node->left != NULL)
			stack[stackSize++] = (stack_el) {el.node->left, 2 * el.idx + 1};
	}

	return (arraySize);
}

struct Node *rebuild_tree(int *arr, int size)
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

		if (left_index < size && arr[left_index] != -1)
		{
			node->left = new_node(arr[left_index]);
			stack[sp++] = (stack_el) {node->left, left_index};
		}

		if (right_index < size && arr[right_index] != -1)
		{
			node->right = new_node(arr[right_index]);
			stack[sp++] = (stack_el) {node->right, right_index};
		}
	}
	return (root);
}

void printArray(int *arr, int size)
{
	if (!arr) return;

	int i = -1;
	while (++i < size)
	{
		if (arr[i] != -1)
			printf("%d ", arr[i]);
		else
			printf("_ "); // Use _ to represent NULL values
	}
	printf("\n");
}

void inorder_traversal(struct Node* root) {
	if (root == NULL)
		return;

	inorder_traversal(root->left);
	printf("%d ", root->data);
	inorder_traversal(root->right);
}

int main(void)
{
	struct Node *root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left = NULL;
	root->left->right = new_node(5);
	root->right->left = new_node(6);
	root->right->right = new_node(7);

	int *arr = NULL;
	int arraySize = store_tree_in_array(root, &arr);

	printf("Array representation of the binary tree:\n");
	printArray(arr, arraySize);
	free_tree(root);
	root = rebuild_tree(arr, arraySize);
	inorder_traversal(root);
	free_tree(root);
	free(arr);

	return (EXIT_SUCCESS);
}
