/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:28:50 by hawild            #+#    #+#             */
/*   Updated: 2024/07/17 12:33:08 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculation(t_list_bf *bf, int head_a_value)
{
	int	a;
	int	b;
	int	result;

	a = head_a_value;
	b = bf->nbr_b;
	result = (a - b);
	return (result);
}

static void	update_variables(t_list_bf *bf, int i)
{
	bf->bf_final_value = bf->bf_current_value;
	bf->bf_final = bf->bf_current;
	bf->index_a = i;
}

int	calculate_bf(t_list **stack_a, t_list_bf *bf)
{
	t_list	*head_a;
	int		i;

	head_a = *stack_a;
	i = 1;
	bf->bf_final_value = __INT_MAX__;
	while (head_a->next != NULL)
	{
		bf->bf_current = head_a->value;
		bf->bf_current_value = calculation(bf, head_a->value);
		if (bf->bf_current_value > 0
			&& bf->bf_current_value < bf->bf_final_value)
		{
			update_variables(bf, i);
		}
		head_a = head_a->next;
		i++;
	}
	bf->bf_current = head_a->value;
	bf->bf_current_value = (head_a->value - bf->nbr_b);
	if (bf->bf_current_value > 0 && bf->bf_current_value < bf->bf_final_value)
		update_variables(bf, i);
	return (bf->bf_final);
}
