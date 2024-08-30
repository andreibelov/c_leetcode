/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleteMiddle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:32:51 by abelov            #+#    #+#             */
/*   Updated: 2024/08/30 13:32:51 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

typedef struct ListNode ListNode;

/**
 * 2095. Delete the Middle Node of a Linked List
 *
 * You are given the head of a linked list. Delete the middle node, and return
 * the head of the modified linked list.
 *
 * The middle node of a linked list of size n is the ⌊n / 2⌋th node
 * from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer
 * less than or equal to x.
 *
 * Constraints:
 * 	The number of nodes in the list is in the range [1, 105].
 * 	1 <= Node.val <= 105
 */
ListNode *deleteMiddle(ListNode *head);

#if !defined TWO_POINTERS

ListNode	*deleteMiddle(ListNode *head)
{
	int	i;
	ListNode dummy = (ListNode){.next = head};
	ListNode *curr = &dummy;
	ListNode *tmp = head;
	int listSize = 0;

	while (head)
	{
		listSize++;
		head = head->next;
	}

	if (listSize > 1)
	{
		i = -1;
		while (++i < (listSize / 2))
			curr = curr->next;
		tmp = curr->next;
		curr->next = curr->next->next;
	}
	else
		dummy.next = NULL;
	free(tmp);
	return (dummy.next);
}

#else

struct ListNode *deleteMiddle(struct ListNode *head)
{
	struct ListNode *slow_ptr = head;
	struct ListNode *fast_ptr = head;
	struct ListNode *prev = NULL;

	if (head == NULL) return (NULL);
	if (head->next)
	{
		while (fast_ptr != NULL && fast_ptr->next != NULL)
		{
			prev = slow_ptr;
			slow_ptr = slow_ptr->next;
			fast_ptr = fast_ptr->next->next;
		}

		if (prev != NULL)
			prev->next = slow_ptr->next;
		else
			head = slow_ptr->next;
	}
	else
		head = NULL;
	free(slow_ptr);
	return (head);
}

#endif
