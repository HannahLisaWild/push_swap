/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:57:06 by hawild            #+#    #+#             */
/*   Updated: 2024/05/10 13:02:31 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../include/push_swap.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list 
{
    int value;
    int index;
    struct s_list *next;
}            t_list;

int	swap(t_list **head)
{
	t_list *temp;
	
	if (*head == NULL || (*head)->next == NULL)
		return (-1);
	else
	{
		temp = (*head)->next;
		(*head)->next = temp->next;
		temp->next = *head;
		*head = temp;
	}
	return (0);
}

int	sa(t_list **stack_a)
{
	if (swap(stack_a) != 0)
		return (-1);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (swap(stack_b) != 0)
		return (-1);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (swap(stack_a) != 0 || swap(stack_b) != 0)
		return (-1);
	return (0);
}

int	rotate(t_list **head)
{
	t_list *last;
	
	if (*head == NULL || (*head)->next == NULL)
		return (-1);
	else
	{
		last = *head;
		last = ft_lstlast(*head);
		if (last->next == NULL)
		{
			last->next = *head;
			*head = (*head)->next;
			last->next->next = NULL;
		}
	}
	return (0);
}

int ra(t_list **stack_a)
{
	if (rotate(stack_a) != 0)
		return (-1);
	return (0);
}

int rb(t_list **stack_b)
{
	if (rotate(stack_b) != 0)
		return (-1);
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (rotate(stack_a) != 0 || rotate(stack_b) != 0)
		return (-1);
	return (0);
}

int	rrotate(t_list **head)
{
	t_list *last;
	t_list *new_last;
	
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
	return (0);
}

int rra(t_list **stack_a)
{
	if (rrotate(stack_a) != 0)
		return (-1);
	return (0);
}

int rrb(t_list **stack_b)
{
	if (rrotate(stack_b) != 0)
		return (-1);
	return (0);
}

int	push(t_list **src_stack, t_list **dest_stack)
{
	t_list *head_src;
	t_list *temp;
	t_list *new_node;
	int value;

	if ((*src_stack) == NULL)
		return (-1);
	head_src = *src_stack;
	temp = *src_stack;
	value = temp->value;
	*src_stack = head_src->next;
	free(head_src);
	new_node = ft_lstnew(value);
	if ((*dest_stack) == NULL)
	{
		*dest_stack = new_node;
		(*dest_stack)->next = NULL;
	}
	else
	{
		new_node->next = (*dest_stack);
		*dest_stack = new_node;
	}
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) != 0)
		return (-1);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) != 0)
		return (-1);
	return (0);
}