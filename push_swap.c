/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:52:40 by hawild            #+#    #+#             */
/*   Updated: 2024/07/17 12:19:51 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotation(t_list **stack_a, int index)
{
	float	lst_size;

	lst_size = (ft_lstsize(*stack_a)) / 2;
	if ((int)lst_size >= index)
	{
		while (index != 1)
		{
			ra(stack_a);
			index--;
		}
	}
	else
	{
		while (index != (lst_size * 2))
		{
			rra(stack_a);
			index++;
		}
		rra(stack_a);
	}
}

void	final_rotate(t_list **stack_a)
{
	t_list	*min;
	t_list	*head;
	int		index;

	index = 1;
	head = *stack_a;
	min = get_min(stack_a);
	while (head->next != NULL)
	{
		if (head->value == min->value)
			break ;
		head = head->next;
		index++;
	}
	rotation(stack_a, index);
}

int	small_sort(t_list **stack_a, t_list **stack_b)
{
	float	lst_size_a;

	lst_size_a = ft_lstsize(*stack_a);
	if (lst_size_a == 2)
		sort_2(stack_a);
	else if (lst_size_a == 3)
		sort_3(stack_a);
	else if (lst_size_a == 4)
		sort_4(stack_a, stack_b);
	else
		sort_5(stack_a, stack_b);
	return (0);
}

int	sort_stack(t_list **stack_a, t_list **stack_b)
{
	float	lst_size_b;
	float	lst_size_a;

	lst_size_a = ft_lstsize(*stack_a);
	if (lst_size_a <= 5)
		small_sort(stack_a, stack_b);
	else
	{
		while (sorted(stack_a) != 0)
		{
			sort_till_5_in_a(stack_a, stack_b);
			sort_5(stack_a, stack_b);
			lst_size_b = ft_lstsize(*stack_b);
			while ((int)lst_size_b != 0)
			{
				best_friend(stack_a, stack_b);
				lst_size_b = ft_lstsize(*stack_b);
			}
			final_rotate(stack_a);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		error();
	check_args(ac, av);
	stack_a = put_in_stack(ac, av);
	if (sorted(&stack_a) == 0)
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (0);
	}
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
