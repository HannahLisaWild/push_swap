/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:31:57 by hawild            #+#    #+#             */
/*   Updated: 2024/07/17 12:21:32 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_min(t_list **stack)
{
	t_list	*min;
	t_list	*current;
	int		i;

	current = *stack;
	min = *stack;
	i = 0;
	while (current->next)
	{
		current = current->next;
		if (current->value < min->value)
			min = current;
		i++;
	}
	return (min);
}

t_list	*get_max(t_list **stack)
{
	t_list	*max;
	t_list	*current;
	int		i;

	current = *stack;
	max = *stack;
	i = 0;
	while (current->next)
	{
		current = current->next;
		if (current->value > max->value)
			max = current;
		i++;
	}
	return (max);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

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
