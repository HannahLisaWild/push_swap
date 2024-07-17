/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:30:44 by hawild            #+#    #+#             */
/*   Updated: 2024/07/17 12:06:19 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_lstsize(t_list *lst)
{
	float	len;
	t_list	*tmp;

	len = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

void	print_list(t_list *head)
{
	t_list	*current;
	int		i;

	current = head;
	i = 0;
	while (current != NULL)
	{
		printf("%d\n", current->value);
		current = current->next;
		i++;
	}
}

t_list	*ft_lstnew(int value)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, int value)
{
	t_list	*last;
	t_list	*new_node;

	new_node = ft_lstnew(value);
	if (*lst == NULL)
		*lst = new_node;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new_node;
	}
}
