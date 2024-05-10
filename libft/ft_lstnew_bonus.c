/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:40:22 by hawild            #+#    #+#             */
/*   Updated: 2023/12/01 14:33:21 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*int main()
{
	int *data = (int *)malloc(sizeof(int));
	*data = 42;

	t_list *new_node = ft_lstnew(data);
	if (new_node)
	{
		printf("Content of the new node:%d\n", *((int *)new_node->content));
		free(new_node->content);
		free(new_node);
	}
	else
		printf("Error creating node\n");
	return (0);
}*/