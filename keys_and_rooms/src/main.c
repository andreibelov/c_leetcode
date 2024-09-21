/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:18:22 by abelov            #+#    #+#             */
/*   Updated: 2024/09/21 21:18:23 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 841. Keys and Rooms
 *
 * Given an array rooms where rooms[i] is the set of keys that you can obtain
 * if you visited room i, return true if you can visit all the rooms,
 * or false otherwise.
 */
bool canVisitAllRooms(int **rooms, int roomsSize, int *roomsColSize);

#define MAX_ROOMS 1000

struct s_test_case
{
	TwoDArray	rooms;
	int			expected;
};

int ft_do_test(struct s_test_case *input)
{
	int i;
	int *rooms[MAX_ROOMS];
	int *sizes;
	int result;
	int check_val;

	sizes = (int *)alloca(input->rooms.size * sizeof(Array));
	i = -1;
	while (++i < input->rooms.size)
	{
		sizes[i] = input->rooms.arrays[i].size;
		rooms[i] = input->rooms.arrays[i].arr;
//		rooms[i] = *(int **)(&input->rooms.arrays[i]);
		ft_print_int_tab(rooms[i], sizes[i], NULL);
	}

	result = canVisitAllRooms(rooms, input->rooms.size, sizes);
	check_val = (input->expected == result);
	if (!check_val)
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   result, input->expected);
	check(check_val);
	return (0);
}

int main(void)
{
	int i;
	struct s_test_case cases[] = {
		{
			.rooms = (TwoDArray){
				.arrays = (Array [4]){
					{(int [1]){1}, .size = 1},
					{(int [1]){2}, .size = 1},
					{(int [1]){3}, .size = 1},
					{(int [1]){1}, .size = 0},
				},
				.size = 4
			},
			.expected = 1
		},
		{
			.rooms = (TwoDArray){
				.arrays = (Array [4]){
					{(int [2]){1,3}, .size = 2},
					{(int [3]){3,0,1}, .size = 3},
					{(int [1]){2}, .size = 1},
					{(int [1]){0}, .size = 1},
				},
				.size = 4
			},
			.expected = 0
		}
	};
	size_t inputs_size = (sizeof(cases) / sizeof(cases[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&cases[i]);
	return (EXIT_SUCCESS);
}
