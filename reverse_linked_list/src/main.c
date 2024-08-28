/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 23:34:22 by abelov            #+#    #+#             */
/*   Updated: 2024/08/27 23:34:22 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "leetcode75.h"

typedef struct ListNode	t_list;

t_list *reverseList(t_list *head);

struct ListNode
{
	int				val;
	struct ListNode	*next;
};

struct s_input
{
	int *arr;
	int arrSize;
};

void	ft_list_destroy(t_list **list, void (*del_fun)(void *))
{
	t_list	*current;
	t_list	*next;

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

int getArr(t_list *head, int **arr)
{
	int arrSize = 0;
	t_list *next = head;

	while(next)
	{
		(*arr)[arrSize++] = next->val;
		next = next->next;
	}
	return (arrSize);
}

t_list *getList(const int *arr, int size)
{
	int 	i = -1;
	t_list	*curr;
	t_list	*next;
	t_list	head = {.next = NULL};

	curr = &head;
	while (++i < size)
	{
		next = (t_list	*)malloc(sizeof(t_list));
		next->next = NULL;
		next->val = arr[i];
		curr->next = next;
		curr = next;
	}
	return (head.next);
}

static int ft_do_test(struct s_input *input)
{
	t_list	*result;
	int		resultSize;
	int		check_val;
	int		*expected = (int *) alloca(input->arrSize * sizeof(int));
	int		*expectedArr = (int *) alloca(input->arrSize * sizeof(int));


	ft_print_int_tab(input->arr, input->arrSize, NULL);
	memcpy(expected, input->arr, input->arrSize * sizeof(int));
	ft_rev_int_tab(expected, input->arrSize);

	result = reverseList(getList(input->arr, input->arrSize));
	resultSize = getArr(result, &expectedArr);
	if (resultSize != input->arrSize)
	{
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   resultSize, input->arrSize);
		check_val = false;
	}
	else
		check_val = !memcmp(expected, expectedArr, input->arrSize * sizeof(int));
	check(check_val);
	ft_list_destroy(&result, NULL);
	return (0);
}

int main(void)
{
	int i;
	struct s_input inputs[] = {
		{
			.arrSize = 0,
			.arr = (int[1]){},
		},
		{
			.arrSize = 5,
			.arr = (int[5]) {1,2,3,4,5}
		},
		{
			.arrSize = 2,
			.arr = (int[2]) {1,2}
		}
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
