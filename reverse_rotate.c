/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:32:56 by hawild            #+#    #+#             */
/*   Updated: 2024/07/17 12:13:48 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrotate(t_list **head)
{
	t_list	*last;
	t_list	*new_last;

	if (*head == NULL || (*head)->next == NULL)
		return (-1);
	else
	{
		last = ft_lstlast(*head);
		new_last = *head;
		while (new_last->next->next != NULL)
			new_last = new_last->next;
		last->next = *head;
		*head = last;
		new_last->next = NULL;
	}
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (rrotate(stack_a) != 0 || rrotate(stack_b) != 0)
		return (-1);
	write(1, "rrr\n", 4);
	return (0);
}

int	rra(t_list **stack_a)
{
	if (rrotate(stack_a) != 0)
		return (-1);
	write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (rrotate(stack_b) != 0)
		return (-1);
	write(1, "rrb\n", 4);
	return (0);
}
