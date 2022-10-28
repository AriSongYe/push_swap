/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:02:16 by yecsong           #+#    #+#             */
/*   Updated: 2022/10/27 22:54:26 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info *init_info(int argc, char **argv)
{
	t_info *info;
	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->argc = argc;
	info->argv = argv;
	info->a = NULL;
	info->b = NULL;
	return (info);
}

t_node	*new_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

t_node	*last_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	init_node(t_info **info, int *order)
{
	t_node	*a;
	t_node	*new;
	t_node	*last;
	int		i;

	i = 1;
	a = new_node(order[0]);
	(*info)->a = a;
	while (i < (*info)->argc - 1)
	{
		new = new_node(order[i]);
		last = last_node(a);
		last->next = new;
		i++;
	}
}

t_node	*pop_a(t_info **info)
{
	t_node	*node;

	node = (*info)->a;
	if (!(*info)->a)
		return (NULL);
	else if ((*info)->a)
	{
		if (!(*info)->a->next)
			(*info)->a = NULL;
		else
			(*info)->a = node->next;
		node->next = NULL;
	}
	return (node);
}

t_node	*pop_b(t_info **info)
{
	t_node	*node;

	node = (*info)->b;
	if (!(*info)->b)
		return (NULL);
	else if ((*info)->b)
	{
		if (!(*info)->b->next)
			(*info)->b = NULL;
		else
			(*info)->b = node->next;
		node->next = NULL;
	}
	return (node);
}

void	push_front(t_info **info, t_node **new, int is_a)
{
	if (!*new)
		return ;
	if (is_a)
	{
		(*new)->next = (*info)->a;
		(*info)->a = (*new);
	}
	else
	{
		(*new)->next = (*info)->b;
		(*info)->b = (*new);
	}
}

void	push_back(t_info **info, t_node **new, int is_a)
{
	t_node	*last;

	if (!*new)
		return ;
	if (is_a)
	{
		if (!(*info)->a)
			(*info)->a = *new;
		else
		{
			last = last_node((*info)->a);
			last->next = (*new);
		}
	}
	else
	{
		if (!(*info)->b)
			(*info)->b = *new;
		else
		{
			last = last_node((*info)->b);
			last->next = (*new);
		}
	}
}

void	sa(t_info **info)
{
	t_node	*temp_1;
	t_node	*temp_2;

	temp_1 = pop_a(info);
	temp_2 = pop_a(info);
	push_front(info, &temp_1, 1);
	push_front(info, &temp_2, 1);
	write (1, "sa\n", 3);
}

void	sb(t_info **info)
{
	t_node	*temp_1;
	t_node	*temp_2;

	temp_1 = pop_b(info);
	temp_2 = pop_b(info);
	push_front(info, &temp_1, 0);
	push_front(info, &temp_2, 0);
	write (1, "sb\n", 3);
}

void	ss(t_info **info)
{
	t_node	*temp_1;
	t_node	*temp_2;

	temp_1 = pop_a(info);
	temp_2 = pop_a(info);
	push_front(info, &temp_1, 1);
	push_front(info, &temp_2, 1);
	temp_1 = pop_b(info);
	temp_2 = pop_b(info);
	push_front(info, &temp_1, 0);
	push_front(info, &temp_2, 0);
	write (1, "ss\n", 3);
}

void	pb(t_info **info)
{
	t_node	*pop;

	if (!(*info)->a)
	{
		write(2, "Error : a is empty stack\n", 23);
		return ;
	}
	pop = pop_a(info);
	push_front(info, &pop, 0);
	write (1, "pb\n", 3);
}

void	pa(t_info **info)
{
	t_node	*pop;

	if (!(*info)->b)
	{
		write(2, "Error: b is empty stack\n", 23);
		return ;
	}
	pop = pop_b(info);
	push_front(info, &pop, 1);
	write (1, "pa\n", 3);
}

void	ra(t_info **info)
{
	t_node	*node;
	t_node	*pop;

	if (!(*info)->a)
	{
		write(2, "a is empty stack\n", 17);
		return ;
	}
	node = (*info)->a;
	pop = pop_a(info);
	push_back(info, &pop, 1);
	write (1, "ra\n", 3);
}

void	rb(t_info **info)
{
	t_node	*node;
	t_node	*pop;

	if (!(*info)->b)
	{
		write(2, "b is empty stack\n", 17);
		return ;
	}
	node = (*info)->b;
	pop = pop_b(info);
	push_back(info, &pop, 0);
	write (1, "rb\n", 3);
}

void	rr(t_info **info)
{
	t_node	*node;
	t_node	*pop;

	node = (*info)->a;
	pop = pop_a(info);
	push_back(info, &pop, 1);
	node = (*info)->b;
	pop = pop_b(info);
	push_back(info, &pop, 0);
	write (1, "rr\n", 3);
}

void	rra(t_info **info)
{
	t_node	*node;
	t_node	*pop;

	pop = last_node((*info)->a);
	push_front(info, &pop, 1);
	node = (*info)->a;
	while (node->next != pop)
		node = node->next;
	node->next = NULL;
	write (1, "rra\n", 4);
}

void	rrb(t_info **info)
{
	t_node	*node;
	t_node	*pop;

	pop = last_node((*info)->b);
	push_front(info, &pop, 0);
	node = (*info)->b;
	while (node->next != pop)
		node = node->next;
	node->next = NULL;
	write (1, "rrb\n", 4);
}

void	rrr(t_info **info)
{
	t_node	*node;
	t_node	*pop;

	pop = last_node((*info)->a);
	push_front(info, &pop, 1);
	node = (*info)->a;
	while (node->next != pop)
		node = node->next;
	node->next = NULL;
	pop = last_node((*info)->b);
	push_front(info, &pop, 0);
	node = (*info)->b;
	while (node->next != pop)
		node = node->next;
	write (1, "rrr\n", 4);
}

void	order_number(int *order, int argc, char **argv)
{
	int	i;
	int	j;
	int	cnt;
	int	stack[argc - 1];

	i = 0;
	while (i < argc - 1)
	{
		stack[i] = ft_atoi(argv[argc - i - 1]);
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		cnt = 0;
		while (j < argc - 1)
		{
			if (stack[i] > stack[j])
				cnt++;
			j++;
		}
		order[i++] = cnt;
	}
}

int	node_len(t_node *node, int argc)
{
	int	i;
	
	i = 0;
	while (node->value != argc)
	{
		node = node->next;
		i++;
	}
	printf("node_len = %d\n", i);
	return (i);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	int	*order;

	info = init_info(argc, argv);
	order = malloc(sizeof(int) * argc - 1);
	order_number(order, argc, argv);
	init_node(&info, order);
	int i;
	int	chunk;
	
	chunk = 30;
	i = 0;
	while (info->a)
	{
		if (info->a->value > i + chunk)
			ra(&info);
		else if (info->a->value >= i && info->a->value < i + chunk)
		{
			pb(&info);
			i++;
		}
		else if (info->a->value <= i)
		{
			pb(&info);
			rb(&info);
			i++;
		}
	}
	t_node *node;
	node = info->b;
	/*
	while (node)
	{
		printf("%d\n", node->value);
		node = node->next;
	}
	*/
	info->argc--;
	info->argc--;
	int	signal;

	signal = 0;
	while (info->argc != -1)
	{
//		if (node_len(info->b,info->argc) < info->argc / 2)
//			signal = 1;
		if (info->argc == info->b->value)
		{
			pa(&info);
			info->argc--;
		}
		else if (signal)
			rb(&info);
		else if (!signal)
			rrb(&info);
	}
	node = info->a;
	/*
	while (node)
	{
		printf("%d\n", node->value);
		node = node->next;
	}
	*/
}
