/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:15:33 by abelov            #+#    #+#             */
/*   Updated: 2024/09/07 12:15:34 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

typedef struct TreeNode TreeNode;

/**
 * 450. Delete Node in a BST
 *
 * Constraints:
 * 	The number of nodes in the tree is in the range [0, 104].
 * 	-105 <= Node.val <= 105
 * 	Each node has a unique value.
 * 	root is a valid binary search tree.
 * 	-105 <= key <= 105
 */
struct TreeNode *deleteNode(struct TreeNode *root, int key);

struct s_test_case
{
	Array	*input;
	int		key;
	Array	*expected[5];
	int		expectedSize;
};

typedef struct s_stack_el
{
	TreeNode *node;
	int idx;
} stack_el;

static int ft_do_test(struct s_test_case *test_case)
{
	int i;
	Array *arr;
	TreeNode *root;
	TreeNode *ans;
	int *result;
	TreeNode *expectedTree;
	int resultSize;
	int check_val = 0;

	ft_print_int_tab_null(test_case->input->arr,
						  test_case->input->size, null, "\n");

	ans = deleteNode(deserialize_level_order(test_case->input->arr,
											 test_case->input->size),
					 test_case->key);
	result = serialize_level_order_leet(ans, &resultSize);

	i = -1;
	while (++i < test_case->expectedSize)
	{
		arr = test_case->expected[i];
		if (resultSize == arr->size)
		{
			if (resultSize == 0)
				check_val = 1;
			else
				check_val = !memcmp(result,
									arr->arr,
									(sizeof(int) * arr->size));
			if (check_val) break;
		}
	}

	if (!check_val)
	{
		printf("\n\n============================\n");
		printf("INITIAL TREE\n");
		root = deserialize_level_order(test_case->input->arr,
									   test_case->input->size);
		print_tree(root);
		printf("============================\n");
		printf("RESULT\n");
		print_tree(ans);
		printf("============================\n");
		printf("got: ");
		ft_print_int_tab_null(result, resultSize, null,
			  		"\n\nwhilst one of the following was to be expected :\n");
		i = -1;
		while (++i < test_case->expectedSize)
		{
			arr = test_case->expected[i];
			printf("============================\n");
			printf("EXPECTED%d\n", i);
			ft_print_int_tab_null(arr->arr, arr->size, null, "\n");
			expectedTree =
				deserialize_level_order(arr->arr, arr->size);
			print_tree(expectedTree);
			free_tree(expectedTree);
		}
		free_tree(root);
		printf("\n");
	}
	free(result);
	check(check_val);
	free_tree(ans);

	return (0);
}

const char *__asan_default_options()
{
	return ("color=always"
		   ":print_summary=1"
		   ":verbosity=1"
		   ":symbolize=1"
		   ":detect_stack_use_after_return=true"
		   ":malloc_context_size=5"
		   ":detect_leaks=1");
}

int main(void)
{
	int i;
	struct s_test_case cases[] = {
		{
			.input = &(Array){(int[7]) {5,3,6,2,4,null,7}, .size = 7},
			.key = 3,
			.expected = {
				&(Array){(int[7]) {5, 4, 6, 2, null, null, 7}, 7},
				&(Array){(int[7]) {5,2,6,null,4,null,7}, 7}
			},
			.expectedSize = 2
		},
		{
			.input = &(Array){(int[7]) {5,3,6,2,4,null,7}, 7},
			.key = 0,
			.expected = {&(Array){(int[7]) {5, 3, 6, 2, 4, null, 7}, 7}},
			.expectedSize = 1
		},
		{
			.input = &(Array){(int[1]) {}, 0},
			.key = 0,
			.expected = {&(Array){(int[1]) {}, 0}},
			.expectedSize = 1
		},
		{
			.input = &(Array){(int[1]) {1}, 1},
			.key = 1,
			.expected = {&(Array){(int[1]) {}, 0}},
			.expectedSize = 1
		},
		{
			.input = &(Array){(int[3]) {1,null, 2}, 3},
			.key = 1,
			.expected = {&(Array){(int[1]) {2}, 1}},
			.expectedSize = 1
		},
		{
			.input = &(Array){(int[3]) {1, 2, null}, 3},
			.key = 1,
			.expected = {&(Array){(int[1]) {2}, 1}},
			.expectedSize = 1
		},
		{
			.input = &(Array){(int[7]) {5,3,6,2,4,null,7}, 7},
			.key = 5,
			.expected = {
				&(Array){(int[5]) {6,3,7,2,4}, 5},
				&(Array){(int[7]) {4,3,6,2,null,null,7}, 7}
			},
			.expectedSize = 2
		},
		{
			.input = &(Array){(int[7]) {50,30,70,null,40,60,80}, .size = 7},
			.key = 50,
			.expected = {
				&(Array){(int[7]) {60,30,70,null,40,null,80}, 7},
				&(Array){(int[7]) {40,30,70,null,null,60,80}, 7},
				&(Array){(int[5]) {40,30,70,60,80}, 5}
			},
			.expectedSize = 3
		},
		{
			.input = &(Array){ .size = 94, .arr = (int[94]) {2, 0, 33, null, 1, 25, 40, null, null, 11, 31, 34, 45, 10, 18, 29, 32, null, 36, 43, 46, 4, null, 12, 24, 26, 30, null, null, 35, 39, 42, 44, null, 48, 3, 9, null, 14, 22, null, null, 27, null, null, null, null, 38, null, 41, null, null, null, 47, 49, null, null, 5, null, 13, 15, 21, 23, null, 28, 37, null, null, null, null, null, null, null, null, 8, null, null, null, 17, 19, null, null, null, null, null, null, null, 7, null, 16, null, null, 20, 6}},
			.key = 33,
			.expected = {
				&(Array){(int[92]) {2,0,34,null,1,25,40,null,null,11,31,35,45,10,18,29,32,null,36,43,46,4,null,12,24,26,30,null,null,null,39,42,44,null,48,3,9,null,14,22,null,null,27,null,null,38,null,41,null,null,null,47,49,null,null,5,null,13,15,21,23,null,28,37,null,null,null,null,null,null,null,null,8,null,null,null,17,19,null,null,null,null,null,null,null,7,null,16,null,null,20,6}, 92},
				&(Array){(int[92]) {2,0,32,null,1,25,40,null,null,11,31,34,45,10,18,29,null,null,36,43,46,4,null,12,24,26,30,35,39,42,44,null,48,3,9,null,14,22,null,null,27,null,null,null,null,38,null,41,null,null,null,47,49,null,null,5,null,13,15,21,23,null,28,37,null,null,null,null,null,null,null,null,8,null,null,null,17,19,null,null,null,null,null,null,null,7,null,16,null,null,20,6}, 92},
				&(Array){(int[92]) {2,0,34,null,1,25,40,null,null,11,31,36,45,10,18,29,32,35,39,43,46,4,null,12,24,26,30,null,null,null,null,38,null,42,44,null,48,3,9,null,14,22,null,null,27,null,null,37,null,41,null,null,null,47,49,null,null,5,null,13,15,21,23,null,28,null,null,null,null,null,null,null,null,null,8,null,null,null,17,19,null,null,null,null,null,7,null,16,null,null,20,6}, 92},
				&(Array){(int[67]) {2,0,34,null,1,25,40,11,31,36,45,10,18,29,32,35,39,43,46,4,null,12,24,26,30,38,null,42,44,null,48,3,9,null,14,22,null,null,27,37,null,41,null,47,49,5,null,13,15,21,23,null,28,null,8,null,17,19,null,7,null,16,null,null,20,6,null},67},
				&(Array){(int[69]) {2,0,32,null,1,25,40,11,31,34,45,10,18,29,null,null,36,43,46,4,null,12,24,26,30,35,39,42,44,null,48,3,9,null,14,22,null,null,27,38,null,41,null,47,49,5,null,13,15,21,23,null,28,37,null,null,8,null,17,19,null,7,null,16,null,null,20,6,null},69}
			},
			.expectedSize = 4
		}
	};
	size_t inputs_size = (sizeof(cases) / sizeof(cases[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&cases[i]);
	return (EXIT_SUCCESS);
}
