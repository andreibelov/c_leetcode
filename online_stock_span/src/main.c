/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:30:48 by abelov            #+#    #+#             */
/*   Updated: 2024/12/20 18:30:49 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

typedef struct {
	int index;
	struct stack
	{
		int price;
		int index;
	} stack[1024];
	int ss;
} StockSpanner;

/**
 * 901. Online Stock Span
 *
 * Design an algorithm that collects daily price quotes for some stock
 * and returns the span of that stock's price for the current day.
 *
 * Use monotonic stack.
 * Keep the stack of monotonically increasing price and index.
 *
 * Constraints:
 * 	1 <= price <= 105
 * 	At most 104 calls will be made to next.
 */
int stockSpannerNext(StockSpanner *obj, int price);

StockSpanner *stockSpannerCreate();

void stockSpannerFree(StockSpanner *obj);

struct s_input
{
	Array *prices;
	Array *expected;
};

int ft_do_test(struct s_input *input)
{
	Array *prices;
	Array result;
	int check_val;
	StockSpanner *spanner = stockSpannerCreate();

	prices = input->prices;
	result = (Array) {.size = prices->size, .iter = 0,
		.arr = (int *) calloc(prices->size, sizeof(int))};
	prices->iter = -1;
	while (++(prices->iter) < prices->size)
		result.arr[result.iter++] = stockSpannerNext(spanner, prices->arr[prices->iter]);
	stockSpannerFree(spanner);

	check_val = (input->expected->size == result.size);
	if (!check_val)
		printf("got array of size [\"%d\"] whilst \"%d\" was to be expected\n",
			   result.size, input->expected->size);
	else
	{
		check_val = (arraycmp(&result, input->expected) == 0);
		if (!check_val)
		{
			check(check_val);
			printf("got ");
			ft_print_array(&result, " whilst ");
			ft_print_array(input->expected, "");
			printf(" was to be expected \n");
		}
		free(result.arr);
	}
	check(check_val);
	return (0);
}

int main(void)
{
	int i;
	struct s_input inputs[] = {
		{
			.prices = &(Array) {.arr = (int[7]) {100, 80, 60, 70, 60, 75, 85}, .size = 7},
			.expected = &(Array) {.arr = (int[7]) {1, 1, 1, 2, 1, 4, 6}, .size = 7}
		}
	};
	size_t inputs_size = (sizeof(inputs) / sizeof(inputs[0]));

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) inputs_size)
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}
