/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:09:00 by abelov            #+#    #+#             */
/*   Updated: 2024/12/25 12:09:01 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * 1268. Search Suggestions System
 *
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced,
 * assume caller calls free().
 *
 * Constraints:
 * 	1 <= products.length <= 1000
 * 	1 <= products[i].length <= 3000
 * 	1 <= sum(products[i].length) <= 2 * 104
 * 	All the strings of products are unique.
 * 	products[i] consists of lowercase English letters.
 * 	1 <= searchWord.length <= 1000
 * 	searchWord consists of lowercase English letters.
 */
char ***suggestedProducts(char **products, int productsSize,
						  char *searchWord, int *returnSize,
						  int **returnColumnSizes);

#include "leetcode75.h"

typedef struct StringArrays
{
	StringArray	*arrays;
	int ss;
	int size;
}	StringArrays;

typedef struct s_input
{
	StringArray *products;
	const char *const searchWord;
	StringArrays *expected;
}	Input;

int ft_do_test(Input *input)
{
	StringArray *products = input->products;
	StringArrays to_check;

	int check_val;
	int *returnColumnSizes;

	char ***result = NULL;

	result = suggestedProducts(products->arr, products->size,
							   (char *)input->searchWord, &to_check.size,
							   &returnColumnSizes);

	check_val = (input->expected->size == to_check.size);
	if (!check_val)
		printf("got array of size [\"%d\"] whilst \"%d\" was to be expected\n",
			   to_check.size, input->expected->size);
	else if (to_check.size != 0)
	{
		to_check.arrays = (StringArray *) alloca(to_check.size * sizeof(StringArray));

		int i = -1;
		while (++i < to_check.size)
		{
			StringArray *sa = &to_check.arrays[i];
			sa->arr = result[i];
			sa->size = returnColumnSizes[i];
		}
		free(result);
		free(returnColumnSizes);

		to_check.ss = -1;
		while (++(to_check.ss) < to_check.size && check_val)
		{
			StringArray *p = &to_check.arrays[to_check.ss];
			StringArray *q = &input->expected->arrays[to_check.ss];

			check_val = !strarraycmp(p, q);

			if (!check_val)
			{
				if (p->size == q->size)
					printf("got array of size [\"%d\"] whilst \"%d\" was to be expected\n",
						   p->size, q->size);
				printf("got ");
				ft_print_str_tab(p->arr, p->size, " whilst \n\t");
				ft_print_str_tab(q->arr, q->size, " was to be expected \n");
			}
		}
		to_check.ss = -1;
		while (++(to_check.ss) < to_check.size)
		{
			StringArray *p = &to_check.arrays[to_check.ss];
			p->iter = 0;
			while(p->iter < p->size)
				free(p->arr[p->iter++]);
			free(p->arr);
		}
	}
	check(check_val);
	return (0);
}

int main(void)
{
	int		i;
	Input	inputs[] = {
		{
			.products = &(StringArray){
				.arr = (char **) (const char *[]) {
					"mobile", "mouse", "moneypot", "monitor", "mousepad"
				},
				.size = 5
			},
			.searchWord = "mouse",
			.expected = &(StringArrays){
				.arrays = (StringArray[]){
					{ .arr = (char **) (const char *[]){"mobile","moneypot","monitor"}, .size = 3 },
					{ .arr = (char **) (const char *[]){"mobile","moneypot","monitor"}, .size = 3 },
					{ .arr = (char **) (const char *[]){"mouse","mousepad"}, .size = 2 },
					{ .arr = (char **) (const char *[]){"mouse","mousepad"}, .size = 2 },
					{ .arr = (char **) (const char *[]){"mouse","mousepad"}, .size = 2 },
				},
				.size = 5
			}
		},
		{
			.products = &(StringArray){
				.arr = (char **) (const char *[]) {
					"havana"
				},
				.size = 1
			},
			.searchWord = "havana",
			.expected = &(StringArrays){
				.arrays = (StringArray[]){
					{ .arr = (char **) (const char *[]){"havana"}, .size = 1 },
					{ .arr = (char **) (const char *[]){"havana"}, .size = 1 },
					{ .arr = (char **) (const char *[]){"havana"}, .size = 1 },
					{ .arr = (char **) (const char *[]){"havana"}, .size = 1 },
					{ .arr = (char **) (const char *[]){"havana"}, .size = 1 },
					{ .arr = (char **) (const char *[]){"havana"}, .size = 1 },
				},
				.size = 6
			}
		},
		{
			.products = &(StringArray){
				.arr = (char **) (const char *[]) {
					"havana"
				},
				.size = 1
			},
			.searchWord = "tatiana",
			.expected = &(StringArrays){
				.arrays = (StringArray[7]){
					{ .arr = (char **) (const char *[1]){}, .size = 0 },
					{ .arr = (char **) (const char *[1]){}, .size = 0 },
					{ .arr = (char **) (const char *[1]){}, .size = 0 },
					{ .arr = (char **) (const char *[1]){}, .size = 0 },
					{ .arr = (char **) (const char *[1]){}, .size = 0 },
					{ .arr = (char **) (const char *[1]){}, .size = 0 },
					{ .arr = (char **) (const char *[1]){}, .size = 0 },
				},
				.size = 7
			}
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}

