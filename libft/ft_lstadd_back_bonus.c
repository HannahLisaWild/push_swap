/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:32:09 by hawild            #+#    #+#             */
/*   Updated: 2023/12/12 16:22:32 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

/*int main()
{
	// Create a list
	t_list *my_list = NULL;

	// Create nodes with integer content
	int *data1 = (int *)malloc(sizeof(int));
	int *data2 = (int *)malloc(sizeof(int));
	int *data3 = (int *)malloc(sizeof(int));
	int *data4 = (int *)malloc(sizeof(int));
	int *data5 = (int *)malloc(sizeof(int));
	int *data6 = (int *)malloc(sizeof(int));

	*data1 = 1;
	*data2 = 2;
	*data3 = 3;
	*data4 = 4;
	*data5 = 5;
	*data6 = 6;

	// Create nodes using ft_lstnew and add them to the front of the list
	t_list *node1 = ft_lstnew(data1);
	t_list *node2 = ft_lstnew(data2);
	t_list *node3 = ft_lstnew(data3);
	t_list *node4 = ft_lstnew(data4);
	t_list *node5 = ft_lstnew(data5);
	t_list *node6 = ft_lstnew(data6);

	ft_lstadd_front(&my_list, node3);
	ft_lstadd_front(&my_list, node2);
	ft_lstadd_front(&my_list, node1);
	ft_lstadd_back(&my_list, node4);
	ft_lstadd_back(&my_list, node5);
	ft_lstadd_back(&my_list, node6);


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