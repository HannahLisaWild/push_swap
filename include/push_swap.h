/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:22:45 by hawild            #+#    #+#             */
/*   Updated: 2024/07/17 12:19:32 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

typedef struct s_list_bf
{
	int				bf_current;
	int				bf_final;
	int				bf_current_value;
	int				bf_final_value;
	int				index_a;
	int				index_b;
	int				index_b_final;
	int				nbr_b;
	int				nbr_b_final;
	int				nbr_a_final;
	int				costs_current;
	int				costs_final;
	int				moves_ra;
	int				moves_rra;
	int				moves_rb;
	int				moves_rrb;
	int				moves_pa;
	int				moves_ra_final;
	int				moves_rra_final;
	int				moves_rb_final;
	int				moves_rrb_final;
}					t_list_bf;

void				check_args(int ac, char **av);
int					ft_atoi(const char *str);
void				free_args(char **args);
int					calculate_bf(t_list **stack_a, t_list_bf *bf);
int					costs(t_list **stack_a, t_list **stack_b, t_list_bf *bf);
void				execute_cheapest_a(t_list **stack_a, t_list_bf *bf);
void				execute_cheapest_b(t_list **stack_a, t_list **stack_b,
						t_list_bf *bf);
char				**ft_split(char const *s, char c);
void				ft_lstadd_back(t_list **lst, int value);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(int value);
void				print_list(t_list *head);
float				ft_lstsize(t_list *lst);
void				rotation(t_list **stack_a, int index);
void				final_rotate(t_list **stack_a);
int					small_sort(t_list **stack_a, t_list **stack_b);
int					sort_stack(t_list **stack_a, t_list **stack_b);
int					pa(t_list **stack_a, t_list **stack_b);
int					pb(t_list **stack_a, t_list **stack_b);
int					push(t_list **src_stack, t_list **dest_stack);
int					rrotate(t_list **head);
int					rrr(t_list **stack_a, t_list **stack_b);
int					rra(t_list **stack_a);
int					rrb(t_list **stack_b);
int					rotate(t_list **head);
int					ra(t_list **stack_a);
int					rb(t_list **stack_b);
int					rr(t_list **stack_a, t_list **stack_b);
int					sort_2(t_list **stack_a);
int					sort_3(t_list **stack_a);
int					sort_4(t_list **stack_a, t_list **stack_b);
int					sort_5(t_list **stack_a, t_list **stack_b);
int					sort_till_5_in_a(t_list **stack_a, t_list **stack_b);
int					best_friend(t_list **stack_a, t_list **stack_b);
void				set_bf(t_list **stack_a, t_list **stack_b, t_list_bf *bf);
int					swap(t_list **head);
int					sa(t_list **stack_a);
int					sb(t_list **stack_b);
int					ss(t_list **stack_a, t_list **stack_b);
t_list				*put_in_stack(int ac, char **av);
void				free_stack(t_list **stack);
int					sorted(t_list **stack_a);
t_list				*get_min(t_list **stack);
t_list				*get_max(t_list **stack);
void				ft_putstr_fd(char *s, int fd);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t n);
void				error(void);

#endif