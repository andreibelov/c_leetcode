/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:03:41 by abelov            #+#    #+#             */
/*   Updated: 2025/01/08 12:03:43 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 452. Minimum Number of Arrows to Burst Balloons
 *
 * There are some spherical balloons taped onto a flat wall that represents
 * the XY-plane. The balloons are represented as a 2D integer array points
 * where points[i] = [Xstart, Xend] denotes a balloon whose horizontal diameter
 * stretches between Xstart and Xend.
 *
 * Given the array points, return the minimum number of arrows
 * that must be shot to burst all balloons.
 *
 * Constraints:
 * 	1 <= points.length <= 105
 *  points[i].length == 2
 *  -231 <= Xstart < Xend <= 231 - 1
 */
int findMinArrowShots(int **points, int pointsSize, int *pointsColSize);

typedef struct s_test_case
{
	TwoDArray balloons;
	int expected;
} Input;


int ft_do_test(Input *input)
{
	int i;
	int *points[105];
	int *pointsColSize;
	int result;
	int check_val;


	pointsColSize = (int *) alloca(input->balloons.size * sizeof(Array));
	i = -1;
	while (++i < input->balloons.size)
	{
		pointsColSize[i] = input->balloons.arrays[i].size;
		points[i] = input->balloons.arrays[i].arr;
	}

	result = findMinArrowShots(points, input->balloons.size,
							   pointsColSize);
	check_val = (input->expected == result);
	if (!check_val)
		printf("got \"%d\" whilst \"%d\" was to be expected\n",
			   result, input->expected);
	check(check_val);
	return (0);
}

int main(void)
{
	Input cases[] = {
		{
			.balloons = (TwoDArray) {
				.arrays = (Array[4]) {

					{(int[2]) {10, 16}, .size = 2},
					{(int[2]) {2, 8}, .size = 2},
					{(int[2]) {1, 6}, .size = 2},
					{(int[2]) {7, 12}, .size = 2},
				},
				.size = 4
			},
			.expected = 2
		},
		{
			.balloons = (TwoDArray) {
				.arrays = (Array[4]) {

					{(int[2]) {1, 2}, .size = 2},
					{(int[2]) {3, 4}, .size = 2},
					{(int[2]) {5, 6}, .size = 2},
					{(int[2]) {7, 8}, .size = 2}
				},
				.size = 4
			},
			.expected = 4
		},
		{
			.balloons = (TwoDArray) {
				.arrays = (Array[4]) {

					{(int[2]) {1,2}, .size = 2},
					{(int[2]) {2,3}, .size = 2},
					{(int[2]) {3,4}, .size = 2},
					{(int[2]) {4,5}, .size = 2},
				},
				.size = 4
			},
			.expected = 2
		},
		{
			.balloons = (TwoDArray) {
				.arrays = (Array[4]) {

					{(int[2]) {-2147483648,2147483647}, .size = 2},
				},
				.size = 1
			},
			.expected = 1
		},
		{
			.balloons = (TwoDArray) {
				.arrays = (Array[4]) {

					{(int[2]) {-2147483646,-2147483645}, .size = 2},
					{(int[2]) {2147483646,2147483647}, .size = 2},
				},
				.size = 2
			},
			.expected = 2
		}
	};
	int i;
	size_t inputs_size = (sizeof(cases) / sizeof(cases[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&cases[i]);
	return (EXIT_SUCCESS);
}
