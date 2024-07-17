/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_nbr_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:31:28 by hawild            #+#    #+#             */
/*   Updated: 2024/07/17 12:18:31 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_2(t_list **stack_a)
{
	t_list	*head;

	head = *stack_a;
	if (head == NULL)
		return (0);
	if (head->value > head->next->value)
		sa(stack_a);
	return (0);
}

static void	handle_cases_3(t_list **stack_a, int first, int second, int third)
{
	if ((first < second) && (first < third) && (second > third))
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((first > second) && (first > third))
	{
		if (second < third)
			ra(stack_a);
		else
		{
			ra(stack_a);
			sa(stack_a);
		}
	}
	else
	{
		if (first < second && first > third)
			rra(stack_a);
		else
			sa(stack_a);
	}
}

int	sort_3(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	handle_cases_3(stack_a, first, second, third);
	return (0);
}

int	sort_4(t_list **stack_a, t_list **stack_b)
{
	t_list	*min;

	min = get_min(stack_a);
	if (min == (*stack_a))
		pb(stack_a, stack_b);
	else
	{
		if (min->next == NULL)
			rra(stack_a);
		else
		{
			while (min != (*stack_a))
				ra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_3(stack_a);
	pa(stack_a, stack_b);
	return (0);
}

int	sort_5(t_list **stack_a, t_list **stack_b)
{
	t_list	*max;

	max = get_max(stack_a);
	if (max == (*stack_a))
		pb(stack_a, stack_b);
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
		pb(stack_a, stack_b);
	}
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
	ra(stack_a);
	return (0);
}
