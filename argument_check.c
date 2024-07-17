/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:35:51 by hawild            #+#    #+#             */
/*   Updated: 2024/07/17 11:28:04 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	nb;

	nb = 0;
	sign = 1;
	i = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
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

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (ft_atoi(str) < INT_MIN || ft_atoi(str) > INT_MAX)
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

static int	check_for_doubles(char **str, char *s, int i)
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

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	check_args(int ac, char **av)
{
	char	**args;
	int		i;

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
