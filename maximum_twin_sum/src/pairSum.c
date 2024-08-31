/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pairSum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 22:13:59 by abelov            #+#    #+#             */
/*   Updated: 2024/08/30 22:14:00 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

typedef struct ListNode ListNode;
struct ListNode
{
	int				val;
	struct ListNode	*next;
};

/**
 * 2130. Maximum Twin Sum of a Linked List
 *
 * In a linked list of size n, where n is even, the ith node (0-indexed)
 * of the linked list is known as the twin of the (n-1-i)th node,
 * if 0 <= i <= (n / 2) - 1.
 *
 * The twin sum is defined as the sum of a node and its twin.
 *
 * Given the head of a linked list with even length,
 * return the maximum twin sum of the linked list.
 *
 * Constraints:
 * 	The number of nodes in the list is an even integer in the range [2, 105].
 * 	1 <= Node.val <= 105
 *
 *
 */
int pairSum(struct ListNode *head);

#define MAX_TWINS 10000

int pairSum(struct ListNode *head)
{
	int	max_sum = 0;
	int	sum;
	int twinsTop = MAX_TWINS;
	struct ListNode *twins[MAX_TWINS + 1];

	struct ListNode *slow_ptr = head;
	struct ListNode *fast_ptr = head;

	if (head != NULL && head->next)
	{
		while (fast_ptr != NULL && fast_ptr->next != NULL)
		{
			slow_ptr = slow_ptr->next;
			fast_ptr = fast_ptr->next->next;
		}

		while (slow_ptr)
		{
			twins[twinsTop--] = slow_ptr;
			slow_ptr = slow_ptr->next;
		}

		while (twinsTop < MAX_TWINS)
		{
			sum = head->val + twins[++twinsTop]->val;
			if (sum > max_sum) max_sum = sum;
			head = head->next;
		}
	}
	return (max_sum);
}
