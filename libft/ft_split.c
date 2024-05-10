/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:10:09 by hawild            #+#    #+#             */
/*   Updated: 2024/04/22 12:52:24 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_error(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	nb_words;

	if (!s[0])
		return (0);
	i = 0;
	nb_words = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_words++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_words++;
	return (nb_words);
}

static void	ft_next_word(char **next_word, size_t *next_word_len, char c)
{
	size_t	i;

	*next_word += *next_word_len;
	*next_word_len = 0;
	i = 0;
	while (**next_word && **next_word == c)
		(*next_word)++;
	while ((*next_word)[i])
	{
		if ((*next_word)[i] == c)
			return ;
		(*next_word_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	char	*next_word;
	size_t	next_word_len;
	size_t	i;

	if (!s)
		return (NULL);
	new = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!new)
		return (NULL);
	i = 0;
	next_word = (char *)s;
	next_word_len = 0;
	while (i < ft_word_count(s, c))
	{
		ft_next_word(&next_word, &next_word_len, c);
		new[i] = (char *)malloc(sizeof(char) * (next_word_len + 1));
		if (!new[i])
			return (ft_error(new));
		ft_strlcpy(new[i], next_word, next_word_len + 1);
		i++;
	}
	new[i] = NULL;
	return (new);
}

/*int	main(void)
{
	char	**tabstr;
	if (!(tabstr = ft_split("", 'z')))
		printf("NULL");
	else
		if (!tabstr[0])
			printf("ok\n");
	return (0);
}*/
/*
int	main(void)
 {
	// Example string
	char input[] = "This is a test string";

	// Character to split on
	char delimiter = ' ';

	// Call ft_split
	char **result = ft_split(input, delimiter);

	// Check if ft_split was successful
	if (result == NULL) {
		printf("ft_split failed\n");
		return (1);
	}

	// Print the 2D array
	int i = 0;
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}

	// Free the allocated memory
	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);

	return (0);
}*/

/*int main()
{
	char	*s = "      split       this for   me  !       ";
	char	**result = ft_split(s, ' ');
	char	**expected = (char*[6]){"split", "this", "for", "me", "!", NULL};
	if (strcmp(*result, *expected) == 0)
		printf("success");
	printf("\n");
	int i = 0;
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}
}*/