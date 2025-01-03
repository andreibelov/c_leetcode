/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallestInfiniteSet.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:02:54 by abelov            #+#    #+#             */
/*   Updated: 2025/01/03 21:03:26 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct SmallestInfiniteSet SmallestInfiniteSet;

/**
 * 2336. Smallest Number in Infinite Set
 *
 * Implement the SmallestInfiniteSet class:
 * SmallestInfiniteSet()
 * 	Initializes the SmallestInfiniteSet object to contain all positive integers.
 * int popSmallest()
 * 	Removes and returns the smallest integer contained in the infinite set.
 * void addBack(int num)
 * 	Adds a positive integer num back into the infinite set,
 * 	if it is not already in the infinite set.
 */
SmallestInfiniteSet *smallestInfiniteSetCreate();

/**
 * Your SmallestInfiniteSet struct will be instantiated and called as such:
 * SmallestInfiniteSet* obj = smallestInfiniteSetCreate();
 * int param_1 = smallestInfiniteSetPopSmallest(obj);
 * smallestInfiniteSetAddBack(obj, num);
 * smallestInfiniteSetFree(obj);
*/

#ifdef DOSIMPLE

#define ONE_THOUSAND 1000

typedef struct SmallestInfiniteSet
{
	int *arr;
}	SmallestInfiniteSet;

SmallestInfiniteSet *smallestInfiniteSetCreate()
{
	SmallestInfiniteSet *set = (SmallestInfiniteSet *)malloc(sizeof(SmallestInfiniteSet));
	set->arr = calloc(sizeof(int), ONE_THOUSAND + 1);  /* 1 is absent */
	return (set);
}

int smallestInfiniteSetPopSmallest(SmallestInfiniteSet *obj)
{
	int res = -1;

	int i = 0;
	while(++i <= ONE_THOUSAND)
	{
		if(!obj->arr[i])
		{
			res = i; /* the least index */
			obj->arr[i] = 1;
			break;
		}
	}
	if(res == -1) return (0);
	return (res);
}

void smallestInfiniteSetAddBack(SmallestInfiniteSet *obj, int num)
{
	obj->arr[num] = 0;
}

void smallestInfiniteSetFree(SmallestInfiniteSet *obj)
{
	free(obj->arr);
	free(obj);
}

#else

typedef struct SmallestInfiniteSet
{
	int *heap;
	int size;
	unsigned long long *bitmap;
}	SmallestInfiniteSet;

#define ONE_THOUSAND 1000

int parent(int i);
void swap(int *a, int *b);
int leftChild(int i);
int rightChild(int i);
void shiftUp(int *heap, int i);
void shiftDown(int *heap, int *size, int i);
void heapInsert(int *heap, int *size, int k);
int extractMax(int *heap, int *size);

SmallestInfiniteSet *smallestInfiniteSetCreate()
{
	SmallestInfiniteSet *set = (SmallestInfiniteSet *)malloc(sizeof(SmallestInfiniteSet));
	set->heap = malloc(sizeof(int) * ONE_THOUSAND);
	set->bitmap = calloc(sizeof(unsigned long long), (ONE_THOUSAND / 64 + 1));   /* 1 is absent */
	int i = -1;
	while (++i < ONE_THOUSAND)
		set->heap[i] = i + 1;
	set->size = ONE_THOUSAND - 1;
	return set;
}

int smallestInfiniteSetPopSmallest(SmallestInfiniteSet *obj)
{
	int val = extractMax(obj->heap, &(obj->size));
	int index = val / 64, off = val % 64;
	obj->bitmap[index] |= 1ULL << off;  /* mark 1 for absent */
	return val;
}

void smallestInfiniteSetAddBack(SmallestInfiniteSet *obj, int num)
{
	int index = num / 64, off = num % 64;
	if (obj->bitmap[index] & 1ULL << off)
		heapInsert(obj->heap, &(obj->size), num);
}

void smallestInfiniteSetFree(SmallestInfiniteSet *obj)
{
	free(obj->heap);
	free(obj->bitmap);
	free(obj);
}

/**
 * Function to swap two elements
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * Function to return the index of the parent node of a given node
 */
int parent(int i)
{
	return (i - 1) / 2;
}

/**
 * Function to return the index of the left child of the given node
 */
int leftChild(int i)
{
	return ((2 * i) + 1);
}

/**
 * Function to return the index of the right child of the given node
 */
int rightChild(int i)
{
	return ((2 * i) + 2);
}

/**
 * Function to shift up the node in order to maintain the heap property
 */
void shiftUp(int *heap, int i)
{
	while (i > 0 && heap[i] < heap[parent(i)])
	{
		/* Swap parent and current node */
		swap(&heap[parent(i)], &heap[i]);
		/* Update i to parent of i */
		i = parent(i);
	}
}

/**
 * Function to shift down the node in order to maintain the heap property
 */
void shiftDown(int *heap, int *size, int i)
{
	int maxIndex = i;
	// Left Child
	int l = leftChild(i);
	if (l <= *size && heap[l] < heap[i])
		maxIndex = l;
	// Right Child
	int r = rightChild(i);
	if (r <= *size && heap[r] < heap[maxIndex])
		maxIndex = r;
	// If i not same as maxIndex
	if (i != maxIndex)
	{
		swap(&heap[i], &heap[maxIndex]);
		shiftDown(heap, size, maxIndex);
	}
}

/**
 * Function to insert a new element in the Binary Heap
 */
void heapInsert(int *heap, int *size, int k)
{
	/* check if it exists */
	int i = -1;
	while (++i <= *size)
	{
		/* exist */
		if (heap[i] == k)
			return;
	}
	heap[++(*size)] = k;
	/* Shift Up to maintain heap property */
	shiftUp(heap, *size);
}

/**
 * Function to extract the element with maximum priority
 */
int extractMax(int *heap, int *size)
{
	int result = heap[0];

	/* Replace the value at the root with the last leaf */
	heap[0] = heap[(*size)--];

	/* Shift down the replaced element to maintain the heap property */
	shiftDown(heap, size, 0);
	return result;
}

#endif
