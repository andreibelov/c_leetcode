/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:49:51 by abelov            #+#    #+#             */
/*   Updated: 2024/12/23 23:49:52 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode75.h"

/**
 * 208. Implement Trie (Prefix Tree)
 *
 * Constraints:
 * 	1 <= word.length, prefix.length <= 2000
 * 	word and prefix consist only of lowercase English letters.
 * 	At most 3 * 104 calls in total will be made to insert,
 * 	search, and startsWith.
 */
typedef struct Trie Trie;
struct Trie
{
	Trie *children[26];
	bool is_end;
};
Trie *trieCreate();
void trieInsert(Trie *node, char *word);
bool trieSearch(Trie *obj, char *word);
bool trieStartsWith(Trie *obj, char *prefix);
void trieFree(Trie *obj);

typedef enum op
{
	insert = 0,
	search,
	startsWith,
	max_op
} t_op;

struct s_input
{
	Array *cmd;
	StringArray *wrd;
	Array *expected;
};

int ft_do_test(struct s_input *input)
{
	Array result;
	Array *sa = input->cmd;
	StringArray *wrd = input->wrd;
	int check_val;
	Trie *trie = trieCreate();

	result = (Array) {.size = input->expected->size, .iter = 0,
		.arr = (int *) calloc(input->expected->size, sizeof(int))};
	sa->iter = -1;
	while (++(sa->iter) < sa->size)
	{
		if (sa->arr[sa->iter] == insert)
		{
			trieInsert(trie, wrd->arr[sa->iter]);
			result.arr[result.iter++] = null;
		}
		else if (sa->arr[sa->iter] == search)
			result.arr[result.iter++] = trieSearch(trie, wrd->arr[sa->iter]);
		else if (sa->arr[sa->iter] == startsWith)
			result.arr[result.iter++] = trieStartsWith(trie, wrd->arr[sa->iter]);
	}
	trieFree(trie);

	check_val = (input->expected->size == result.size);
	if (!check_val)
		printf("got array of size [\"%d\"] whilst \"%d\" was to be expected\n",
			   result.size, input->expected->size);
	else
	{
		check_val = (arraycmp(&result, input->expected) == 0);
		if (!check_val)
		{
			check(check_val);
			printf("got ");
			ft_print_array(&result, " whilst ");
			ft_print_array(input->expected, "");
			printf(" was to be expected \n");
		}
		free(result.arr);
	}
	check(check_val);
	return (0);
}

int main(void)
{
	int				i;
	struct s_input	inputs[] = {
		{
			.cmd = &(Array){.arr =  (int []){ insert, search, search, startsWith, insert, search, }, .size = 6},
			.wrd = &(StringArray){(char **) (const char *[6]){ "apple","apple", "app", "app", "app", "app"}, .size = 6},
			.expected = &(Array){ .arr = (int []){null,true,false,true,null,true}, .size = 6}
		}
	};

	signal(SIGSEGV, sigsegv);
	i = -1;
	while (++i < (int) (sizeof(inputs) / sizeof(inputs[0])))
		ft_do_test(&inputs[i]);
	return (EXIT_SUCCESS);
}

