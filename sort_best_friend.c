/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_best_friend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:26:43 by hawild            #+#    #+#             */
/*   Updated: 2024/07/17 17:02:35 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_final_moves(t_list_bf *bf)
{
	bf->moves_ra_final = bf->moves_ra;
	bf->moves_rra_final = bf->moves_rra;
	bf->moves_rb_final = bf->moves_rb;
	bf->moves_rrb_final = bf->moves_rrb;
}

void	set_bf(t_list **stack_a, t_list **stack_b, t_list_bf *bf)
{
	t_list	*head_b;

	head_b = *stack_b;
	head_b = head_b->next;
	while (head_b != NULL)
	{
		bf->nbr_b = head_b->value;
		bf->bf_current = calculate_bf(stack_a, bf);
		bf->costs_current = costs(stack_a, stack_b, bf);
		if (bf->costs_final > bf->costs_current)
		{
			bf->nbr_a_final = bf->bf_current;
			bf->costs_final = bf->costs_current;
			bf->nbr_b_final = bf->nbr_b;
			bf->index_b_final = bf->index_b;
			set_final_moves(bf);
		}
		head_b = head_b->next;
		bf->index_b++;
	}
}

int	best_friend(t_list **stack_a, t_list **stack_b)
{
	t_list		*head_b;
	t_list_bf	*bf;

	bf = malloc(sizeof(t_list_bf));
	if (!bf)
		return (0);
	head_b = *stack_b;
	bf->nbr_b = head_b->value;
	bf->nbr_a_final = calculate_bf(stack_a, bf);
	bf->nbr_b_final = bf->nbr_b;
	bf->index_b_final = 1;
	bf->index_b = 1;
	bf->costs_final = costs(stack_a, stack_b, bf);
	set_final_moves(bf);
	bf->index_b = 2;
	set_bf(stack_a, stack_b, bf);
	execute_cheapest_a(stack_a, bf);
	execute_cheapest_b(stack_a, stack_b, bf);
	free(bf);
	return (0);
}

static float	calculate_mean_val(t_list **stack_a, float lst_size)
{
	t_list	*head;
	float	mean;

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

int	sort_till_5_in_a(t_list **stack_a, t_list **stack_b)
{
	float	lst_size;
	float	mean;

	lst_size = ft_lstsize(*stack_a);
	while (lst_size > 5 && (*stack_a)->next != NULL)
	{
		mean = calculate_mean_val(stack_a, lst_size);
		if ((*stack_a)->value < mean)
		{
			pb(stack_a, stack_b);
			lst_size -= 1;
		}
		else if ((*stack_a)->value > mean)
		{
			ra(stack_a);
		}
		else
			ra(stack_a);
	}
	return (0);
}
