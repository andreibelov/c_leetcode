/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveZeroes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:23:51 by abelov            #+#    #+#             */
/*   Updated: 2024/08/16 13:23:51 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void moveZeroes(int *nums, int numsSize)
{
	int stack[10000];
	int stackSize = 0;
	int	i;

	i = -1;
	while (++i < numsSize)
		if (nums[i] != 0) stack[stackSize++] = nums[i];
	i = -1;
	while (++i < stackSize)
		nums[i] = stack[i];
	i--;
	while (++i < numsSize)
		nums[i] = 0;
}
