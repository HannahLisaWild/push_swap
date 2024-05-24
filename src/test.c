//#include "../include/push_swap.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

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
	int	index_b_final;
	int	nbr_b;
	int	nbr_b_final;
	int	nbr_a_final;
	int	costs_current;
	int	costs_final;
	int    moves_ra;
    int    moves_rra;
    int    moves_rb;
    int    moves_rrb;
    int    moves_pa;
	int    moves_ra_final;
    int    moves_rra_final;
    int    moves_rb_final;
    int    moves_rrb_final;
}            t_list_bf;


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (n == 0)
		return (len);
	if (n != 0)
	{
		while (src[i] != '\0' && i < (n - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}



static char	**ft_error(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	nb_words;

	if (!s[0])
		return (0);
	i = 0;
	nb_words = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_words++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_words++;
	return (nb_words);
}

static void	ft_next_word(char **next_word, size_t *next_word_len, char c)
{
	size_t	i;

	*next_word += *next_word_len;
	*next_word_len = 0;
	i = 0;
	while (**next_word && **next_word == c)
		(*next_word)++;
	while ((*next_word)[i])
	{
		if ((*next_word)[i] == c)
			return ;
		(*next_word_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	char	*next_word;
	size_t	next_word_len;
	size_t	i;

	if (!s)
		return (NULL);
	new = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!new)
		return (NULL);
	i = 0;
	next_word = (char *)s;
	next_word_len = 0;
	while (i < ft_word_count(s, c))
	{
		ft_next_word(&next_word, &next_word_len, c);
		new[i] = (char *)malloc(sizeof(char) * (next_word_len + 1));
		if (!new[i])
			return (ft_error(new));
		ft_strlcpy(new[i], next_word, next_word_len + 1);
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}


int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	nb;

	nb = 0;
	sign = 1;
	i = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
	{
		i++;
	}
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (sign * nb);
}

int is_numeric(char *str)
{
    int i;

    i = 0;
    if (ft_atoi(str) < -2147483648 || ft_atoi(str) > 2147483647)
        return (1);
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (1);
        i++;
    }
    return (0);
}

int check_for_doubles(char **str, char *s, int i)
{
    i++;
    while (str[i])
    {
        if (ft_atoi(str[i]) == (ft_atoi(s)))
            return (1);
        i++;
    }
    return (0);
}

void    free_args(char **args)
{
    int i;

    i = 0;
    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
}

void check_args(int ac, char **av)
{
    char **args; 
    int i;

    if (ac == 2)
    {
        i = 0;
        args = ft_split(av[1], ' ');
    }
    else
    {
        i = 1;
        args = av;
    }
    while (args[i])
    {
        if (is_numeric(args[i]) == 1)
            error();
        if (check_for_doubles(args, args[i], i) == 1)
            error();
        i++;
    }
    if (ac == 2)
        free_args(args);
}


void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

// int	ft_atoi(const char *str)
// {
// 	int				i;
// 	int				sign;
// 	long long int	nb;

// 	nb = 0;
// 	sign = 1;
// 	i = 0;
// 	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
// 			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
// 	{
// 		i++;
// 	}
// 	if (str[i] == '-')
// 		sign = -1;
// 	if (str[i] == '+' || str[i] == '-')
// 	{
// 		i++;
// 	}
// 	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
// 	{
// 		nb = nb * 10 + (str[i] - '0');
// 		i++;
// 	}
// 	return (sign * nb);
// }

t_list	*ft_lstnew(int value)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}
 
// modified
void	ft_lstadd_back(t_list **lst, int value)
{
	t_list	*last;
	t_list *new_node;

	new_node = ft_lstnew(value);
	if (*lst == NULL)
		*lst = new_node;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new_node;
	}
}

t_list	*put_in_stack(int ac, char **av)
{
	t_list *head;
	int i;
	int value;
	char **temp;

	head = NULL;
	if (ac == 2)
	{
		temp = ft_split(av[1], ' ');
		i = 0;
		while (temp[i])
		{
			value = ft_atoi(temp[i]);
			ft_lstadd_back(&head, value);
			i++;
		}
		free_args(temp);
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			value = ft_atoi(av[i]);
			ft_lstadd_back(&head, value);
			i++;
		}
	}
	return (head);
}

void	print_list(t_list *head)
{
	t_list *current;

	current = head;
	int	i = 0;
	while (current != NULL)
	{
		printf("%d\n", current->value);
		current = current->next;
		i++;
	}
}

int	swap(t_list **head)
{
	t_list *temp;
	
	if (*head == NULL || (*head)->next == NULL)
		return (-1);
	else
	{
		temp = (*head)->next;
		(*head)->next = temp->next;
		temp->next = *head;
		*head = temp;
	}
	return (0);
}

int	sa(t_list **stack_a)
{
	if (swap(stack_a) != 0)
		return (-1);
	write(1, "sa\n", 3);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (swap(stack_b) != 0)
		return (-1);
	write(1, "sb\n", 3);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (swap(stack_a) != 0 || swap(stack_b) != 0)
		return (-1);
	write(1, "ss\n", 3);
	return (0);
}

int	rotate(t_list **head)
{
	t_list *last;
	
	if (*head == NULL || (*head)->next == NULL)
		return (-1);
	else
	{
		last = *head;
		last = ft_lstlast(*head);
		if (last->next == NULL)
		{
			last->next = *head;
			*head = (*head)->next;
			last->next->next = NULL;
		}
	}
	return (0);
}

int ra(t_list **stack_a)
{
	if (rotate(stack_a) != 0)
		return (-1);
	write(1, "ra\n", 3);
	return (0);
}

int rb(t_list **stack_b)
{
	if (rotate(stack_b) != 0)
		return (-1);
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (rotate(stack_a) != 0 || rotate(stack_b) != 0)
		return (-1);
	write(1, "rr\n", 3);
	return (0);
}

int	rrotate(t_list **head)
{
	t_list *last;
	t_list *new_last;
	
	if (*head == NULL || (*head)->next == NULL)
		return (-1);
	else
	{
		last = ft_lstlast(*head);
		new_last = *head;
		while (new_last->next->next != NULL)
			new_last = new_last->next;
		last->next = *head;
		*head = last;
		new_last->next = NULL;
	}
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (rrotate(stack_a) != 0 || rrotate(stack_b) != 0)
		return (-1);
	write(1, "rrr\n", 4);
	return (0);
}

int rra(t_list **stack_a)
{
	if (rrotate(stack_a) != 0)
		return (-1);
	write(1, "rra\n", 4);
	return (0);
}

int rrb(t_list **stack_b)
{
	if (rrotate(stack_b) != 0)
		return (-1);
	write(1, "rrb\n", 4);
	return (0);
}

int	push(t_list **src_stack, t_list **dest_stack)
{
	t_list *head_src;
	t_list *temp;
	t_list *new_node;
	int value;

	if ((*src_stack) == NULL)
		return (-1);
	head_src = *src_stack;
	temp = *src_stack;
	value = temp->value;
	*src_stack = head_src->next;
	free(head_src);
	new_node = ft_lstnew(value);
	if ((*dest_stack) == NULL)
	{
		*dest_stack = new_node;
		(*dest_stack)->next = NULL;
	}
	else
	{
		new_node->next = (*dest_stack);
		*dest_stack = new_node;
	}
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) != 0)
		return (-1);
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) != 0)
		return (-1);
	write(1, "pb\n", 3);
	return (0);
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
    i = ra(stack_a);
    return (0);
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


int	calculation(t_list_bf *bf, int head_a_value)
{
	int	a;
	int	b;
	int	result;

	a = head_a_value;
	b = bf->nbr_b;
	result = (a - b);
	return (result);
}

int	calculate_bf(t_list **stack_a, t_list **stack_b, t_list_bf *bf)
{
	t_list	*head_a;
	float	lst_size;
	int i;

	head_a = *stack_a;
	i = 1;
	bf->bf_final_value = __INT_MAX__;
	lst_size = ft_lstsize(*stack_a);
	while (head_a->next != NULL)
	{
		bf->bf_current = head_a->value;
		bf->bf_current_value = calculation(bf, head_a->value);
		if (bf->bf_current_value > 0 && bf->bf_current_value < bf->bf_final_value)
		{
			bf->bf_final_value = bf->bf_current_value;
			bf->bf_final = bf->bf_current;
			bf->index_a = i;
		}
		head_a = head_a->next;
		i++;;
	}
	bf->bf_current = head_a->value;
	bf->bf_current_value = (head_a->value - bf->nbr_b);
	if (bf->bf_current_value > 0 && bf->bf_current_value < bf->bf_final_value)
	{
		bf->bf_final = bf->bf_current;
		bf->index_a = i;
	}
	return (bf->bf_final);
}

int	costs_a(t_list **stack_a, t_list_bf *bf)
{
	float lst_size_a;
	int	i;

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

int	costs_b(t_list **stack_b, t_list_bf *bf)
{
	float	lst_size_b;
	int	i;

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
	int i;

	i = 0;
	if (bf->moves_ra_final != 0)
	{
		while (bf->moves_ra_final != 0)
		{
			i = ra(stack_a);
			bf->moves_ra_final--;
		}
	}
	if (bf->moves_rra_final != 0)
	{
		while (bf->moves_rra_final != 0)
		{
			i = rra(stack_a);
			bf->moves_rra_final--;
		}
	}
}

void	execute_cheapest_b(t_list **stack_a, t_list **stack_b, t_list_bf *bf)
{
	int i;

	i = 0;
	if (bf->moves_rb_final != 0)
	{
		while (bf->moves_rb_final != 0)
		{
			i = rb(stack_b);
			bf->moves_rb_final--;
		}
	}
	if (bf->moves_rrb_final != 0)
	{
		while (bf->moves_rrb_final != 0)
		{
			i = rrb(stack_b);
			bf->moves_rrb_final--;
		}
	}
	i = pa(stack_a, stack_b);
}

void	set_final_moves(t_list_bf *bf)
{
	bf->moves_ra_final = bf->moves_ra;
	bf->moves_rra_final = bf->moves_rra;
	bf->moves_rb_final = bf->moves_rb;
	bf->moves_rrb_final = bf->moves_rrb;
}

int	best_friend(t_list **stack_a, t_list **stack_b)
{
	t_list *head_b;
    t_list_bf *bf;

    bf = malloc(sizeof(t_list_bf));
    if (!bf)
        return (0);
	head_b = *stack_b;
	bf->nbr_b = head_b->value;
	bf->nbr_a_final = calculate_bf(stack_a, stack_b, bf);
	bf->nbr_b_final = bf->nbr_b;
	bf->index_b_final = 1;
	bf->index_b = 1;
	bf->costs_final = costs(stack_a, stack_b, bf);
	set_final_moves(bf);
	head_b = head_b->next;
	bf->index_b = 2;
	while (head_b != NULL)
	{
		bf->nbr_b = head_b->value;
		bf->bf_current = calculate_bf(stack_a, stack_b, bf);
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
	execute_cheapest_a(stack_a, bf);
	execute_cheapest_b(stack_a, stack_b, bf);
	free(bf);
	return (0);
}

void	final_rotate(t_list **stack_a)
{
	t_list	*min;
	t_list *head;
	int index;
	float lst_size;

	index = 1;
	head = *stack_a;
	min = get_min(stack_a);
	while (head->next != NULL)
	{
		if (head->value == min->value)
			break;
		head = head->next;
		index++;
	}
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

int	small_sort(t_list **stack_a, t_list **stack_b)
{
	float lst_size_a;

	if ((lst_size_a = ft_lstsize(*stack_a)) == 2)
		sort_2(stack_a);
	else if ((lst_size_a = ft_lstsize(*stack_a)) == 3)
		sort_3(stack_a);
	else if ((lst_size_a = ft_lstsize(*stack_a)) == 4)
		sort_4(stack_a, stack_b);
	else
		sort_5(stack_a, stack_b);
	return (0);
}

int	sorted(t_list **stack_a)
{
	t_list *head;
	int	i;
	float list_size;

	i = 1;
	head = *stack_a;
	while (head->next != NULL)
	{
		if (head->value < head->next->value)
			i++;
		head = head->next;
	}
	list_size = ft_lstsize(*stack_a);
	if ((int)list_size == i)
		return (0);
	return (-1);
}

int	sort_stack(t_list **stack_a, t_list **stack_b)
{
	float lst_size_b;
	float lst_size_a;

	if ((lst_size_a = ft_lstsize(*stack_a)) <= 5)
		small_sort(stack_a, stack_b);
	else
	{
		while (sorted(stack_a) != 0)
		{
			sort_till_5_in_A(stack_a, stack_b);
    		sort_5(stack_a, stack_b);
			while ((int)(lst_size_b = ft_lstsize(*stack_b)) != 0)
			{	
				best_friend(stack_a, stack_b);
			}
			final_rotate(stack_a);
		}
	}
	return (0);
}

void	free_stack(t_list **stack)
{
	t_list *current;
	t_list *temp;
	float	lst_size;

	current = *stack;
	lst_size = ft_lstsize(*stack);
	while (lst_size > 0)
	{
		temp = current;
		current = current->next;
		free(temp);
		lst_size--;
	}
	free(current);
}

int	main(int ac, char **av)
{
	t_list *stack_a;
	t_list *stack_b;

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
