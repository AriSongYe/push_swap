/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:56:11 by yecsong           #+#    #+#             */
/*   Updated: 2022/10/27 21:46:02 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_info **info, int len);

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

void	init_node(t_info **info)
{
	t_node	*a;
	t_node	*new;
	t_node	*last;
	int		i;
	
	i = (*info)->argc - 2;
	a = new_node(ft_atoi((*info)->argv[(*info)->argc - 1]));
	(*info)->a = a;
	while (i > 0)
	{
		new = new_node(ft_atoi((*info)->argv[i]));
		last = last_node(a);
		last->next = new;
		i--;
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
	(*info)->a = node->next;
	push_back(info, &pop, 1);
	write (1, "ra\n", 3);
}

void	rb(t_info **info)
{
	t_node	*node;
	t_node	*pop;

	if (!(*info)->a)
	{
		write(2, "a is empty stack\n", 17);
		return ;
	}
	node = (*info)->b;
	pop = pop_b(info);
	(*info)->b = node->next;
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

int	min_max(t_node *node, int is_max)
{
	int	min;
	int	max;

	max = -2147483647;
	min = 2147483647;

	
	while (node)
	{
		if (min > node->value)
			min = node->value;
		if (max < node->value)
			max = node->value;
		node = node->next;
	}
	if (is_max)
		return (max);
	else
		return (min);
}

int	node_len(t_node *node)
{
	int i;

	i = 0;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}
void	b_to_a(t_info **info, int len)
{
	int	pa_cnt;
	int	rb_cnt;
	int pivot;
	int	i;

	pa_cnt = 0;
	rb_cnt = 0;
	i = 0;
	pivot = (min_max((*info)->b, 1) + min_max((*info)->b, 0)) /2;
	if (len == 1)
		return ;
	while(i < len)
	{
		if (pivot <= (*info)->b->value)
		{
			pa(info);
			pa_cnt++;
		}
		else
		{
			rb(info);
			rb_cnt++;
		}
		i++;
	}
	while (i < rb_cnt)
	{
		rrb(info);
		i++;
	}
	b_to_a(info, rb_cnt);
	a_to_b(info, pa_cnt);
}

void	a_to_b(t_info **info, int len)
{
	int	pb_cnt;
	int	ra_cnt;
	int pivot;
	int	i;

	pb_cnt = 0;
	ra_cnt = 0;
	i = 0;
	pivot = (min_max((*info)->a, 1) + min_max((*info)->a, 0)) /2;
	if (len == 1)
		return ;
	while(i < len)
	{
		if (pivot >= (*info)->a->value)
		{
			pb(info);
			pb_cnt++;
		}
		else
		{
			ra(info);
			ra_cnt++;
		}
		i++;
	}
	i = 0;
	while (i < ra_cnt)
	{
		rra(info);
		i++;
	}
	a_to_b(info, ra_cnt);
	b_to_a(info, pb_cnt);

}

int	main(int argc, char **argv)
{
	t_info	*info;
	t_node	*node;
	if (argc < 3)
	{
		write(2, "Error: arguments is not enough!\n", 32);
		return (-1);
	}
	info = init_info(argc, argv);
	init_node(&info);
	a_to_b(&info, node_len(info->a));
	node = info->a;
	while (node)
	{
		printf("a node = %d\n", node->value);
		node = node->next;
	}
	node = info->b;
	while (node)
	{
		printf("b node = %d\n", node->value);
		node = node->next;
	}
}
