/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predictPartyVictory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:10:28 by abelov            #+#    #+#             */
/*   Updated: 2024/08/29 13:10:29 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>

/**
 * 649. Dota2 Senate
 *
 * In the world of Dota2, there are two parties: the Radiant and the Dire.
 * The Dota2 senate consists of senators coming from two parties.
 * Now the Senate wants to decide on a change in the Dota2 game.
 * The voting for this change is a round-based procedure.
 * In each round, each senator can exercise one of the two rights:
 *	Ban one senator's right:
 *		A senator can make another senator lose all his rights in this and all
 *		the following rounds.
 *	Announce the victory:
 *		If this senator found the senators who still have rights to vote are
 *		all	from the same party, he can announce the victory and decide
 *		on the change in the game.
 *
 * Given a string senate representing each senator's party belonging.
 * The character 'R' and 'D' represent the Radiant party and the Dire party.
 * Then if there are n senators, the size of the given string will be n.
 *
 * The round-based procedure starts from the first senator to the last senator
 * in the given order. This procedure will last until the end of voting.
 * All the senators who have lost their rights will be skipped during
 * the procedure.
 *
 * Suppose every senator is smart enough and will play the best strategy for his
 * own party. Predict which party will finally announce the victory and change
 * the Dota2 game. The output should be "Radiant" or "Dire".
 *
 * Constraints:
 * 	n == senate.length
 * 	1 <= n <= 104
 * 	senate[i] is either 'R' or 'D'.
 */
char *predictPartyVictory(const char *senate);

#define MAX_N 10000

typedef struct
{
	int	queue[MAX_N];
	int	front;
	int	rear;
} Queue;

void enqueue(Queue *q, int val)
{
	q->queue[q->rear++] = val;
}

int dequeue(Queue *q)
{
	return q->queue[q->front++];
}

int is_empty(Queue *q)
{
	return q->front == q->rear;
}

char *predictPartyVictory(const char *senate)
{
	int		i;
	int		n;
	int		r_index;
	int		d_index;
	Queue	radiant;
	Queue	dire;
	char	*winner = NULL;

	radiant.front = radiant.rear = 0;
	dire.front = dire.rear = 0;

	n = (int)strlen(senate);
	i = -1;
	while (++i < n)
	{
		if (senate[i] == 'R')
			enqueue(&radiant, i);
		else
			enqueue(&dire, i);
	}

	while (!is_empty(&radiant) && !is_empty(&dire))
	{

		r_index = dequeue(&radiant);
		d_index = dequeue(&dire);

		/* The senator with the smaller index bans the other */
		if (r_index < d_index)
			/* Radiant senator will vote again in the next round */
			enqueue(&radiant, r_index + n);
		else
			/* Dire senator will vote again in the next round */
			enqueue(&dire, d_index + n);
	}

	if (is_empty(&radiant))
		winner = (char *)"Dire";
	else
		winner = (char *)"Radiant";
	return (winner);
}
