/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseList.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 23:34:42 by abelov            #+#    #+#             */
/*   Updated: 2024/08/27 23:34:43 by abelov           ###   ########.fr       */
/*                                                                            */
#include <stddef.h>

/* ************************************************************************** */

struct ListNode
{
	int val;
	struct ListNode *next;
};

/**
 * 206. Reverse Linked List
 *
 * Given the head of a singly linked list,
 * reverse the list, and return the reversed list.
 *
 * Constraints:
 *     The number of nodes in the list is the range [0, 5000].
 *     -5000 <= Node.val <= 5000
 */
struct ListNode *reverseList(struct ListNode *list);

struct ListNode *reverseList(struct ListNode *list)
{
	struct ListNode	*to_return = NULL;
	struct ListNode	*current;
	struct ListNode	*next;

	if (list != NULL)
	{
		current = list;
		next = current->next;
		current->next = NULL;
		to_return = current;
		while (next)
		{
			current = next;
			next = current->next;
			current->next = to_return;
			to_return = current;
		}
	}
	return (to_return);
}
