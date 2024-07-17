/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:28:16 by hawild            #+#    #+#             */
/*   Updated: 2024/07/17 12:04:59 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	costs_a(t_list **stack_a, t_list_bf *bf)
{
	float	lst_size_a;
	int		i;

	lst_size_a = ft_lstsize(*stack_a);
	bf->moves_rra = 0;
	bf->moves_ra = 0;
	if ((int)lst_size_a % 2 == 0)
	{
		i = (int)lst_size_a / 2;
		if (bf->index_a <= i)
			bf->moves_ra = bf->index_a - 1;
		else if (bf->index_a > i)
			bf->moves_rra = ((lst_size_a - bf->index_a) + 1);
	}
	else if ((int)lst_size_a % 2 != 0)
	{
		i = ((int)lst_size_a + 1) / 2;
		if (bf->index_a < i)
			bf->moves_ra = bf->index_a - 1;
		else if (bf->index_a >= i)
			bf->moves_rra = ((lst_size_a - bf->index_a) + 1);
	}
	return (bf->moves_rra + bf->moves_ra);
}

static int	costs_b(t_list **stack_b, t_list_bf *bf)
{
	float	lst_size_b;
	int		i;

	lst_size_b = ft_lstsize(*stack_b);
	bf->moves_rb = 0;
	bf->moves_rrb = 0;
	bf->moves_pa = 1;
	if ((int)lst_size_b % 2 == 0)
	{
		i = (int)lst_size_b / 2;
		if (bf->index_b <= i)
			bf->moves_rb = bf->index_b - 1;
		else if (bf->index_b > i)
			bf->moves_rrb = ((lst_size_b - bf->index_b) + 1);
	}
	else if ((int)lst_size_b % 2 != 0)
	{
		i = ((int)lst_size_b + 1) / 2;
		if (bf->index_b <= i)
			bf->moves_rb = bf->index_b - 1;
		else if (bf->index_b > i)
			bf->moves_rrb = ((lst_size_b - bf->index_b) + 1);
	}
	return (bf->moves_rrb + bf->moves_rb + bf->moves_pa);
}

int	costs(t_list **stack_a, t_list **stack_b, t_list_bf *bf)
{
	int	costs;

	costs = (costs_a(stack_a, bf) + costs_b(stack_b, bf));
	return (costs);
}

void	execute_cheapest_a(t_list **stack_a, t_list_bf *bf)
{
	if (bf->moves_ra_final != 0)
	{
		while (bf->moves_ra_final != 0)
		{
			ra(stack_a);
			bf->moves_ra_final--;
		}
	}
	if (bf->moves_rra_final != 0)
	{
		while (bf->moves_rra_final != 0)
		{
			rra(stack_a);
			bf->moves_rra_final--;
		}
	}
}

void	execute_cheapest_b(t_list **stack_a, t_list **stack_b, t_list_bf *bf)
{
	if (bf->moves_rb_final != 0)
	{
		while (bf->moves_rb_final != 0)
		{
			rb(stack_b);
			bf->moves_rb_final--;
		}
	}
	if (bf->moves_rrb_final != 0)
	{
		while (bf->moves_rrb_final != 0)
		{
			rrb(stack_b);
			bf->moves_rrb_final--;
		}
	}
	pa(stack_a, stack_b);
}
