/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:21:03 by abelov            #+#    #+#             */
/*   Updated: 2024/09/06 14:21:04 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/**
 * 700. Search in a Binary Search Tree
 *
 * Find the node in the BST that the node's value equals val and return the
 * subtree rooted with that node. If such a node does not exist, return null.
 */
struct TreeNode *searchBST(struct TreeNode *root, int val);

struct TreeNode *searchBST(struct TreeNode *ptr, int val)
{
	while (ptr)
	{
		if (ptr->val == val) break;
		if (ptr->val > val) ptr = ptr->left;
		else ptr = ptr->right;
	}
	return (ptr);
}
