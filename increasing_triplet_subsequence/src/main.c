/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:40:37 by abelov            #+#    #+#             */
/*   Updated: 2024/08/14 10:40:38 by abelov           ###   ########.fr       */
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

bool increasingTriplet(int *nums, int numsSize);


struct s_input
{
	int *nums;
	int numsSize;
	bool expected;
};


int ft_do_test(struct s_input *input)
{
	bool result;
	int check_val;
	ft_print_int_tab(input->nums, input->numsSize, NULL);

	result = increasingTriplet(input->nums,
							   input->numsSize);
	check_val = (input->expected == result);
	if (!check_val)
		printf("got \"%s\" whilst \"%s\" was to be expected\n",
			   result ? "true" : "false",
			   input->expected ? "true" : "false");
	check(check_val);
	return (0);
}

int main(void)
{
	int i;
	struct s_input inputs[] = {
		{
			.nums = (int[]) {1, 2, 3, 4, 5},
			.numsSize = 5,
			.expected = true
		},
		{
			.nums = (int[]) {5, 4, 3, 2, 1},
			.numsSize = 5,
			.expected = false
		},
		{
			.nums = (int[]) {2, 1, 5, 0, 4, 6},
			.numsSize = 6,
			.expected = true
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
