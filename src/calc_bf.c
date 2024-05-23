/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_bf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:35:19 by hawild            #+#    #+#             */
/*   Updated: 2024/05/17 18:20:04 by hawild           ###   ########.fr       */
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


typedef struct s_list_bf 
{
    int bf_current;
	int	bf_final;
    int bf_current_value;
	int	bf_final_value;
	int index_a;
	int	index_b;
	int	nbr_b;
	int	costs_current;
	int	costs_final;
	int    moves_ra_a;
    int    moves_rra_a;
    int    moves_ra_b;
    int    moves_rra_b;
    int    moves_pa_b;
    struct s_list_bf *next;
}            t_list_bf;


int	calculate_bf(t_list **stack_a, t_list **stack_b, t_list_bf *bf)
{
	t_list_bf *bf;
	t_list	*head_a;
	float	lst_size;
	int i;

	bf = NULL;
	head_a = *stack_a;
	bf->bf_final_value = (head_a->value - bf->nbr_b);
	head_a = head_a->next;
	lst_size = ft_lstsize(*stack_a);
	i = 0;
	while (i <= lst_size)
	{
		bf->bf_current = head_a->value;
		bf->bf_current_value = (head_a->value - bf->nbr_b);
		if (bf->bf_current_value > 0 && bf->bf_current < bf->bf_final_value)
		{
			bf->bf_final = bf->bf_current;
			bf->index_a = i;
		}
		head_a = head_a->next;
		i++;;
	}
	return (bf->bf_final);
}

int	costs_a(t_list **stack_a, t_list_bf *bf)
{
	float lst_size_a;
	int	i;

	lst_size_a = ft_lstsize(*stack_a);
	if ((int)lst_size_a % 2 == 0)
	{
		i = (int)lst_size_a / 2;
		if (bf->index_a <= i)
			bf->moves_ra_a = bf->index_a;
		else if (bf->index_a > i)
			bf->moves_rra_a = (lst_size_a - bf->index_a + 1);
	}
	else if ((int)lst_size_a % 2 != 0)
	{
		i = ((int)lst_size_a + 1) / 2;
		if (bf->index_a < i)
			bf->moves_ra_a = bf->index_a;
		else if (bf->index_a >= i)
			bf->moves_rra_a = (lst_size_a - bf->index_a + 1);
	}
	return (0);
}

int	costs_b(t_list **stack_b, t_list_bf *bf)
{
	float	lst_size_b;
	int	i;

	lst_size_b = ft_lstsize(*stack_b);
	if ((int)lst_size_b % 2 == 0)
	{
		i = (int)lst_size_b / 2;
		if (bf->index_b <= i)
			bf->moves_ra_b = bf->index_b;
		else if (bf->index_b > i)
			bf->moves_rra_b = (lst_size_b - bf->index_b + 1);
		bf->moves_pa_b = 1;
	}
	else if ((int)lst_size_b % 2 != 0)
	{
		i = ((int)lst_size_b + 1) / 2;
		if (bf->index_b < i)
			bf->moves_ra_b = bf->index_b;
		else if (bf->index_b >= i)
			bf->moves_rra_b = (lst_size_b - bf->index_b + 1);
		bf->moves_pa_b = 1;
	}
	return (0);
}

int	costs(t_list **stack_a, t_list **stack_b, t_list_bf *bf)
{
	int	costs;

	costs = (costs_a(stack_a, bf) + costs_b(stack_b, bf));
	return (costs);
}

int	best_friend(t_list **stack_a, t_list **stack_b)
{
	int i;
	t_list *head_b;
    t_list_bf *bf;

    bf = malloc(sizeof(t_list_bf));
    if (!bf)
        return (NULL);
    bf = NULL;
	head_b = *stack_b;
	bf->nbr_b = head_b->value;
	bf->index_b = 0;
	bf->bf_final = calculate_bf(stack_a, stack_b, bf);
	bf->costs_final = costs(stack_a, stack_b, bf);
	head_b = head_b->next;
	i = 0;
	while (head_b != NULL)
	{
		bf->nbr_b = head_b->value;
		bf->bf_current = calculate_bf(stack_a, stack_b, bf);
		bf->costs_current = costs(stack_a, stack_b, bf);
		if (bf->costs_final > bf->costs_current)
		{
			bf->bf_final = bf->bf_current;
			bf->costs_final = bf->costs_current;
		}
		head_b = head_b->next;
		i++;
	}
}

int main_algorithm(t_list **stack_a, t_list **stack_b)
{
    int i;
	t_list *temp_stack;
    
	temp_stack = NULL;
    i = sort_till_5_in_A(stack_a, stack_b);
	printf("stack after sort till 5\n");
	printf("stack a : \n");
	print_list(*stack_a);
	printf("stack b : \n");
	print_list(*stack_b);
	printf("now comes sort_5:\n");
    i = sort_5(stack_a, &temp_stack);
	free(temp_stack);
	return (i);
}


int	calculate_bf(t_list **stack_a, t_list **stack_b, t_list_bf *bf)
{
	t_list	*head_a;
	float	lst_size;
	int i;

	printf("in calculate_bf funcion\n");
	head_a = *stack_a;
	printf("value of b at start: %i\n", bf->nbr_b);
	printf("value of a at start: %i\n", head_a->value);
	bf->bf_final_value = calculation(bf, head_a->value);
	printf(RED"bf final value at beginning: %i\n"RESET, bf->bf_final_value);
	i = 1;
	head_a = head_a->next;
	lst_size = ft_lstsize(*stack_a);
	while (head_a->next != NULL)
	{
		printf("in loop\n");
		printf("value of b: %i\n", bf->nbr_b);
		printf("value of a: %i\n", head_a->value);
		bf->bf_current = head_a->value;
		bf->bf_current_value = calculation(bf, head_a->value);
		printf("bf curret value: %i at iterration: %i\n", bf->bf_current_value, i);
		printf(RED" bf final: %i at iteration: %i index: %i\n"RESET, bf->bf_final, i, bf->index_a);
		if (bf->bf_current_value > 0 && bf->bf_current_value < bf->bf_final_value)
		{
			bf->bf_final = bf->bf_current;
			bf->index_a = i;
			printf(RED" bf final: %i at iteration: %i index: %i\n"RESET, bf->bf_final, i, bf->index_a);
		}
		head_a = head_a->next;
		i++;;
	}
	printf("out of loop\n");
	printf("in loop\n");
	printf("final value of b: %i\n", bf->nbr_b);
	printf("final value of a: %i\n", head_a->value);
	bf->bf_current = head_a->value;
	bf->bf_current_value = (head_a->value - bf->nbr_b);
	printf("bf current value at iteration (i):%i value: %i\n", i, bf->bf_current_value);
	if (bf->bf_current_value > 0 && bf->bf_current_value < bf->bf_final_value)
	{
		bf->bf_final = bf->bf_current;
		bf->index_a = i;
	}
	head_a = head_a->next;
	i++;;
	return (bf->bf_final);
}