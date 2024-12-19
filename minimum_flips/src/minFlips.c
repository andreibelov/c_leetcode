/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minFlips.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:08:03 by abelov            #+#    #+#             */
/*   Updated: 2024/12/19 17:08:04 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int bitCount(int n)
{
	int res = 0;
	while (n != 0)
	{
		n &= n - 1;
		++res;
	}
	return res;
}

/**
 * 1318. Minimum Flips to Make a OR b Equal to c
 *
 * Given 3 positives numbers a, b and c.
 * Return the minimum flips required in some bits of a and b
 * to make ( a OR b == c ). (bitwise OR operation).
 *
 * Flip operation consists of change any single bit 1 to 0 or change
 * the bit 0 to 1 in their binary representation.
 */
int minFlips(int a, int b, int c)
{
	int bca = bitCount(a & ~c);
	int bcb = bitCount(b & ~c);
	int bcc = bitCount((c ^ (a & c)) & (c ^ (b & c)));
	return bca + bcb + bcc;
}
