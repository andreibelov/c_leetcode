/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largestAltitude.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:31:33 by abelov            #+#    #+#             */
/*   Updated: 2024/08/20 11:31:33 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * 1732. Find the Highest Altitude
 */
int largestAltitude(const int *gain, int gainSize)
{
	int i;
	int altitude = 0;
	int max_altitude = 0;

	i = -1;
	while (++i < gainSize)
	{
		altitude += gain[i];
		if (altitude > max_altitude) max_altitude = altitude;
	}
	return (max_altitude);
}