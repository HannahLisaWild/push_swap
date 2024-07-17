/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:55:16 by hawild            #+#    #+#             */
/*   Updated: 2024/07/17 12:20:56 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

t_list	*put_in_stack(int ac, char **av)
{
	t_list	*head;
	int		i;
	int		value;
	char	**temp;

	head = NULL;
	i = 0;
	temp = av;
	if (ac == 2)
		temp = ft_split(av[1], ' ');
	else
		i = 1;
	while (temp[i])
	{
		value = ft_atoi(temp[i]);
		ft_lstadd_back(&head, value);
		i++;
	}
	if (ac == 2)
		free_args(temp);
	return (head);
}

void	free_stack(t_list **stack)
{
	t_list	*current;
	t_list	*temp;
	float	lst_size;

	current = *stack;
	lst_size = ft_lstsize(*stack);
	while (lst_size > 0)
	{
		temp = current;
		current = current->next;
		free(temp);
		lst_size--;
	}
	free(current);
}

int	sorted(t_list **stack_a)
{
	t_list	*head;
	int		i;
	float	list_size;

	i = 1;
	head = *stack_a;
	while (head->next != NULL)
	{
		if (head->value < head->next->value)
			i++;
		head = head->next;
	}
	list_size = ft_lstsize(*stack_a);
	if ((int)list_size == i)
		return (0);
	return (-1);
}
