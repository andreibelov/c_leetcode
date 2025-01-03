/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:51:04 by abelov            #+#    #+#             */
/*   Updated: 2025/01/03 20:51:05 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

typedef enum op
{
	popSmallest = 0,
	addBack,
	max_op
} t_op;

struct s_input
{
	Array *cmd;
	Array *nums;
	Array *expected;
};

typedef struct SmallestInfiniteSet
{
	int *heap;
	int size;
	unsigned long long *bitmap;
} SmallestInfiniteSet;


SmallestInfiniteSet *smallestInfiniteSetCreate(void);

int smallestInfiniteSetPopSmallest(SmallestInfiniteSet *obj);

void smallestInfiniteSetAddBack(SmallestInfiniteSet *obj, int num);

void smallestInfiniteSetFree(SmallestInfiniteSet *obj);

int ft_do_test(struct s_input *input)
{
	Array result;
	Array *cmds = input->cmd;
	Array *nums = input->nums;
	int check_val;
	SmallestInfiniteSet *set = smallestInfiniteSetCreate();

	result = (Array) {.size = input->expected->size, .iter = 0,
		.arr = (int *) calloc(input->expected->size, sizeof(int))};
	cmds->iter = -1;
	while (++(cmds->iter) < cmds->size)
	{
		if (cmds->arr[cmds->iter] == addBack)
		{
			smallestInfiniteSetAddBack(set, nums->arr[cmds->iter]);
			result.arr[result.iter++] = null;
		}
		else if (cmds->arr[cmds->iter] == popSmallest)
			result.arr[result.iter++] = smallestInfiniteSetPopSmallest(set);
	}
	smallestInfiniteSetFree(set);

	check_val = (input->expected->size == result.size);
	if (!check_val)
		printf("got array of size [\"%d\"] whilst \"%d\" was to be expected\n",
			   result.size, input->expected->size);
	else
	{
		check_val = (arraycmp(&result, input->expected) == 0);
		if (!check_val)
		{
			check(check_val);
			printf("got ");
			ft_print_array(&result, " whilst ");
			ft_print_array(input->expected, "");
			printf(" was to be expected \n");
		}
		free(result.arr);
	}
	check(check_val);
	return (0);
}


int main(void)
{
	int i;
	struct s_input inputs[] = {
		{
			.cmd = &(Array) {.arr = (int[1]) {addBack}, .size = 1},
			.nums = &(Array) {(int[1]) {870}, .size = 1},
			.expected = &(Array) {.arr = (int[1]) {null}, .size = 1}
		},
		{
			.cmd = &(Array) {.arr = (int[8]) {addBack, popSmallest, popSmallest, popSmallest, addBack, popSmallest,
											  popSmallest, popSmallest}, .size = 8},
			.nums = &(Array) {(int[8]) {2, null, null, null, 1, null, null, null}, .size = 8},
			.expected = &(Array) {.arr = (int[8]) {null, 1, 2, 3, null, 1, 4, 5}, .size = 8}
		},
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}

