/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:56:36 by hawild            #+#    #+#             */
/*   Updated: 2024/05/07 17:53:15 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// typedef struct s_test{
//     int flag;
// } t_test;

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (n == 0)
		return (len);
	if (n != 0)
	{
		while (src[i] != '\0' && i < (n - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}



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

void	error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}


int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	nb;

	nb = 0;
	sign = 1;
	i = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
	{
		i++;
	}
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (sign * nb);
}

int is_numeric(char *str)
{
    int i;

    i = 0;
    if (ft_atoi(str) < -2147483648 || ft_atoi(str) > 2147483647)
        return (1);
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (1);
        i++;
    }
    return (0);
}

int check_for_doubles(char **str, char *s, int i)
{
    i++;
    while (str[i])
    {
        if (ft_atoi(str[i]) == (ft_atoi(s)))
            return (1);
        i++;
    }
    return (0);
}

void    free_args(char **args)
{
    int i;

    i = 0;
    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
}

void check_args(int ac, char **av)
{
    char **args; 
    int i;

    if (ac == 2)
    {
        i = 0;
        args = ft_split(av[1], ' ');
    }
    else
    {
        i = 1;
        args = av;
    }
    while (args[i])
    {
        if (is_numeric(args[i]) == 1)
            error();
        if (check_for_doubles(args, args[i], i) == 1)
            error();
        i++;
    }
    if (ac == 2)
        free_args(args);
}

int main(int ac, char **av)
{
    int **args;
    int i;
    
    if (ac > 1)
    {
        check_args(ac, av);
    }

    return (0);
}