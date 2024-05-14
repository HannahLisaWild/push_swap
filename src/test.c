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

	head = NULL;
	i = 1;
	while (i < ac)
	{
		value = ft_atoi(av[i]);
		ft_lstadd_back(&head, value);
		i++;
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

int main_algorithm(t_list **stack_a, t_list **stack_b)
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

int main(int ac, char **av)
{
	t_list *stack_a;
	t_list *stack_b;
	int	i;

	stack_a = NULL;
	stack_b = NULL;

	stack_a = put_in_stack(ac, av);
    printf("stack a created with arguments\n");
	printf("stack a : \n");
	print_list(stack_a);
	printf("stack b : \n");
	print_list(stack_b);
    i = main_algorithm(&stack_a, &stack_b);
    printf("stack a : \n");
	print_list(stack_a);
	printf("stack b : \n");
	print_list(stack_b);
	// int i = push(&stack_a, &stack_b);
	// printf("push executed\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// printf("stack b : \n");
	// print_list(stack_b);
	// i = push(&stack_a, &stack_b);
	// printf("push executed\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// printf("stack b : \n");
	// print_list(stack_b);
	// i = pa(&stack_a, &stack_b);
	// printf("pa executed\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// printf("stack b : \n");
	// print_list(stack_b);
	// i = pb(&stack_a, &stack_b);
	// printf("pb executed\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// printf("stack b : \n");
	// print_list(stack_b);
	// i = sa(&stack_a);
	// printf("sa executed!\n");
	// print_list(stack_a);
	// i = ra(&stack_a);
	// printf("ra executed!\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// i = rr(&stack_a);
	// printf("rr executed\n");
	// print_list(stack_a);
	// i = rrotate(&stack_a);
	// printf("rrotate executed!\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// i = pb(&stack_a, &stack_b);
	// i = pb(&stack_a, &stack_b);
	// i = pb(&stack_a, &stack_b);
	// printf("pb executed 3 times\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// printf("stack b : \n");
	// print_list(stack_b);
	// i = ss(&stack_a, &stack_b);
	// printf("ss\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// printf("stack b : \n");
	// print_list(stack_b);
	// i = sa(&stack_a);
	// printf("sa\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// i = sb(&stack_b);
	// printf("sb\n");
	// printf("stack b : \n");
	// print_list(stack_b);
	// i = ra(&stack_a);
	// printf("ra executed\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// i = rb(&stack_b);
	// printf("rb executed\n");
	// printf("stack b : \n");
	// print_list(stack_b);
	// i = rr(&stack_a, &stack_b);
	// printf("rr\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// printf("stack b : \n");
	// print_list(stack_b);
	// i = rra(&stack_a);
	// printf("rra executed\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// i = rrb(&stack_b);
	// printf("rrb executed\n");
	// printf("stack b : \n");
	// print_list(stack_b);
	// i = rrr(&stack_a, &stack_b);
	// printf("rrr\n");
	// printf("stack a : \n");
	// print_list(stack_a);
	// printf("stack b : \n");
	// print_list(stack_b);

	t_list *current = stack_a;
	t_list *temp;
	i = 0;
	while (current != NULL && i < 4)
	{
		temp = current;
		current = current->next;
		free(temp);
		i++;
	} 
	return (0);
}