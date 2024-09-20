/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleteNode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:17:16 by abelov            #+#    #+#             */
/*   Updated: 2024/09/07 12:17:17 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/**
 * 450. Delete Node in a BST
 *
 * Given a root node reference of a BST and a key,
 * delete the node with the given key in the BST.
 *
 * Return the root node reference (possibly updated) of the BST.
 */
struct TreeNode *deleteNode(struct TreeNode *const root, int key);

typedef struct TreeNode TreeNode;

#if !defined USE_RIGHTMOST_PREDECESSOR
/**
 * To remove a value from a binary tree you need to complete the following:
 * 	1. Start with an existing tree
 * 	2. Search for the node containing the value you want to remove
 * 	3. If the node is found:
 * 		a. If the node has no children (leaf node), simply remove it from the tree
 * 		b. If the node has one child, replace the node with its child
 * 		c. If the node has two children, find the replacement node by:
 * 		    Option 1: Find the minimum value in its right subtree
 * 		    	(or the maximum value in its left subtree)
 * 		    Option 2: Choose either the leftmost node in the right subtree
 * 		    	(or the rightmost node in the left subtree).
 * 		    Remove the replacement node from its original location and place it
 * 		    	in the position of the node to be deleted.
 * 	4. After removal, adjust the binary tree structure (if necessary) in order
 * 	to maintain its properties and integrity
 * 	https://www.cs.cmu.edu/~clo/www/CMU/DataStructures/Lessons/lesson4_3.htm
 */
struct TreeNode *deleteNode(struct TreeNode *root, int key)
{
	struct TreeNode **tmp = NULL;
	struct TreeNode *parent = NULL;
	struct TreeNode *current = root;
	struct TreeNode *succParent = NULL;
	struct TreeNode *successor = NULL;
	struct TreeNode *leftNode = NULL;
	struct TreeNode *rightNode = NULL;

	// Step 1: Find the node to be deleted and its parent
	while (current != NULL && current->val != key)
	{
		parent = current;
		current = key < current->val ? current->left : current->right;
	}

	// Step 2: If node has been found:
	if (current != NULL)
	{
		leftNode = current->left;
		rightNode = current->right;

		if (parent == NULL) // The node to be deleted is the root
			tmp = &root;
		else if (parent->left == current) tmp = &parent->left;
		else tmp = &parent->right;

		// Case 0: Node with only one or no children
		if (leftNode == NULL || rightNode == NULL)
		{
			/* Case 1: Node with no children (leaf node) */
			if (leftNode == NULL && rightNode == NULL)
				*tmp = NULL;
			/* Case 2: Node with only left child */
			else if (rightNode == NULL)
				*tmp = leftNode;
			/* Case 3: Node with only right child */
			else *tmp = rightNode;
		}
		// Case 4: Node with two children
		else // Find in-order predecessor (leftmost node in the right subtree)
		{
			successor = rightNode;
			succParent = current;

			/* locate the rightmost node in the given subtree */
			while (successor->left != NULL)
			{
				succParent = successor;
				successor = successor->left;
			}

			/* Handle successor's promotion */
			*tmp = successor;
			if (succParent->right == successor)
				succParent->right = successor->right;
			else
			{
				succParent->left = successor->right;
				successor->right = rightNode;
			}
			successor->left = leftNode;

			/*
			if (succParent->right == successor)
				succParent->right = successor->right;
			else
				succParent->left = successor->right;

			successor->left = current->left;
			successor->right = current->right;
			 */
		}
		//  Handle node deletion
		free(current);  // Free the current node
	}
	return root;
}

#elif !defined USE_RECURSIVE

struct TreeNode *deleteNode(struct TreeNode *root, int key)
{
	struct TreeNode **tmp = NULL;
	struct TreeNode *parent = NULL;
	struct TreeNode *current = root;
	struct TreeNode *predParent = NULL;
	struct TreeNode *predecessor = NULL;

	// Step 1: Find the node to be deleted and its parent
	while (current != NULL && current->val != key)
	{
		parent = current;
		current = key < current->val ? current->left : current->right;
	}

	// If node has been found:
	// Step 2: Handle node deletion
	if (current != NULL)
	{
		struct TreeNode *leftNode = current->left;
		struct TreeNode *rightNode = current->right;

		// Case 0: Node with only one or no children
		if (leftNode == NULL || rightNode == NULL)
		{
			if (parent == NULL) // The node to be deleted is the root
				tmp = (free(current), &root);
			else if (parent->left == current) tmp = &parent->left;
			else tmp = &parent->right;
			/* Case 1: Node with no children (leaf node) */
			if (leftNode == NULL && rightNode == NULL)
				*tmp = NULL;
			/* Case 2: Node with only left child */
			else if (rightNode == NULL)
				*tmp = leftNode;
			/* Case 3: Node with only right child */
			else *tmp = rightNode;
		}
		// Case 4: Node with two children
		else // Find in-order predecessor (rightmost node in the left subtree)
		{
			predecessor = leftNode;
			predParent = current;

			/* locate the rightmost node in the given subtree */
			while (predecessor->right != NULL)
			{
				predParent = predecessor;
				predecessor = predecessor->right;
			}

			/* Replace currentNode's value with predecessor's value */
			current->val = predecessor->val;

			/* Handle predecessor's removal */
			if (predParent->left == predecessor)
				predParent->left = predecessor->left;
			else
				predParent->right = predecessor->left;
			free(predecessor);  // Free the predecessor node
		}
	}
	return root;
}

#else

/* Function to delete a node from the BST */
struct TreeNode *deleteNode(struct TreeNode *root, int key)
{
	struct TreeNode *node;
	struct TreeNode *leftNode;
	struct TreeNode *rightNode;

	if (root == NULL)
		return NULL;

	/* Search for the node to be deleted */
	if (key < root->val)
		root->left = deleteNode(root->left, key);
	else if (key > root->val)
		root->right = deleteNode(root->right, key);
	else // Node found
	{
		leftNode = root->left;
		rightNode = root->right;

		if (leftNode == NULL || rightNode == NULL)
		{
			free(root);
			// Case 1: Node has only one child
			if (leftNode == NULL)
				return (rightNode);
			else if (rightNode == NULL)
				return (leftNode);
			// Case 2: Node has no children (leaf node)
			else
				return (NULL);
		}
		else // Case 3: Node has two children
		{
			/* Find the inorder successor (smallest in the right subtree) */
			node = root->right;
			while (node->left != NULL)
				node = node->left;
			/* Copy the inorder successor's value to this node */
			root->val = node->val;
			/* Delete the inorder successor */
			root->right = deleteNode(root->right, node->val);
		}
	}
	return (root);
}

#endif
