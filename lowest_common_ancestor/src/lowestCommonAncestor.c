/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowestCommonAncestor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 01:02:46 by abelov            #+#    #+#             */
/*   Updated: 2024/09/05 01:02:46 by abelov           ###   ########.fr       */
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
 * 236. Lowest Common Ancestor of a Binary Tree
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given
 * nodes in the tree.
 */
struct TreeNode *lowestCommonAncestor(struct TreeNode *root,
									  struct TreeNode *p, struct TreeNode *q);

#if defined USE_RECURSIVE
struct TreeNode *lowestCommonAncestor(struct TreeNode *root,
									  struct TreeNode *p, struct TreeNode *q)
{
	struct TreeNode *lca = NULL;
	struct TreeNode *left = NULL;
	struct TreeNode *right = NULL;

	if (!root || root->val == p->val || root->val == q->val)
		lca = root;
	else
	{
		left = lowestCommonAncestor(root->left, p, q);
		right = lowestCommonAncestor(root->right, p, q);
		if (left != NULL && right != NULL) lca = root;
		else
			lca = left != NULL ? left : right;
	}

	return lca;
}
#elif !defined USE_STATIC_STACK

#define MAX_STACK_SIZE 100033 // Size of the stack
#define HASHMAP_SIZE 100033   // Size of the hash map
#define HASH_MOD 100000007   // Large prime modulus for hashing

enum st_state
{
	pre_order = 0,
	in_order = 1,
	post_order = 2
};

typedef struct s_stack_el
{
	struct TreeNode	*node;
	enum st_state 	state;
} stack_el;

unsigned int hash(struct TreeNode *node) {
	long key = (long)node;  // Use the pointer itself as the key
	unsigned int result = (key % HASH_MOD + HASH_MOD) % HASH_MOD;
	return (unsigned int) (result % HASHMAP_SIZE);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
	struct TreeNode *lca = NULL;
	struct TreeNode *foundP = NULL;
	struct TreeNode *foundQ = NULL;

	int sp = 0;
	stack_el el;
	stack_el stack[MAX_STACK_SIZE];

	if (root) stack[sp++] = (stack_el) {root, 0};

	// Keep track of parent-child relationships.
	struct TreeNode *parentMap[HASHMAP_SIZE] = {NULL};

	while (sp)
	{
		el = stack[--sp];

		if (el.state == pre_order)
		{
			/* Pre-order step: process the node before visiting children. */
			if (el.node == p) foundP = el.node;
			if (el.node == q) foundQ = el.node;

			/* Track the parent relationship for both children. */
			if (el.node->left) parentMap[hash(el.node->left)] = el.node;
			if (el.node->right) parentMap[hash(el.node->right)] = el.node;

			/* Push the node back to the stack with the updated state (to explore the right subtree next). */
			stack[sp++] = (stack_el) {el.node, 1};
			// Push the left child to explore next.
			if (el.node->left)
				stack[sp++] = (stack_el) {el.node->left, 0};
		}
		else if (el.state == in_order)
		{
			/* In-order step: left subtree has been processed, now explore right subtree. */
			stack[sp++] = (stack_el) {el.node, 2};
			if (el.node->right)
				stack[sp++] = (stack_el) {el.node->right, 0};
		}
		/* Optional: the tracing still needs to be done after this */
		else if (el.state == post_order)
		{
			/* Post-order step: all subtrees have been processed, move up the tree. */
			if (foundP && foundQ)
				break;  // Exit early if both nodes have been found.
		}
	}

	// Trace the path back to the root for both p and q.
	struct TreeNode* pathP[MAX_STACK_SIZE];
	struct TreeNode* pathQ[MAX_STACK_SIZE];
	int pathPLen = 0, pathQLen = 0;

	struct TreeNode *current;

	current = foundP;
	while (current != NULL) {
		pathP[pathPLen++] = current;
		current = parentMap[hash(current)];
	}

	current = foundQ;
	while (current != NULL) {
		pathQ[pathQLen++] = current;
		current = parentMap[hash(current)];
	}

	int i = pathPLen;
	int j = pathQLen;

	while (--i >= 0 && --j >= 0)
	{
		if (pathP[i] != pathQ[j]) break ;
		lca = pathP[i];
	}

	return (lca);
}

#endif
