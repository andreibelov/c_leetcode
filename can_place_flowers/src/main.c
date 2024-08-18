/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:23:47 by abelov            #+#    #+#             */
/*   Updated: 2024/08/11 16:23:48 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

bool	canPlaceFlowers(int *flowerbed, const int flowerbedSize, int n);

int ft_do_test(int *flowerbed, int flowerbedSize, int n, unsigned char expected)
{
	ft_print_int_tab(flowerbed, flowerbedSize, NULL);
	return (canPlaceFlowers(flowerbed, flowerbedSize, n) == expected);
}

int main(void)
{
	signal(SIGSEGV, sigsegv);
	check(ft_do_test((int[]) {1, 0, 0, 0, 1}, 5, 1, true));
	check(ft_do_test((int[]) {1, 0, 0, 0, 1}, 5, 2, false));
	return (EXIT_SUCCESS);
}
