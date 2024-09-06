/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathSum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:44:39 by abelov            #+#    #+#             */
/*   Updated: 2024/09/02 19:44:39 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>

typedef struct TreeNode TreeNode;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
};

/**
 * 437. Path Sum III
 *
 * Given the root of a binary tree and an integer targetSum, return the number
 * of paths where the sum of the values along the path equals targetSum.
 *
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards (i.e., traveling only from parent nodes to child nodes).
 */
int pathSum(struct TreeNode *root, int targetSum);

#if defined USE_RECURSIVE

int sumFrom(struct TreeNode *node, int sum)
{
	int number_of_paths = 0;

	if (node == NULL) return 0;
	sum -= node->val;
	number_of_paths += !sum ? 1 : 0;
	number_of_paths += sumFrom(node->left, sum);
	number_of_paths += sumFrom(node->right, sum);
	return number_of_paths;
}

int pathSum(struct TreeNode *root, int sum)
{
	if (!root) return 0;
	return sumFrom(root, sum) +
		   pathSum(root->left, sum) +
		   pathSum(root->right, sum);
}

#elif !defined STATIC_HASHMAP

#define HASHMAP_SIZE 1000033 // Size of the hash map
#define HASH_MOD 100000007  // Large prime modulus for hashing
#define STACK_SIZE 100000   // Size of the stack

unsigned int hash(long key)
{
	/* Ensure non-negative result */
	unsigned int result = (key % HASH_MOD + HASH_MOD) % HASH_MOD;
	return (unsigned int) (result % HASHMAP_SIZE);
}

typedef struct s_stack_el
{
	struct TreeNode *node;
	long sum;
	int isBacktracking;
} stack_el;

int pathSum(struct TreeNode *root, int sum)
{
	struct TreeNode *node;
	stack_el stack[STACK_SIZE];
	int prefixSumCounts[HASHMAP_SIZE] = {0};
	int sp = 0;
	int result = 0;

	if (root)
		stack[sp++] = (stack_el) {.node = root, .sum = 0, .isBacktracking = 0};

	/* Handle base case for prefix sum == target sum */
	prefixSumCounts[hash(0)] = 1;

	while (sp)
	{
		stack_el *el = &stack[sp - 1];

		if (el->isBacktracking)
		{
			/* Backtracking: decrement the prefix sum count */
			prefixSumCounts[hash(el->sum)]--;
			sp--;
		}
		else
		{
			node = el->node;
			el->sum += node->val;

			/* Count paths that end at the current node */
			result += prefixSumCounts[hash(el->sum - sum)];

			prefixSumCounts[hash(el->sum)]++;

			/* Mark the current node for backtracking */
			el->isBacktracking = 1;

			/* Push right and left children to the stack */
			if (node->right)
				stack[sp++] = (stack_el) {.node = node->right,
					.sum = el->sum, .isBacktracking = 0};
			if (node->left)
				stack[sp++] = (stack_el) {.node = node->left,
					.sum = el->sum, .isBacktracking = 0};
		}
	}
	return (result);
}


#elif !defined USE_UTHASH

#include <uthash.h>

typedef struct
{
	long key;
	int value;
	UT_hash_handle hh;
}	hash_entry;

void pathSumRec(struct TreeNode *root, int targetSum,
				long currentSum, int *count, hash_entry **table)
{
	long key;
	hash_entry *entry;
	currentSum += root->val;
	if (currentSum == targetSum) (*count)++;
	/**
	 * currentSum only increases not decreases.
	 * It only record the sum from the root to the current node.
	 * For the end of those path sums with only middle nodes,
	 * currentSum = targetSum + prefixSum where prefixSum
	 * is the sum from the root to the beginning of the
	 * middle path.
	 * Thus, these paths exist iff prefixSums exist
	 * iff (currentSum - targetSum)s exist.
	 * If they do exist, add them to the count.
	 */
	key = currentSum - targetSum;
	HASH_FIND(hh, *table, &key, sizeof(long), entry);
	if (entry)
		(*count) += entry->value;
	/**
	 * check if currentSum already exists.
	 * If not, create it.
	 */
	HASH_FIND(hh, *table, &currentSum, sizeof(long), entry);
	if (!entry)
	{
		entry = (hash_entry *)malloc(sizeof(hash_entry));
		if (!entry) return;
		entry->key = currentSum;
		HASH_ADD(hh, *table, key, sizeof(long), entry);
		entry->value = 0;
	}
	entry->value++;
	if (root->left)
		pathSumRec(root->left, targetSum, currentSum, count, table);
	if (root->right)
		pathSumRec(root->right, targetSum, currentSum, count, table);
	/**
	 * For those nodes below this node and in this subtree, there exists
	 * a prefixSum as the currentSum here.
	 * However, for those not in this subtree, the path shouldn't be counted in,
	 * and directly return will make this path still available to others.
	 * While only descendants of the current node can have this path as
	 * a prefix, this path should be deleted before return to other subtrees.
	 */
	entry->value--;
}

int pathSum(struct TreeNode *root, int targetSum)
{
	hash_entry *table = NULL, *i, *tmp;
	int res = 0;
	if (root)
		pathSumRec(root, targetSum, 0, &res, &table);
	HASH_ITER(hh, table, i, tmp) {
		HASH_DEL(table, i);
		free(i);
	}
	return res;
}

#elif !defined CHAT_VERSION

#include <stdio.h>
#include <stdlib.h>

#define HASHMAP_SIZE 1000033 // Adjust size based on expected range of sums

#define HASH_MOD 100000007  // Large prime modulus for hashing
#define STACK_SIZE 100000   // Size of the stack

unsigned int hash(long key)
{
	/* Ensure non-negative result */
	unsigned int result = (key % HASH_MOD + HASH_MOD) % HASH_MOD;
	return ((unsigned int) result % HASHMAP_SIZE);
}

int pathSumFrom(struct TreeNode *node, int sum,
				long currentSum, int *prefixSumCounts)
{
	int result;
	if (!node) return 0;

	currentSum += node->val;
	result = prefixSumCounts[hash(currentSum - sum)];
	prefixSumCounts[hash(currentSum)]++;

	result += pathSumFrom(node->left, sum, currentSum, prefixSumCounts);
	result += pathSumFrom(node->right, sum, currentSum, prefixSumCounts);

	prefixSumCounts[hash(currentSum)]--;

	return result;
}

int pathSum(struct TreeNode *root, int sum)
{
	int prefixSumCounts[HASHMAP_SIZE] = {0};
	/* handle the case when currentSum == sum */
	prefixSumCounts[hash(0)] = 1;
	return pathSumFrom(root, sum, 0, prefixSumCounts);
}


#else

#include <stdlib.h>

typedef struct HashMapNode
{
	int key;
	int value;
	struct HashMapNode *next;
} HashMapNode;

typedef struct
{
	HashMapNode **buckets;
	int bucketCount;
} HashMap;

#define HASH_MOD 100000007  // Large prime modulus for hashing
#define STACK_SIZE 100000   // Size of the stack

// HashMap functions
unsigned int hash(long key, int bucketCount)
{
	/* Ensure non-negative result */
	unsigned int result = (key % HASH_MOD + HASH_MOD) % HASH_MOD;
	return (unsigned int) (result % bucketCount);
}

HashMap *createHashMap(int bucketCount)
{
	int i = -1;
	HashMap *map = (HashMap *) malloc(sizeof(HashMap));
	map->buckets = (HashMapNode **) malloc(bucketCount * sizeof(HashMapNode *));

	while (++i < bucketCount)
		map->buckets[i] = NULL;
	map->bucketCount = bucketCount;
	return map;
}

void put(HashMap *map, long key, int value)
{
	unsigned int index = hash(key, map->bucketCount);
	HashMapNode *node = map->buckets[index];
	while (node)
	{
		if (node->key == key)
		{
			node->value = value;
			return;
		}
		node = node->next;
	}
	node = (HashMapNode *) malloc(sizeof(HashMapNode));
	*node = (HashMapNode){.key = key, . value = value, .next = map->buckets[index]};
	map->buckets[index] = node;
}

int get(HashMap *map, long key)
{
	unsigned int index = hash(key, map->bucketCount);
	HashMapNode *node = map->buckets[index];
	while (node)
	{
		if (node->key == key)
			return node->value;
		node = node->next;
	}
	return 0;
}

void freeHashMap(HashMap *map)
{
	int i =-1;
	HashMapNode *node;
	HashMapNode *temp;

	while (++i < map->bucketCount)
	{
		node = map->buckets[i];
		while (node)
		{
			temp = node;
			node = node->next;
			free(temp);
		}
	}
	free(map->buckets);
	free(map);
}

long pathSumFrom(struct TreeNode *node, int sum, long currentSum, HashMap *prefixSumCounts)
{
	if (!node) return 0;
	long result;

	currentSum += node->val;
	result = get(prefixSumCounts, currentSum - sum);

	put(prefixSumCounts, currentSum, get(prefixSumCounts, currentSum) + 1);

	result += pathSumFrom(node->left, sum, currentSum, prefixSumCounts);
	result += pathSumFrom(node->right, sum, currentSum, prefixSumCounts);

	put(prefixSumCounts, currentSum, get(prefixSumCounts, currentSum) - 1);

	return result;
}

int pathSum(struct TreeNode *root, int sum)
{
	int result;
	HashMap *prefixSumCounts = createHashMap(10000); // Adjust size if necessary
	put(prefixSumCounts, 0, 1); // To handle the case when currentSum == sum

	result = (int)pathSumFrom(root, sum, 0, prefixSumCounts);
	freeHashMap(prefixSumCounts);
	return result;
}

#endif
