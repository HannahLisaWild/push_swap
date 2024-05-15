/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:03:00 by hawild            #+#    #+#             */
/*   Updated: 2024/05/15 16:39:48 by hawild           ###   ########.fr       */
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

void	free_stack(t_list **stack)
{
	t_list *current;
	t_list *temp;
	float	lst_size;

	current = *stack;
	lst_size = ft_lstsize(*stack);
	while (lst_size >= 0)
	{
		temp = current;
		current = current->next;
		free(temp);
		lst_size--;
	}
	free(stack);
}

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

float   calculate_mean_val(t_list **stack_a, float lst_size)
{
    t_list *head;
    float   mean;

    head = *stack_a;
    mean = 0;
    while (head->next != NULL)
    {
        mean += head->value;
        head = head->next;
    }
    mean += head->value;
    return (mean / lst_size);
}

int sort_till_5_in_A(t_list **stack_a, t_list **stack_b)
{
    float lst_size;
    float mean;
    int i;
    
    lst_size = ft_lstsize(*stack_a);
    while (lst_size > 5 && (*stack_a)->next != NULL)
    {
        mean = calculate_mean_val(stack_a, lst_size);
		printf("mean value: %f\n", mean);
		printf("lst size: %f\n", lst_size);
        if ((*stack_a)->value < mean)
        {
            i = pb(stack_a, stack_b);
            lst_size -= 1;
        }
        else if ((*stack_a)->value > mean)
        {   
            i = ra(stack_a);
        }
    }
    return (0);
}

int main_algorithm(t_list **stack_a, t_list **stack_b)
{
    int i;
	t_list *temp_stack;
    
	temp_stack = NULL;
    i = sort_till_5_in_A(stack_a, stack_b);
    i = sort_5(stack_a, &temp_stack);
	free(temp_stack);
	return (i);
}