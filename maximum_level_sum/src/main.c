/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 01:22:13 by abelov            #+#    #+#             */
/*   Updated: 2024/09/06 01:22:15 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 1161. Maximum Level Sum of a Binary Tree
 *
 * Constraints:
 * 	The number of nodes in the tree is in the range [1, 104].
 * 	-105 <= Node.val <= 105
 */
int maxLevelSum(struct TreeNode *root);

struct s_input
{
	int *arr;
	int arrSize;
	int expected;
};

typedef struct s_stack_el
{
	TreeNode *node;
	int idx;
} stack_el;

static int ft_do_test(struct s_input *input)
{
	TreeNode *root;
	int result;
	int check_val;

	ft_print_int_tab_null(input->arr, input->arrSize, null, NULL);
	root = deserialize_level_order(input->arr, input->arrSize);
	print_tree(root);
	result = maxLevelSum(root);
	check_val = (result == input->expected);
	if (!check_val)
	{
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   result, input->expected);
		check_val = false;
	}
	check(check_val);
	free_tree(root);
	return (0);
}

int main(void)
{
	int i;
	struct s_input inputs[] = {
		{
			.arrSize = 0,
			.arr = (int[1]) {},
			.expected = 0
		},
		{
			.arrSize = 3,
			.arr = (int[3]) {1,2,3},
			.expected = 2
		},
		{
			.arrSize = 7,
			.arr = (int[7]) {1,7,0,7,-8,null,null},
			.expected = 2
		},
		{
			.arrSize = 9,
			.arr = (int[9]) {989,null,10250,98693,-89388,null,null,null,-32127},
			.expected = 2
		}
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
