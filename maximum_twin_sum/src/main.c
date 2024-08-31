/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 22:13:37 by abelov            #+#    #+#             */
/*   Updated: 2024/08/30 22:13:37 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

typedef struct ListNode ListNode;

/**
 * 2130. Maximum Twin Sum of a Linked List
 */
int pairSum(struct ListNode *head);

struct ListNode
{
	int				val;
	struct ListNode	*next;
};

struct s_input
{
	int *arr;
	int arrSize;
	int expected;
};

void	fListNode_destroy(ListNode **list, void (*del_fun)(void *))
{
	ListNode	*current;
	ListNode	*next;

	if (list != NULL)
	{
		current = *list;
		while (current != NULL)
		{
			next = current->next;
			if (del_fun != NULL)
				del_fun((void *)&current->val);
			free(current);
			current = next;
		}
	}
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	*head;
	int	*tail;
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

	while(next)
	{
		(*arr)[arrSize++] = next->val;
		next = next->next;
	}
	return (arrSize);
}

ListNode *getList(const int *arr, int size)
{
	int 	i = -1;
	ListNode	*curr;
	ListNode	*next;
	ListNode	head = {.next = NULL};

	curr = &head;
	while (++i < size)
	{
		next = (ListNode	*)malloc(sizeof(ListNode));
		next->next = NULL;
		next->val = arr[i];
		curr->next = next;
		curr = next;
	}
	return (head.next);
}

static int ft_do_test(struct s_input *input)
{
	ListNode *inputList = getList(input->arr, input->arrSize);
	int	result;
	int	check_val;

	ft_print_int_tab(input->arr, input->arrSize, NULL);

	result = pairSum(inputList);
	check_val = (result == input->expected);
	if (!check_val)
	{
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   result, input->expected);
	}
	check(check_val);
	fListNode_destroy(&inputList, NULL);
	return (0);
}

int main(void)
{
	int i;
	struct s_input inputs[] = {
		{
			.arrSize = 4,
			.arr = (int[]){5,4,2,1},
			.expected = 6
		},
		{
			.arrSize = 4,
			.arr = (int[5]) {4,2,2,3},
			.expected = 7
		},
		{
			.arrSize = 2,
			.arr = (int[5]) {1,100000},
			.expected = 100001
		}
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
