/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:55:19 by abelov            #+#    #+#             */
/*   Updated: 2024/08/21 10:55:20 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

int **findDifference(const int *nums1, int nums1Size,
					 const int *nums2, int nums2Size,
					 int *returnSize, int **returnColumnSizes);

struct s_input
{
	int *nums1;
	int nums1Size;
	int *nums2;
	int nums2Size;
	int *expected[2];
	int *expectedColumnSizes;
};

int ft_do_test(struct s_input *input)
{
	int **result;
	int resultSize;
	int *resultColumnSizes;
	int check_val;
	int totalSize = 0;
	int expectedTotalSize = 0;
	int i;

	ft_print_int_tab(input->nums1, input->nums1Size, NULL);
	ft_print_int_tab(input->nums2, input->nums2Size, NULL);

	result = findDifference(input->nums1, input->nums1Size,
							input->nums2, input->nums2Size,
							&resultSize, &resultColumnSizes);
	i = -1;
	while (++i < 2)
		expectedTotalSize += input->expectedColumnSizes[i];
	i = -1;
	while (++i < resultSize)
		totalSize += resultColumnSizes[i];
	if (expectedTotalSize != totalSize)
	{
		printf("resultTotalSize doesn't match expected value\n");
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
					  totalSize, expectedTotalSize);
		check(false);
	}
	else
	{
		check_val = 0;
		i = -1;
		while (++i < 2 && !check_val)
			check_val = !memcmp(input->expected[i], result[i], input->expectedColumnSizes[i] * sizeof(int));
		if (!check_val)
		{
			printf("got: ");
			i = -1;
			while(++i < resultSize)
				ft_print_int_tab(result[i], resultColumnSizes[i], ", ");
			printf("\nwhilst: ");
			i = -1;
			while(++i < 2)
				ft_print_int_tab(input->expected[i], input->expectedColumnSizes[i], ", ");
			printf(", was to be expected\n");
		}
		check(check_val);
	}
	return (0);
}

int main(void)
{
	int i;
	struct s_input inputs[] = {
		{
			.nums1 = (int[3]){1,2,3},
			.nums1Size = 3,
			.nums2 = (int[3]){2,4,6},
			.nums2Size = 3,
			.expected = {(int[]){1,3}, (int[]){4,6}},
			.expectedColumnSizes = (int[2]){2,2}
		},
		{
			.nums1 = (int[4]){1,2,3,3},
			.nums1Size = 4,
			.nums2 = (int[4]){1,1,2,2},
			.nums2Size = 4,
			.expected = {(int[]){3}, NULL},
			.expectedColumnSizes = (int[2]){1,0}
		},
		{
			.nums1 = (int[7]){-68,-80,-19,-94,82,21,-43},
			.nums1Size = 7,
			.nums2 = (int[1]){-63},
			.nums2Size = 1,
			.expected = {(int[7]){-68,-80,-19,-94,82,21,-43}, (int[]){-63}},
			.expectedColumnSizes = (int[2]){7,1}
		}
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
