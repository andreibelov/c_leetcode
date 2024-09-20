/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:55:57 by abelov            #+#    #+#             */
/*   Updated: 2024/09/20 19:55:57 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "leetcode75.h"

/**
 * 374. Guess Number Higher or Lower
 *
 * We are playing the Guess Game. The game is as follows:
 * 	I pick a number from 1 to n. You have to guess which number I picked.
 * 	Every time you guess wrong, I will tell you whether the number I picked
 * 	is higher or lower than your guess.
 * 	You call a pre-defined API int guess(int num),
 * 	which returns three possible results: [-1, 1, 0]
 * Return the number that I picked.
 */
int guessNumber(int n);

struct s_test_case
{
	int num;
	int expected;
};

int *get_target_pointer()
{
	static int target = 0;
	return &target;
}

int guess(int num)
{
	int *target_ptr = get_target_pointer();
	if (num < *target_ptr) return 1;
	if (num > *target_ptr) return -1;
	return 0;
}

int ft_do_test(struct s_test_case *input)
{
	int result;
	int check_val;

	*get_target_pointer() = input->expected;

	result = guessNumber(input->num);
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
	struct s_test_case inputs[] = {
		{
			.num = 10,
			.expected = 6
		},
		{
			.num = 1,
			.expected = 1
		},
		{
			.num = 2,
			.expected = 1
		}
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
