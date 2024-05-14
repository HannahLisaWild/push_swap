/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:03:00 by hawild            #+#    #+#             */
/*   Updated: 2024/05/14 16:56:33 by hawild           ###   ########.fr       */
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
    float   sum;

    head = *stack_a;
    sum = 0;
    while (head->next != NULL)
    {
        sum += head->value;
        head = head->next;
    }
    sum += head->value;
    return (sum / lst_size);
}

int main_algorithm(t_list **stack_a, t_list **stack_b)
{
    float lst_size;
    float mean;
    t_list *head_a;
    int i;
    
    head_a = *stack_a;
    while ((lst_size = ft_lstsize(*stack_a)) >= 5)
    {
        mean = calculate_mean_val(stack_a, lst_size);
        if (head_a->value < mean)
            i = pb(stack_a, stack_b);
        else if (head_a->value > mean)
            i = ra(stack_a, stack_b);
    }
    return (0);
}