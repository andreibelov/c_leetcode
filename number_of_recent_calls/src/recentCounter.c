/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recentCounter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:59:28 by abelov            #+#    #+#             */
/*   Updated: 2024/08/28 10:21:08 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct rc RecentCounter;

/**
 * 933. Number of Recent Calls
 *
 * You have a RecentCounter class which counts the number of recent
 * requests within a certain time frame.
*/
int recentCounterPing(RecentCounter *counter, int t);

#if !defined USE_DINAMIC
typedef struct rc RecentCounter;
// Use a linked list queue (pop elements once it exceeds 3000 in time difference)
struct rc
{
	int head;
	int tail;
	int time[10001];
};

RecentCounter *recentCounterCreate()
{
	RecentCounter *counter = malloc(sizeof(RecentCounter));
	counter->head = 0;
	counter->tail = 1;
	return (counter);
}

int recentCounterPing(RecentCounter *counter, int t)
{
	while (t - (counter->time)[counter->head] > 3000)
	{
		if (counter->head >= counter->tail) break;
		(counter->head)++;
	}
	(counter->time)[(counter->tail)++] = t;
	return (counter->tail - counter->head);
}

void recentCounterFree(RecentCounter *counter)
{
	free(counter);
}

#else

typedef struct Node
{
	int time;
	struct Node *next;
} Node;

struct rc
{
	Node *front;
	Node *rear;
};

RecentCounter *recentCounterCreate()
{
	RecentCounter *counter = (RecentCounter *) malloc(sizeof(RecentCounter));
	counter->front = NULL;
	counter->rear = NULL;
	return counter;
}

int recentCounterPing(RecentCounter *counter, int t)
{
	int		count = 0;
	Node	*new;
	Node	*current;
	Node	*front;

	new = (Node *) malloc(sizeof(Node));
	new->time = t;
	new->next = NULL;

	if (counter->rear == NULL)
	{
		counter->front = new;
		counter->rear = new;
	}
	else
	{
		counter->rear->next = new;
		counter->rear = new;
	}

	/* Remove times from the front that are out of the 3000 ms range */
	while (counter->front != NULL && counter->front->time < (t - 3000))
	{
		front = counter->front;
		counter->front = counter->front->next;
		free(front);
	}

	/* Calculate the size of the queue (number of valid pings) */
	current = counter->front;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void recentCounterFree(RecentCounter *counter)
{
	Node *front;

	while (counter->front != NULL)
	{
		front = counter->front;
		counter->front = counter->front->next;
		free(front);
	}
	free(counter);
}

#endif
