/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oddEvenList.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:59:10 by abelov            #+#    #+#             */
/*   Updated: 2024/08/30 15:59:10 by abelov           ###   ########.fr       */
/*                                                                            */
#include <stddef.h>

/* ************************************************************************** */

struct ListNode
{
	int val;
	struct ListNode *next;
};

typedef struct ListNode ListNode;

/**
 * 328. Odd Even Linked List
 *
 * Given the head of a singly linked list, group all the nodes with odd indices
 * together followed by the nodes with even indices, and return the reordered
 * list.
 *
 * The first node is considered odd, and the second node is even, and so on.
 */
ListNode *oddEvenList(struct ListNode *head);

#if !defined USE_COMBINED_LIST

struct ListNode *oddEvenList(struct ListNode *head)
{
	if (!head || !head->next) return head;

	struct ListNode *odd = head;
	struct ListNode *even = head->next;
	struct ListNode *even_head = even;

	while (even && even->next)
	{
		odd->next = even->next;
		odd = odd->next;

		even->next = odd->next;
		even = even->next;
	}
	odd->next = even_head;
	return head;
}

#else
struct ListNode *oddEvenList(struct ListNode *head)
{
	int				cond = 1;
	int				list_size = 0;

	struct ListNode *tail = head;
	struct ListNode *current = head;
	struct ListNode *prev = NULL;
	struct ListNode *tmp = NULL;
	struct ListNode *end;

	if (!head || !head->next) return (head);
	while (tail->next)
	{
		list_size++;
		prev = tail;
		tail = tail->next;
	}
	end = tail;

	while (current->next && cond)
	{
		tmp = current;
		tail->next = current->next;
		current->next = current->next->next;
		tail = tail->next;
		tail->next = NULL;
		current = current->next;
		cond = list_size % 2 ? tmp != prev : current != end;
	}
	return (head);
}
#endif
