/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minEatingSpeed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:46:35 by abelov            #+#    #+#             */
/*   Updated: 2024/09/22 21:46:35 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * 875. Koko Eating Bananas
 *
 * Koko loves to eat bananas.
 * There are n piles of bananas, the ith pile has piles[i] bananas.
 * The guards have gone and will come back in h hours.
 *
 *
 */
int minEatingSpeed(const int *piles, int pilesSize, int h);

int minEatingSpeed(const int *piles, int pilesSize, int h)
{
	int i;
	int left = 1;
	int right = 0;
	int mid;
	int minSpeed = 0;
	long long hoursSpentEating;

	/* Find the maximum pile size for the upper boundary */
	i = -1;
	while (++i < pilesSize)
		if (piles[i] > right)
			right = piles[i];

	while (left <= right)
	{
		mid = (left + right) >> 1;
		/* more overflow-safe option */
//		mid = left + (right - left) / 2;
		hoursSpentEating = 0;

		/* Calculate hours required for current eating speed `mid` */
		i = -1;
		while (++i < pilesSize)
		{
			if (piles[i] % mid == 0)
				hoursSpentEating += (piles[i] / mid);
			else
				hoursSpentEating += (piles[i] / mid + 1);
		}

		/* Binary search condition: update bounds */
		if (hoursSpentEating > h)
			left = mid + 1;
		else
		{
			minSpeed = mid;
			right = mid - 1;
		}
	}
	return (minSpeed);
}
