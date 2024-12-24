/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:49:42 by abelov            #+#    #+#             */
/*   Updated: 2024/12/23 23:49:44 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <malloc.h>

/**
 * 208. Implement Trie (Prefix Tree)
 */
typedef struct Trie Trie;
struct Trie
{
	Trie *children[26];
	bool is_end;
};

static Trie *searchPrefix(Trie *node, const char *prefix)
{
	int index;

	while (*prefix)
	{
		index = *prefix++ - 'a';
		if (!node->children[index]) return NULL; // Prefix not found
		node = node->children[index]; // Move to next node
	}
	return node;
}

Trie *trieCreate()
{
	return (Trie *)calloc(1, sizeof(Trie));
}

void trieInsert(Trie *node, char *word)
{
	int index;

	while (*word)
	{
		index = *word++ - 'a';
		if (!node->children[index]) node->children[index] = trieCreate();
		node = node->children[index];
	}
	node->is_end = true;
}

bool trieSearch(Trie *obj, char *word)
{
	Trie* node = searchPrefix(obj, word);
	return (node != NULL && node->is_end);
}

bool trieStartsWith(Trie *obj, char *prefix)
{
	Trie* node = searchPrefix(obj, prefix);
	return node != NULL;
}

void trieFree(Trie *obj)
{
	Trie *current;
	Trie *stack[1024];
	int ss = 0;
	int i;

	stack[ss++] = obj;

	while (ss)
	{
		current = stack[--ss];
		i = -1;
		while (++i < 26)
			if (current->children[i]) stack[ss++] = current->children[i];
		free(current);
	}
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 * bool param_2 = trieSearch(obj, word);
 * bool param_3 = trieStartsWith(obj, prefix);
 * trieFree(obj);
*/
