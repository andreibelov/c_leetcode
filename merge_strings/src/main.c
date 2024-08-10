#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *mergeAlternately(const char *word1, const char *word2)
{

	char	*new,*onew = NULL;
	size_t	len1, len2, maxlen;

	if (!word1 || !word2)
		return (NULL);
	len1 = strlen(word1);
	len2 = strlen(word2);
	maxlen = len1 >= len2 ? len1 : len2;
	onew = (char *)malloc(sizeof(char) * (maxlen * 2 + 1));
	new = onew;
	if (!new)
		return (NULL);
	if (len1 >= len2) {
		while (*word2) {
			*new++ = *word1++;
			*new++ = *word2++;
		}
		while (*word1)
			*new++ = *word1++;
	}
	else {
		while (*word1) {
			*new++ = *word1++;
			*new++ = *word2++;
		}
		while (*word2)
			*new++ = *word2++;
	}
	*new = '\0';
	return (onew);
}

/**
 * You are given two strings word1 and word2.
 * Merge the strings by adding letters in alternating order,
 * starting with word1. If a string is longer than the other,
 * append the additional letters onto the end of the merged string.
 */
int main(void) {

	char *new;
	printf("Hello, World!\n");
	new = mergeAlternately("abc", "pqr");
	printf("%s\n", new);
	free(new);
	return (EXIT_SUCCESS);
}
