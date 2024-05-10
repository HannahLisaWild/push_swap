/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:49:56 by hawild            #+#    #+#             */
/*   Updated: 2023/12/04 18:52:49 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	delete_content(void *content)
{
	free(content);
}*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}

/*int main()
{
	t_list *my_list = NULL;

	int *data1 = (int *)malloc(sizeof(int));
	int *data2 = (int *)malloc(sizeof(int));
	int *data3 = (int *)malloc(sizeof(int));

	*data1 = 1;
	*data2 = 2;
	*data3 = 3;

	t_list *node1 = ft_lstnew(data1);
	t_list *node2 = ft_lstnew(data2);
	t_list *node3 = ft_lstnew(data3);

	ft_lstadd_front(&my_list, node3);
	ft_lstadd_front(&my_list, node2);
	ft_lstadd_front(&my_list, node1);

	printf("list before deletion of second node:\n");
	t_list *current = my_list;
	while (current)
	{
		printf("%d ", *((int *)(current->content)));
		current = current->next;
	}
	printf("\n");

	ft_lstdelone(node2, delete_content);
	node1->next = node3;

	printf("list after deletion of second node:\n");
	t_list *tmp = my_list;
	while (tmp)
	{
		printf("%d ", *((int *)(tmp->content)));
		tmp = tmp->next;
	}
	printf("\n");

	while (my_list)
	{
		t_list *temp = my_list;
		my_list = my_list->next;
		free(temp->content);
		free(temp);
	}

	return (0);
}*/