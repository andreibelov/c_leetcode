/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:26:37 by abelov            #+#    #+#             */
/*   Updated: 2025/01/06 14:26:37 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 1466. Reorder Routes to Make All Paths Lead to the City Zero
 *
 * There are n cities numbered from 0 to n - 1 and n - 1 roads such
 * that there is only one way to travel between two different cities
 * (this network form a tree).
 *
 * Last year, The ministry of transport decided to orient the roads
 * in one direction because they are too narrow.
 * Your task consists of reorienting some roads such that each city
 * can visit the city 0. Return the minimum number of edges changed.
 *
 * Constraints:
 * 	2 <= n <= 5 * 104
 *  connections.length == n - 1
 *  connections[i].length == 2
 *  0 <= ai, bi <= n - 1
 *  ai != bi
 */
int minReorder(int n, int **connections, int connectionsSize,
			   int *connectionsColSize);

typedef struct s_input
{
	int 		n;
	TwoDArray	connections;
	int			expected;
}	Input;

static int ft_do_test(Input *input)
{
	int result;
	int check_val;

	int **connections = (int **) alloca(input->connections.size * sizeof(int *));
	int *connectionsColSize = (int *) alloca(input->connections.size * sizeof(int));

	while (input->connections.iter < input->connections.size)
	{
		Array *ar = &input->connections.arrays[input->connections.iter];
		connections[input->connections.iter] = ar->arr;
		connectionsColSize[input->connections.iter] = ar->size;
		input->connections.iter++;
	}

	result = minReorder(input->n, connections,
						input->connections.size, connectionsColSize);
	check_val = (result == input->expected);
	if (!check_val)
	{
		printf("got \"%d\" elements whilst \"%d\" was to be expected\n",
			   result, input->expected);
	}
	check(check_val);
	return (0);
}

int main(void)
{
	int i;
	Input inputs[] = {
		{
			.n = 6,
			.connections = (TwoDArray){
				.arrays = (Array [5]){
					{(int []){0,1}, .size = 2},
					{(int []){1,3}, .size = 2},
					{(int []){2,3}, .size = 2},
					{(int []){4,0}, .size = 2},
					{(int []){4,5}, .size = 2},
				},
				.size = 5,
				.iter = 0
			},
			.expected = 3
		},
		{
			.n = 5,
			.connections = (TwoDArray){
				.arrays = (Array []){
					{(int []){1,0}, .size = 2},
					{(int []){1,2}, .size = 2},
					{(int []){3,2}, .size = 2},
					{(int []){3,4}, .size = 2},
				},
				.size = 4,
				.iter = 0
			},
			.expected = 2
		},
		{
			.n = 3,
			.connections = (TwoDArray){
				.arrays = (Array []){
					{(int []){1,0}, .size = 2},
					{(int []){2,0}, .size = 2},
				},
				.size = 2,
				.iter = 0
			},
			.expected = 0
		},
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
