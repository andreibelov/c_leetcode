/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcdOfStrings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:35:03 by abelov            #+#    #+#             */
/*   Updated: 2024/08/07 09:35:04 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stddef.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	size_t	buff_size;
	const size_t len1 = strlen(s1);
	const size_t len2 = strlen(s2);

	buff_size = len1 + len2 + 1;
	new = (char *)malloc(buff_size);
	if (!new)
		return (NULL);
	*new = '\0';
	strncpy(new, s1, buff_size);
	strncat(new, s2, buff_size);
	free((void *)s1);
	return (new);
}

int get_min(int a, int b)
{
	int	result;

	if (a < b)
		result = a;
	else
		result = b;
	return result;
}

int	gcd(int a, int b)
{
	int res = get_min(a, b) + 1;

	while (--res > 0)
		// Check if both a and b are divisible by result
		if (a % res == 0 && b % res == 0)
			break;
	return (res);
}

/**
 * For two strings s and t, we say "t divides s" if and only if s = t + t + t +
 * ... + t + t (i.e., t is concatenated with itself one or more times).
 * Given two strings str1 and str2, return the largest string x such
 * that x divides both str1 and str2.
 */
char	*gcdOfStrings(const char *s1, const char *s2)
{
	char 	*new1;
	char 	*new2;
	size_t	gcdLength;

	new1 = ft_strjoin(strdup(s1), s2);
	new2 = ft_strjoin(strdup(s2), s1);

	if (strcmp(new1, new2) != 0)
		return (strdup(""));
	free(new1);
	free(new2);
	gcdLength = gcd((int)strlen(s1), (int)strlen(s2));
	return (strndup(s1, gcdLength));
}
