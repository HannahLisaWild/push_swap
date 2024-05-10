/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:11:17 by hawild            #+#    #+#             */
/*   Updated: 2023/12/01 14:32:50 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

/*int main()
{
	// Create a list
	t_list *my_list = NULL;

	// Create nodes with integer content
	int *data1 = (int *)malloc(sizeof(int));
	int *data2 = (int *)malloc(sizeof(int));
	int *data3 = (int *)malloc(sizeof(int));

	*data1 = 1;
	*data2 = 2;
	*data3 = 3;

	// Create nodes using ft_lstnew and add them to the front of the list
	t_list *node1 = ft_lstnew(data1);
	t_list *node2 = ft_lstnew(data2);
	t_list *node3 = ft_lstnew(data3);

	ft_lstadd_front(&my_list, node3);
	ft_lstadd_front(&my_list, node2);
	ft_lstadd_front(&my_list, node1);

	// Print the contents of the list
	t_list *current = my_list;
	while (current)
	{
		printf("%d ", *((int *)(current->content)));
		current = current->next;
	}
	printf("\n");

	// Free allocated memory for the list nodes and their content
	while (my_list)
	{
		t_list *temp = my_list;
		my_list = my_list->next;
		free(temp->content);
		free(temp);
	}

	return (0);
}*/