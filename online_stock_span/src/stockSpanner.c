/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stockSpanner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:32:37 by abelov            #+#    #+#             */
/*   Updated: 2024/12/20 18:32:38 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

typedef struct {
	int index;
	struct
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
 */
int stockSpannerNext(StockSpanner* obj, int price);
StockSpanner *stockSpannerCreate();
void stockSpannerFree(StockSpanner *obj);

StockSpanner *stockSpannerCreate()
{
	StockSpanner *result = (StockSpanner *) malloc(sizeof(StockSpanner));
	result->index = 0;
	result->ss = 0;
	return result;
}

int stockSpannerNext(StockSpanner *obj, int price)
{
	int result;

	while (obj->ss && obj->stack[obj->ss - 1].price <= price) obj->ss--;
	obj->index += 1;
	result = obj->index;
	if (obj->ss) result -= obj->stack[obj->ss - 1].index;
	obj->stack[obj->ss].index = obj->index;
	obj->stack[obj->ss++].price = price;
	return (result);
}

void stockSpannerFree(StockSpanner *obj)
{ free(obj); }

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);

 * stockSpannerFree(obj);
 */
