/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:45:20 by abelov            #+#    #+#             */
/*   Updated: 2025/01/05 22:45:21 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "leetcode75.h"

/**
 * 1926. Nearest Exit from Entrance in Maze
 *
 * You are given an m x n matrix mazewith empty cells ('.') and walls ('+').
 * You are also given the `entrance` of the maze: the row and column of the cell
 * you are initially standing at.
 *
 * Return the number of steps in the shortest path from the entrance
 * to the nearest exit, or -1 if no such path exists.
 *
 * Constraints:
 * 	maze.length == m
 * 	maze[i].length == n
 * 	1 <= m, n <= 100
 * 	maze[i][j] is either '.' or '+'.
 * 	entrance.length == 2
 * 	0 <= entrancerow < m
 * 	0 <= entrancecol < n
 * 	entrance will always be an empty cell.
 */
int nearestExit(char **maze, int mazeSize, const int *mazeColSize,
				const int *entrance, int entranceSize);

typedef struct
{
	int row, col;
} Point;
typedef struct StringArrays
{
	StringArray *arrays;
	int ss;
	int size;
} StringArrays;
typedef struct s_input
{
	StringArrays maze;
	Point start;
	int expected;
} Input;

int ft_do_test(Input *input)
{
	int result;
	int check_val;
	StringArray sa;
	sa.size = input->maze.size;
	sa.arr = alloca(sizeof(char *) * sa.size);
	sa.iter = -1;
	while (++(sa.iter) < sa.size)
	{
		StringArray *curr = &input->maze.arrays[sa.iter];
		sa.arr[sa.iter] = ft_tab_str_join(curr->arr, curr->size, "");
	}
	result = nearestExit(sa.arr, sa.size, (int[]) {(int) strlen(sa.arr[0])},
						 (int[2]) {input->start.row, input->start.col}, 2);
	check_val = (input->expected == result);
	if (!check_val)
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   result, input->expected);
	check(check_val);
	sa.iter = -1;
	while (++(sa.iter) < sa.size)
	{
		StringArray *curr = &input->maze.arrays[sa.iter];
		free(sa.arr[sa.iter]);
	}
	return (0);
}

int main(void)
{
	int i;
	struct s_input inputs[] = {
		{
			.maze = (StringArrays) {
				.arrays = (StringArray[]) {
					{.arr = (char **) (const char *[4]) {"+", "+", ".", "+"}, .size = 4},
					{.arr = (char **) (const char *[4]) {".", ".", ".", "+"}, .size = 4},
					{.arr = (char **) (const char *[4]) {"+", "+", "+", "."}, .size = 4}
				},
				.size = 3
			},
			.start = {1, 2},
			.expected = 1
		},
		{
			.maze = (StringArrays) {
				.arrays = (StringArray[]) {
					{.arr = (char **) (const char *[4]) {"+", "+", "+"}, .size = 3},
					{.arr = (char **) (const char *[4]) {".", ".", "."}, .size = 3},
					{.arr = (char **) (const char *[4]) {"+", "+", "+"}, .size = 3}
				},
				.size = 3
			},
			.start = {1, 0},
			.expected = 2
		},
		{
			.maze = (StringArrays) {
				.arrays = (StringArray[]) {
					{.arr = (char **) (const char *[4]) {".", "+"}, .size = 2},
				},
				.size = 1
			},
			.start = {0, 0},
			.expected = -1
		}
	};
	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
