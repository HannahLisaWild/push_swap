/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_nbr_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:12:29 by hawild            #+#    #+#             */
/*   Updated: 2024/05/14 16:05:55 by hawild           ###   ########.fr       */
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

t_list *get_min(t_list **stack)
{
    t_list *min;
    t_list *current;
    int i;

    current = *stack;
    min = *stack;
    i = 0;
    while (current->next)
    {
        current = current->next;
        if (current->value < min->value)
            min = current;
        i++;
    }
    return (min);
}

t_list *get_max(t_list **stack)
{
    t_list *max;
    t_list *current;
    int i;

    current = *stack;
    max = *stack;
    i = 0;
    while (current->next)
    {
        current = current->next;
        if (current->value > max->value)
            max = current;
        i++;
    }
    return (max);
}

int sort_2(t_list **stack_a)
{
    t_list *head;

    head = *stack_a;
    if (head == NULL)
        return (0);
    if (head->value > head->next->value)    
        sa(stack_a);
    return (0);
}

int sort_3(t_list **stack_a)
{
    int first;
    int second;
    int third;

    first = (*stack_a)->value;
    second = (*stack_a)->next->value;
    third = (*stack_a)->next->next->value;
    if ((first < second) && (first < third))
    {
        if (second > third)
        {
            sa(stack_a);
            ra(stack_a);
        }
        return (0);
    }
    else if ((first > second) && (first > third))
    {
        if (second < third)
            ra(stack_a);
        else
        {
            ra(stack_a);
            ra(stack_a);
        }
        return (0);
    }
    else
    {
        if (first < second && first > third)
            rra(stack_a);
        else
            sa(stack_a);
        return (0);
    }
}

int sort_4(t_list **stack_a, t_list **stack_b)
{
    t_list *min;
    int     i;
    
    min = get_min(stack_a);
    if (min == (*stack_a))
        i = pb(stack_a, stack_b);
    else
    {
        if (min->next == NULL)
            rra(stack_a);
        else
        {
            while (min != (*stack_a))
                ra(stack_a);
        }
        i = pb(stack_a, stack_b);  
    }
    i = sort_3(stack_a);
    i = pa(stack_a, stack_b);
    return (0);
}

int sort_5(t_list **stack_a, t_list **stack_b)
{
    t_list *max;
    int i;

    max = get_max(stack_a);
    if (max == (*stack_a))
        i = pb(stack_a, stack_b);
    else
    {
        if (max->next == NULL || max->next->next == NULL)
        {
            while (max != (*stack_a))
                rra(stack_a);
        }
        else
        {
            while (max != (*stack_a))
                ra(stack_a);
        }
        i = pb(stack_a, stack_b);  
    }
    i = sort_4(stack_a, stack_b);
    i = pa(stack_a, stack_b);
    i = pa(stack_a, stack_b);
    i = ra(stack_a);
    return (0);
}