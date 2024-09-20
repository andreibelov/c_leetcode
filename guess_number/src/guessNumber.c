/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guessNumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:56:12 by abelov            #+#    #+#             */
/*   Updated: 2024/09/20 19:56:13 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 */
int guess(int num);

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

int guessNumber(int n)
{
	unsigned int start;
	unsigned int mid;
	unsigned int end = n;
	int result;

	start = 0;
	while (1)
	{
		mid = (start + end) / 2;
		result = guess((int) mid);
		if (result == 0)
			break;
		else if (result == -1)
			end = mid;
		else
			start = mid + 1;
	}
	return ((int)mid);
}
