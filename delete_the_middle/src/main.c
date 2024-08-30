/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:32:27 by abelov            #+#    #+#             */
/*   Updated: 2024/08/30 13:32:28 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

typedef struct ListNode ListNode;

/**
 * 2095. Delete the Middle Node of a Linked List
 */
ListNode *deleteMiddle(ListNode *head);

struct ListNode
{
	int val;
	ListNode *next;
};

struct s_input
{
	int *arr;
	int arrSize;
	int *expected;
	int expectedSize;
};

void fListNode_destroy(ListNode **list, void (*del_fun)(void *))
{
	ListNode *current;
	ListNode *next;

	if (list != NULL)
	{
		current = *list;
		while (current != NULL)
		{
			next = current->next;
			if (del_fun != NULL)
				del_fun((void *) &current->val);
			free(current);
			current = next;
		}
	}
}

void ft_rev_int_tab(int *tab, int size)
{
	int *head;
	int *tail;
	int temp;

	head = tab;
	tail = tab + size - 1;
	while (head <= tail)
	{
		temp = *tail;
		*tail-- = *head;
		*head++ = temp;
	}
}

int getArr(ListNode *head, int **arr)
{
	int arrSize = 0;
	ListNode *next = head;

	while (next)
	{
		(*arr)[arrSize++] = next->val;
		next = next->next;
	}
	return (arrSize);
}

ListNode *getList(const int *arr, int size)
{
	int i = -1;
	ListNode *curr;
	ListNode *next;
	ListNode head = {.next = NULL};

	curr = &head;
	while (++i < size)
	{
		next = (ListNode *) malloc(sizeof(ListNode));
		next->next = NULL;
		next->val = arr[i];
		curr->next = next;
		curr = next;
	}
	return (head.next);
}

static int ft_do_test(struct s_input *input)
{
	ListNode *result;
	int resultSize;
	int check_val;
	int *resultArr = (int *) alloca(input->arrSize * sizeof(int));

	ft_print_int_tab(input->arr, input->arrSize, NULL);

	result = deleteMiddle(getList(input->arr, input->arrSize));
	resultSize = getArr(result, &resultArr);
	if (resultSize != input->expectedSize)
	{
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   resultSize, input->arrSize);
		check_val = false;
	}
	else
		check_val = !memcmp(resultArr, input->expected, input->expectedSize * sizeof(int));
	check(check_val);
	fListNode_destroy(&result, NULL);
	return (0);
}

int main(void)
{
	int i;
	struct s_input inputs[] = {
		{
			.arr = (int[]) {1, 3, 4, 7, 1, 2, 6},
			.arrSize = 7,
			.expected = (int[]) {1, 3, 4, 1, 2, 6},
			.expectedSize = 6,
		},
		{
			.arr = (int[]) {1, 2, 3, 4},
			.arrSize = 4,
			.expected = (int[]) {1, 2, 4},
			.expectedSize = 3,
		},
		{
			.arr = (int[]) {2, 1},
			.arrSize = 2,
			.expected = (int[1]) {2},
			.expectedSize = 1,
		},
		{
			.arr = (int[]) {1},
			.arrSize = 1,
			.expected = (int[1]) {},
			.expectedSize = 0,
		}
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
