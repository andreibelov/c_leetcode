/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:55:55 by abelov            #+#    #+#             */
/*   Updated: 2025/01/06 20:55:55 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 435. Non-overlapping Intervals
 *
 * Given an array of intervals intervals where intervals[i] = [starti, endi}, .size = 2},
 * return the minimum number of intervals you need to remove
 * to make the rest of the intervals non-overlapping.
 *
 * Constraints:
 * 	1 <= intervals.length <= 10^5
 *  intervals[i].length == 2
 *  -5 * 10^4 <= starti < endi <= 5 * 10^4
 */
int eraseOverlapIntervals(int **intervals, int intervalsSize,
						  int *intervalsColSize);

#define MAX_INTERVALS 100000

typedef struct s_test_case
{
	TwoDArray intervals;
	int expected;
} Input;


int ft_do_test(Input *input)
{
	int i;
	int *intervals[MAX_INTERVALS];
	int *sizes;
	int result;
	int check_val;


	sizes = (int *) alloca(input->intervals.size * sizeof(Array));
	i = -1;
	while (++i < input->intervals.size)
	{
		sizes[i] = input->intervals.arrays[i].size;
		intervals[i] = input->intervals.arrays[i].arr;
	}

	result = eraseOverlapIntervals(intervals, input->intervals.size,
								   sizes);
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
			.intervals = (TwoDArray) {
				.arrays = (Array[4]) {

					{(int[2]) {2, 3}, .size = 2},
					{(int[2]) {1, 2}, .size = 2},
					{(int[2]) {3, 4}, .size = 2},
					{(int[2]) {1, 3}, .size = 2},
				},
				.size = 4
			},
			.expected = 1
		},
		{
			.intervals = (TwoDArray) {
				.arrays = (Array[4]) {

					{(int[2]) {1, 2}, .size = 2},
					{(int[2]) {1, 2}, .size = 2},
					{(int[2]) {1, 2}, .size = 2}
				},
				.size = 3
			},
			.expected = 2
		},
		{
			.intervals = (TwoDArray) {
				.arrays = (Array[4]) {

					{(int[2]) {1, 100}, .size = 2},
					{(int[2]) {11, 22}, .size = 2},
					{(int[2]) {2, 12}, .size = 2}
				},
				.size = 3
			},
			.expected = 2
		},
		{
			.intervals = (TwoDArray) {
				.arrays = (Array[4]) {

					{(int[2]) {1, 2}, .size = 2},
					{(int[2]) {2, 3}, .size = 2},
				},
				.size = 2
			},
			.expected = 0
		},
		{
			.intervals = (TwoDArray) {
				.arrays = (Array[12]) {
					{(int[2]) {-52, 31}, .size = 2},
					{(int[2]) {-73, -26}, .size = 2},
					{(int[2]) {82, 97}, .size = 2},
					{(int[2]) {-65, -11}, .size = 2},
					{(int[2]) {-62, -49}, .size = 2},
					{(int[2]) {95, 99}, .size = 2},
					{(int[2]) {58, 95}, .size = 2},
					{(int[2]) {-31, 49}, .size = 2},
					{(int[2]) {66, 98}, .size = 2},
					{(int[2]) {-63, 2}, .size = 2},
					{(int[2]) {30, 47}, .size = 2},
					{(int[2]) {-40, -26}, .size = 2},
				},
				.size = 12
			},
			.expected = 7
		},
	};
	int i;
	size_t inputs_size = (sizeof(cases) / sizeof(cases[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&cases[i]);
	return (EXIT_SUCCESS);
}


