/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suggestedProducts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:11:36 by abelov            #+#    #+#             */
/*   Updated: 2024/12/25 12:11:37 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ARRAY_SIZE 1024

typedef struct Array
{
	int *arr;
	size_t size;
	int ss;
} Array;

typedef struct TwoDArray
{
	Array *arrays;
	size_t size;
	int ss;
} TwoDArray;

typedef struct Trie Trie;
struct Trie
{
	Trie *children[26];
	Array indices;
	bool is_end;
};
int compare_strings(const void* a, const void* b);
static int *intdup(const int *arr, size_t len);
Trie *trieCreate();
void trieInsert(Trie *node, char *word, int wordIndex);
bool trieSearch(Trie *obj, char *word);
bool trieStartsWith(Trie *obj, char *prefix);
void trieFree(Trie *obj);
TwoDArray search(Trie *node, const char *prefix);

/**
 * 1268. Search Suggestions System
 *
 * You are given an array of strings products and a string searchWord.
 *
 * Design a system that suggests at most three product names from products
 * after each character of searchWord is typed. Suggested products should have
 * common prefix with searchWord.
 * If there are more than three products with a common prefix return the three
 * lexicographically minimums products.
 *
 * Return a list of lists of the suggested products after each character
 * of searchWord is typed.
 * Note: Both returned array and *columnSizes array must be malloced,
 * assume caller calls free().
 */
char ***suggestedProducts(char **products, int productsSize, char *searchWord,
						  int *returnSize, int **returnColumnSizes)
{
	Trie *trie = trieCreate();
	qsort(products, productsSize, sizeof(char *), compare_strings);


	int i = -1;
	while (++i < productsSize)
		trieInsert(trie, products[i], i);

	TwoDArray arr = search(trie, searchWord);

	char ***to_return = (char ***) malloc(sizeof(char **) * arr.size);
	int *retColumnSizes = (int *) malloc(sizeof(int) * arr.size);

	i = -1;
	while (++i < (int)arr.size)
	{
		Array *a = &arr.arrays[i];

		char **strs = (char **) malloc(a->ss * sizeof(char *));
		int j = -1;
		while (++j < a->ss)
			strs[j] = strdup(products[a->arr[j]]);
		retColumnSizes[i] = (int)a->ss;
		free(a->arr);
		to_return[i] = strs;
	}
	free(arr.arrays);
	*returnSize = (int)arr.size;
	*returnColumnSizes = retColumnSizes;

	trieFree(trie);
	return (to_return);
}

int compare_strings(const void* a, const void* b)
{
	const char* str1 = *(const char**)a;
	const char* str2 = *(const char**)b;
	return strcmp(str1, str2); // Lexicographic comparison
}


static int *intdup(const int *arr, size_t len)
{
	if (arr == NULL || len == 0) return NULL;
	int *new_arr = (int *)malloc(len * sizeof(int));
	if (!new_arr) return NULL; // Memory allocation failed
	memcpy(new_arr, arr, len * sizeof(int));
	return new_arr;
}

static Array arraydup(Array *to_clone)
{
	return (Array){
		.arr = intdup(to_clone->arr, to_clone->size),
		.size = to_clone->size,
		.ss = to_clone->ss
	};
}

TwoDArray search(Trie *node, const char *prefix)
{
	size_t prefixLen = strlen(prefix);

	TwoDArray results;
	results.arrays = (Array *) calloc(prefixLen, sizeof(Array));
	results.size = prefixLen;

	ssize_t i = -1;
	while (++i < (int) prefixLen)
	{
		int index = *prefix++ - 'a';
		if (!node->children[index])
			break;
		node = node->children[index];
		results.arrays[i] = arraydup(&node->indices);
	}
	results.ss = 0;
	return (results);
}

static Trie *searchPrefix(Trie *node, const char *prefix)
{
	while (*prefix)
	{
		int index = *prefix++ - 'a';
		if (!node->children[index]) return NULL; // Prefix not found
		node = node->children[index]; // Move to next node
	}
	return node;
}

Trie *trieCreate()
{
	Trie *ret = (Trie *)calloc(1, sizeof(Trie));
	ret->indices.size = ARRAY_SIZE;
	ret->indices.arr = (int *) malloc(sizeof(int) * ARRAY_SIZE);
	return ret;
}

void trieInsert(Trie *node, char *word, int wordIndex)
{
	while (*word)
	{
		int index = *word++ - 'a';
		if (!node->children[index]) node->children[index] = trieCreate();
		node = node->children[index];

		if (node->indices.ss < 3)
			node->indices.arr[node->indices.ss++] = wordIndex;
	}
	node->is_end = true;
}

bool trieSearch(Trie *obj, char *word)
{
	Trie *node = searchPrefix(obj, word);
	return (node != NULL && node->is_end);
}

bool trieStartsWith(Trie *obj, char *prefix)
{
	Trie *node = searchPrefix(obj, prefix);
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
		free(current->indices.arr);
		free(current);
	}
}
