/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:13:16 by abelov            #+#    #+#             */
/*   Updated: 2024/08/16 14:13:17 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>

# define FT_RED   "\033[0;31m"
# define FT_GREEN "\033[0;32m"
# define FT_CYAN  "\033[36m"
# define FT_RESET "\e[0m"

void sigsegv(int signal)
{
	(void) signal;
	printf("> "FT_CYAN".SIGSEGV"FT_RESET"\n");
	exit(EXIT_SUCCESS);
}

void check(bool succes)
{
	if (succes)
		printf("> "FT_GREEN".OK "FT_RESET"\n");
	else
		printf("> "FT_RED".KO "FT_RESET"\n");
}

void ft_print_int_tab(int tab[], size_t size, const char *eol)
{
	size_t pos;

	pos = 0;
	printf("[");
	if (pos < size)
		printf("%d", tab[pos++]);
	while (pos < size)
		printf(", %d", tab[pos++]);
	printf("]");
	if (!eol)
		printf("\n");
	else
		printf("%s", eol);
}

int maxArea(int *height, int heightSize);

struct s_input
{
	int *nums;
	int numsSize;
	int expected;
};


int ft_do_test(struct s_input *input)
{
	int result;
	int check_val;
	ft_print_int_tab(input->nums, input->numsSize, NULL);

	result = maxArea(input->nums,
					 input->numsSize);
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
	struct s_input inputs[] = {
		{
			.numsSize = 9,
			.nums = (int[9]) {1, 8, 6,  2, 5, 4,  8, 3, 7},
			.expected = 49
		},
		{
			.numsSize = 2,
			.nums = (int[2]) {1, 1},
			.expected = 1
		},
		{
			.numsSize = 3,
			.nums = (int[3]) {1,2,1},
			.expected = 2
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
