/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equalPairs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:23:30 by abelov            #+#    #+#             */
/*   Updated: 2024/08/25 17:23:31 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <alloca.h>
#include <malloc.h>

/**
 * 2352. Equal Row and Column Pairs
 * Given a 0-indexed n x n integer matrix grid, return the number of pairs
 * (ri, cj) such that row ri and column cj are equal.
 * A row and column pair is considered equal if they contain the same elements
 * in the same order (i.e., an equal array).
 *
 * Constraints:
 *  n == grid.length == grid[i].length
 *  1 <= n <= 200
 *  1 <= grid[i][j] <= 105
 */
int equalPairs(int **grid, int gridSize, const int *gridColSize);

#if defined USE_HASHTABLE && !defined USE_STRONG_HASH

#define MOD1 4007
#define MOD2 3967

int equalPairs(int **grid, const int gridSize, const int *gridColSize)
{
	int count = 0;
	int i, j;
	int *table1 = (int *) alloca(gridSize * sizeof(int));
	int *table2 = (int *) alloca(gridSize * sizeof(int));

	i = -1;
	while (++i < gridSize)
	{
		table1[i] = 0;
		table2[i] = 0;
	}

	i = -1;
	while (++i < gridSize)
	{
		int mult;
		j = -1;
		while (++j < gridSize)
		{
			/**
			 * Adding 1 is to not ignore the first element of each row/column.
			 * Modulo is to prevent overflow and increase randomness.
			 * Using square of (j + 1) is to amplify difference between
			 * elements with the same value in different positions.
			 * Using different moduli for mult and the final hash value adds
			 * randomness and helps in spreading out the possible hash values.
			 */
			mult = (j + 1) * (j + 1) % MOD1;
			table1[i] += (grid[i][j] * mult) % MOD2;
			table2[i] += (grid[j][i] * mult) % MOD2;
		}
	}
	i = -1;
	while (++i < gridSize)
	{
		j= -1;
		while (++j < gridSize)
			if (table1[i] == table2[j]) count++;
	}
	return (count);
	/* grid is a n x n square matrix, so gridSize is equal to
	 * every element in gridColSize */
	(void)gridColSize;
}
#elif defined USE_STRONG_HASH && !defined GREEDY

/**
 * Base: The choice of base (e.g., 31, 37, or any prime number) is critical.
 * It determines how the sequence of elements is encoded.
 * Modulo (mod): This prevents overflow and helps in distributing hash values
 * uniformly. A large prime number is usually chosen.
 *
 * Uniqueness:
 * 	The polynomial rolling hash method is effective in distinguishing between
 * 	sequences that are permutations of each other because it takes into account
 * 	both the values and their positions with varying powers of the base.
 */

#define BASE1 31
#define MODULO1 (1e9 + 9)
#define BASE2 37
#define MODULO2 (1e9 + 7)
int polynomial_rolling_hash(const int *arr, int size, int base, int mod);

/**
 * We can combine multiple different hash functions to reduce the likelihood
 * of collisions. For instance, we can calculate two or more hash values using
 * different bases and then combine them (e.g., using XOR or concatenation).
 *
 * This way, even if one hash function produces the same hash for two
 * different rows/columns, the chances of both producing the same
 * combined hash are significantly reduced.
 */
int combined_hash(int *arr, int size)
{
	int hash1 = polynomial_rolling_hash(arr, size, BASE1, (int)(MODULO1));
	int hash2 = polynomial_rolling_hash(arr, size, BASE2, (int)(MODULO2));
	return hash1 ^ hash2;  // or (hash1 << 16) | hash2
}

int polynomial_rolling_hash(const int *arr, int size, int base, int mod)
{
	int i;
	long long hash_value = 0;
	long long power = 1;

	i = -1;
	while (++i < size)
	{
		hash_value = (hash_value + arr[i] * power) % mod;
		power = (power * base) % mod;
	}
	return ((int)hash_value);
}

int equalPairs(int **grid, const int gridSize, const int *gridColSize)
{
	int count = 0;
	int i, j;
	int *rowHashes = (int *) alloca(gridSize * sizeof(int));
	int *colHashes = (int *) alloca(gridSize * sizeof(int));
	int **colArr = (int **) alloca(gridSize * sizeof(int *));

	/* OPTIONAL: fill with zeroes
	i = -1;
	while (++i < gridSize)
	{
		rowHashes[i] = 0;
		colHashes[i] = 0;
	} */

	i = -1;
	while (++i < gridSize) /* Hash rows */
		rowHashes[i] = polynomial_rolling_hash(grid[i], gridSize, BASE1, MODULO1);

	/**
	 * alloca is non-standard function that allocates memory on the stack during
	 * runtime. It is not part of the C standard library.
	 *
	 * Using alloca in a loop requires caution
	 * because it allocates memory on the stack, and this memory is only reclaimed
	 * when the function exits.
	 *
	 * In comparison, the memory for a Variable Length Arrays (VLAs)
	 * is automatically managed and freed when it goes out of scope
	 * (e.g., at the end of the block or function in which it is declared).
	 */
	i = -1;
	while (++i < gridSize)  /* Hash columns */
	{
		j = -1;
		colArr[i] = (int *)alloca(gridSize * sizeof(int));
		while (++j < gridSize)
			colArr[i][j] = grid[j][i]; /* Optional: use combined_hash */
		colHashes[i] = polynomial_rolling_hash(colArr[i], gridSize, BASE1, MODULO1);
	}
	i = -1;
	while (++i < gridSize)  /* Compare row and column hashes */
	{
		j = -1;
		while (++j < gridSize)
			if (rowHashes[i] == colHashes[j])
			{
				/* Optional: Direct comparison for safety */
//				if (!memcmp(grid[i], colArr[j], gridSize * sizeof(int))) count++;
				count++;
			}
	}
	return (count);
	(void)gridColSize;
}

#else
int equalPairs(int **grid, const int gridSize, const int *gridColSize)
{
	int i,j,k;
	int count = 0;
	i = -1;
	while (++i < gridSize)
	{
		j= -1;
		while (++j < gridSize)
		{
			int tmp[gridSize];
			k = -1;
			while (++k < gridColSize[j])
				tmp[k] = (grid[k])[j];
			if (!memcmp(grid[i], tmp, gridSize * sizeof(int))) count++;
		}
	}
	return (count);
}
#endif
