/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_to_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:57:15 by hawild            #+#    #+#             */
/*   Updated: 2024/05/14 12:30:31 by hawild           ###   ########.fr       */
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
}