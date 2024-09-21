/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canVisitAllRooms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:19:23 by abelov            #+#    #+#             */
/*   Updated: 2024/09/21 21:19:24 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef enum bool
{
	false = 0,
	true = 1
} bool;

/**
 * 841. Keys and Rooms
 *
 * Given an array rooms where rooms[i] is the set of keys that you can obtain
 * if you visited room i, return true if you can visit all the rooms,
 * or false otherwise.
 */
bool canVisitAllRooms(int **rooms, int roomsSize, int *roomsColSize);

void dfs(int room, bool visited[], int **rooms, int *roomsSize)
{
	int i;
	int nextRoom;
	visited[room] = true;

	i =-1;
	while (++i < roomsSize[room])
	{
		nextRoom = rooms[room][i];
		if (!visited[nextRoom])
			dfs(nextRoom, visited, rooms, roomsSize);
	}
}

#define MAX_ROOMS 1000

bool canVisitAllRooms(int **rooms, int roomsSize, int *roomsColSize)
{
	int i;
	bool visited[MAX_ROOMS] = {false};  // Initialize visited array
	dfs(0, visited, rooms, roomsColSize);  // Start DFS from room 0

	i = -1;
	while (++i < roomsSize)
		if (!visited[i])
			return false;  /* If any room is unvisited, return false */
	return true;  /* All rooms were visited */
}
