/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:11:04 by hawild            #+#    #+#             */
/*   Updated: 2023/12/12 15:14:06 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
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

	t_list *last_node = ft_lstlast(my_list);
	printf("last node: %d", *((int *)last_node->content));

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