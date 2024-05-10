/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_to_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:57:15 by hawild            #+#    #+#             */
/*   Updated: 2024/05/10 13:00:46 by hawild           ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	nb;

	nb = 0;
	sign = 1;
	i = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
	{
		i++;
	}
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (sign * nb);
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
 
// modified
void	ft_lstadd_back(t_list **lst, int value)
{
	t_list	*last;
	t_list *new_node;

	new_node = ft_lstnew(value);
	if (*lst == NULL)
		*lst = new_node;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new_node;
	}
}

t_list	*put_in_stack(int ac, char **av)
{
	t_list *head;
	int i;
	int value;

	head = NULL;
	i = 1;
	while (i < ac)
	{
		value = ft_atoi(av[i]);
		ft_lstadd_back(&head, value);
		i++;
	}
	return (head);
}

void	print_list(t_list *head)
{
	t_list *current;

	current = head;
	int	i = 0;
	while (current != NULL)
	{
		printf("%d\n", current->value);
		current = current->next;
		i++;
	}
}

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

int main(int ac, char **av)
{
	t_list *stack_a;
	t_list *stack_b;
	int	i;

	stack_a = NULL;
	stack_b = NULL;

	stack_a = put_in_stack(ac, av);
	// printf("stack a created with arguments\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// printf("stack b : \n");
	// print_list(stack_b);
	// int i = push(&stack_a, &stack_b);
	// printf("push executed\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// printf("stack b : \n");
	// print_list(stack_b);
	// i = push(&stack_a, &stack_b);
	// printf("push executed\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// printf("stack b : \n");
	// print_list(stack_b);
	// i = pa(&stack_a, &stack_b);
	// printf("pa executed\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// printf("stack b : \n");
	// print_list(stack_b);
	// i = pb(&stack_a, &stack_b);
	// printf("pb executed\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// printf("stack b : \n");
	// print_list(stack_b);
	i = sa(&stack_a);
	printf("sa executed!\n");
	print_list(stack_a);
	i = ra(&stack_a);
	printf("ra executed!\n");
	printf("stack a : \n");
	print_list(stack_a);
	// i = rr(&stack_a);
	// printf("rr executed\n");
	// print_list(stack_a);
	// i = rrotate(&stack_a);
	// printf("rrotate executed!\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// i = pb(&stack_a, &stack_b);
	// i = pb(&stack_a, &stack_b);
	// i = pb(&stack_a, &stack_b);
	// printf("pb executed 3 times\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// printf("stack b : \n");
	// print_list(stack_b);
	// i = ss(&stack_a, &stack_b);
	// printf("ss\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// printf("stack b : \n");
	// print_list(stack_b);
	// i = sa(&stack_a);
	// printf("sa\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// i = sb(&stack_b);
	// printf("sb\n");
	// printf("stack b : \n");
	// print_list(stack_b);
	// i = ra(&stack_a);
	// printf("ra executed\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// i = rb(&stack_b);
	// printf("rb executed\n");
	// printf("stack b : \n");
	// print_list(stack_b);
	// i = rr(&stack_a, &stack_b);
	// printf("rr\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// printf("stack b : \n");
	// print_list(stack_b);
	// i = rra(&stack_a);
	// printf("rra executed\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// i = rrb(&stack_b);
	// printf("rrb executed\n");
	// printf("stack b : \n");
	// print_list(stack_b);
	// i = rrr(&stack_a, &stack_b);
	// printf("rrr\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// printf("stack b : \n");
	// print_list(stack_b);

	t_list *current = stack_a;
	t_list *temp;
	i = 0;
	while (current != NULL && i < 4)
	{
		temp = current;
		current = current->next;
		free(temp);
		i++;
	} 
	return (0);
	
	
    // // Create a list
	// t_list *stack_a = NULL;

	// // Create nodes with integer content
	// int *data1 = (int *)malloc(sizeof(int));
	// int *data2 = (int *)malloc(sizeof(int));
	// int *data3 = (int *)malloc(sizeof(int));

	// *data1 = 1;
	// *data2 = 2;
	// *data3 = 3;

	// // Create nodes using ft_lstnew and add them to the front of the list
	// t_list *node1 = ft_lstnew(data1);
	// t_list *node2 = ft_lstnew(data2);
	// t_list *node3 = ft_lstnew(data3);
}