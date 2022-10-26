/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:02:23 by yecsong           #+#    #+#             */
/*   Updated: 2022/10/26 19:45:29 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info *init_info()
{
	t_info *info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->a_head = NULL;
	info->b_head = NULL;
	return (info);
}

t_node	*last_node(t_node *node)
{
	t_node	*temp;

	if (!node)
		return (NULL);
	temp = node;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

t_node	*new_node(int value)
{
	t_node	*new_node;
	
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	return (new_node);
}

t_node	*init_node(int argc, char **argv)
{
	t_node	*a_node;
	t_node	*temp;
	t_node	*last;
	int		i;

	a_node = new_node(ft_atoi(argv[argc - 1]));
	a_node->next = NULL;
	i = argc - 2;
	while (i > 0)
	{
		tmp = new_node(ft_atoi(argv[i]));
		last = last_node(a_node);
		last->next = temp;
		i--;
	}
	return (a_node);
}

t_node	*pop(t_node **node, t_info **info, int is_a)
{
	t_node	*temp;

	temp = *node;
	if (!temp)
		return (NULL);
	else if (temp && temp->next == NULL)
		*node = NULL;
	else
		*node = temp->next;
	if (is_a)
		(*info)->a_head = *node;
	else
		(*info)->b_head = *node;
	return (temp);
}

void	push(t_node **node, t_node **put, t_info **info, int is_a)
{
	if (!(*put))
		return ;
	if (!(*node))
	{
		(*node) = (*put);
		(*node)->next = NULL;
	}
	else
	{
		(*put)->next = (*node);
		(*node) = (*put);
	}
	if (is_a)
		(*info)->a_head = *node;
	else
		(*info)->b_head = *node;
}

void	sa(t_node **a_node, t_info **info)
{
	t_node	*temp_1;
	t_node	*temp_2;

	if (!*a_node || !(*a_node)->next)
	{
		write(2, "a is an empty stack", 20);
		return ;
	}
	temp_1 = pop(a_node, info, 1);
	temp_2 = pop(a_node, info, 1);
	push(a_node, &temp_1, info, 1);
	push(a_node, &temp_2, info, 1);
	write(1, "sa\n", 3);
}

void	sb(t_node **b_node, t_info **info)
{
	t_node	*temp_1;
	t_node	*temp_2;

	if (!*b_node || !(*b_node)->next)
	{
		write(2, "b is an empty stack", 20);
		return ;
	}
	temp_1 = pop(b_node, info, 0);
	temp_2 = pop(b_node, info, 0);
	push(b_node, &temp_1, info, 0);
	push(b_node, &temp_2, info, 0);
	write(1, "sb\n", 3);
}

void	ss(t_node **a_node, t_node **b_node, t_info **info)
{
	t_node *temp_1;
	t_node *temp_2;

	if(!*a_node || !*b_node || !(*a_node)->next || !(*b_node)->next)
	{

		write(2, "plz check your stack", 22);
		return ;
	}
	temp_1 = pop(a_node, info, 1);
	temp_2 = pop(a_node, info, 1);
	push(a_node, &temp_1, info, 1);
	push(a_node, &temp_2, info, 1);
	temp_1 = pop(b_node, info, 0);
	temp_2 = pop(b_node, info, 0);
	push(b_node, &temp_1, info, 0);
	push(b_node, &temp_2, info, 0);
	write(1, "ss\n", 3);
}

void	ra(t_node **a_node, t_info **info)
{
	t_node	*temp;
	t_node	*last;

	if (*a_node)
	{
		temp = pop(a_node, info, 1);
		last = last_node(*a_node);
		last->next = temp;
		write(1, "ra\n", 3);
	}
	else
	{
		write(2, "plz check your stack", 22);
		return ;
	}
}

void	rb(t_node **b_node, t_info **info)
{
	t_node	*temp;
	t_node	*last;

	if (*b_node)
	{
		temp = pop(b_node, info, 0);
		last = last_node(*b_node);
		last->next = temp;
		write(1, "rb\n", 3);
	}
	else
	{
		write(2, "plz check your stack", 22);
		return ;
	}
}

void	rr(t_node **a_node, t_node **b_node, t_info **info)
{
	t_node	*temp;
	t_node	*last;

	if (*a_node && *b_node)
	{
		temp = pop(a_node, info, 1);
		last = last_node(*a_node);
		last->next = temp;
		temp = pop(b_node, info, 0);
		last = last_node(*b_node);
		last->next = temp;
		write(1, "rr\n", 3);
	}
	else
	{
		write(2, "plz check your stack", 22);
		return ;
	}
}

void	rra(t_node **a_node, t_info **info)
{
	t_node	*last;
	t_node	*temp;

	temp = *a_node;
	if (*a_node)
	{
		last = last_node(*a_node);
		while (temp->next != last)
			temp = temp->next;
		temp->next = NULL;
		push(a_node, &last, info, 1);
		write(1, "rra\n", 4);
	}
	else
	{
		write(2, "plz check your stack", 22);
		return ;
	}
}

void	rrb(t_node **b_node, t_info **info)
{
	t_node	*last;
	t_node	*temp;

	temp = *b_node;
	if (*b_node)
	{
		last = last_node(*b_node);
		while (temp->next != last)
			temp = temp->next;
		temp->next = NULL;
		push(b_node, &last, info, 0);
		write(1, "rrb\n", 4);
	}
	else
	{
		write(2, "plz check your stack", 22);
		return ;
	}
}

void	rrr(t_node **a_node, t_node **b_node, t_info **info)
{
	t_node	*temp;
	t_node	*last;

	if (*a_node && *b_node)
	{
		temp = *a_node;
		last = last_node(*a_node);
		while (temp->next != last)
			temp = temp->next;
		temp->next = NULL;
		push(a_node, &last, info, 1);
		temp = *b_node;
		last = last_node(*b_node);
		while (temp->next != last)
			temp = temp->next;
		temp->next = NULL;
		push(b_node, &last, info, 1);
		write(1, "rrr\n", 4);
	}
	else
	{
		write(2, "plz check your stack", 22);
		return ;
	}
}

void	pa(t_node **a_node, t_node **b_node, t_info **info)
{
	t_node	*temp;

	if (*b_node)
	{
		temp = pop(b_node, info, 0);
		push(a_node, &temp, info, 1);
		write(1, "pa\n", 3);
	}
	else
	{
		write(2, "plz check your stack", 22);
		return ;
	}
}

void	pb(t_node **a_node, t_node **b_node, t_info **info)
{
	t_node	*temp;

	if (*a_node)
	{
		temp = pop(a_node, info, 1);
		push(b_node, &temp, info, 0);
		write(1, "pb\n", 3);
	}
	else
	{
		write(2, "plz check your stack", 22);
		return ;
	}
}

int	node_len(t_node *a_node)
{
	int	i;

	i = 0;
	while (a_node)
	{
		a_node = a_node->next;
		i++;
	}
	return (i);
}

int	find_min_max(t_node **a_node, int is_max)
{
	t_node	*temp;
	int	max;
	int	min;

	temp = *a_node;
	max = -2147483647;
	min	= 2147483647;
	while (temp)
	{
		if (max < temp->value)
			max = temp->value;
		if (min > temp->value)
			min = temp->value;
		temp = temp->next;
	}
	if (is_max)
		return (max);
	else
		return (min);
}

void	a_to_b(t_node **a_node, t_node **b_node, t_info **info, int len)
{
	int		i;
	int		ra_cnt;
	int		pb_cnt;
	int		pivot;
	t_node	*temp;

	i = 0;
	pb_cnt = 0;
	ra_cnt = 0;
	temp = *info->head;
	pivot = (find_min_max(a_node, 1) + find_min_max(a_node, 0)) / 2;
	while (i++ < len)
	{
		if (temp->value < pivot)
		{
			pb(a_node, b_node, info);
			pb_cnt++;
		}
		else
		{
			ra(a_node, info);
			ra_cnt++;
		}
	}
	i = 0;
	while (i++ < ra_cnt)
		rra(a_node, info);
}
int main(int argc, char **argv)
{
	t_node	*a_node;
	t_node	*b_node;
	t_info	*info;

	info = init_info();
	a_node = init_node(argc, argv);
	b_node = NULL;


	//a_info->head = a_node;
	printf("node = %d\n", a_node->value);
	printf("node = %d\n", a_node->next->value);
	printf("node = %d\n", a_node->next->next->value);
	//printf("node = %d\n", a_node->next->next->value);
	pb(&a_node, &b_node, &info);
	printf("node = %d\n", a_node->value);
	printf("node = %d\n", b_node->value);
	printf("node = %d\n", info->a_head->value);
	printf("node = %d\n", info->b_head->value);
	printf("node = %d\n", a_node->next->value);
	printf("len = %d\n", node_len(a_node));
}
