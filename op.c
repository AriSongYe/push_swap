/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:54:03 by yecsong           #+#    #+#             */
/*   Updated: 2022/09/15 16:34:27 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pop function return struct
t_num	*pop(t_num **list)
{
	t_num	*node;

	node = *list;
	if (!node)
		return (NULL);
	*list = node->next;
	return (node);
}

// push function return pop's struct
void	push(t_num **list, t_num **put)
{
	if (!(*put))
		return ;
	if (!(*list))
	{
		(*put)->next = NULL;
		*list = *put;
	}
	else
	{
		(*put)->next = (*list);
		*list = *put;
	}
}


t_num	*last_node(t_num *list)
{
	t_num	*temp;

	if (!list)
		return (NULL);
	temp = list;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	op_rrr(t_num **a, t_num **b)
{
	t_num	*last;
	t_num	*temp;

	if (!*a || !*b || !(*a)->next || !(*b)->next)
		return ;
	temp = *a;
	last = last_node(*a);
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	push(a, &last);
	temp = *b;
	last = last_node(*b);
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	push(b, &last);
}

void	op_r_rot(t_num **a, int is_a)
{
	t_num	*last;
	t_num	*temp;

	temp = *a;
	if (*a)
	{
		last = last_node(*a);
		while (temp->next != last)
			temp = temp->next;
		temp->next = NULL;
		push(a, &last);
		if (!is_a)
			write(1, "rrb\n", 4);
		else
			write(1, "rra\n", 4);
	}
}

void	op_rr(t_num **a, t_num **b)
{
	t_num	*temp;
	t_num	*last;
	
	if (!*a || !*b || !(*a)->next || !(*b)->next)
		return ;
	temp = pop(a);
	last = last_node(*a);
	last->next = temp;
	temp->next = NULL;
	temp = pop(b);
	last = last_node(*b);
	last->next = temp;
	temp->next = NULL;
	write(1, "rr\n", 3);
}

void	op_rot(t_num **a, int is_a)
{
	t_num	*temp_1;
	t_num	*last;
	
	if (*a)
	{
		temp_1 = pop(a);
		last = last_node(*a);
		last->next = temp_1;
		temp_1->next = NULL;
		if (!is_a)
			write(1, "rb\n", 3);
		else
			write(1, "ra\n", 3);
	}
}

void	op_swap(t_num **a, int is_a)
{
	t_num	*temp_1;
	t_num	*temp_2;

	if (*a)
	{
		temp_1 = pop(a);
		temp_2 = pop(a);
		push(a, &temp_1);
		push(a, &temp_2);
		if (!is_a)
			write(1, "sb\n", 3);
		else
			write(1, "sa\n", 3);
	}

}

void	op_swap_ss(t_num **a, t_num **b)
{
	t_num	*temp_1;
	t_num	*temp_2;

	if (!*a || !*b || !(*a)->next || !(*b)->next)
		return ;
	temp_1 = pop(a);
	temp_2 = pop(a);
	push(a, &temp_1);
	push(a, &temp_2);
	temp_1 = pop(b);
	temp_2 = pop(b);
	push(b, &temp_1);
	push(b, &temp_2);
	write(1, "ss\n", 3);
}

void	op_push(t_num **a, t_num **b, int is_a)
{
	t_num	*temp;

	if (!is_a && (*a))
	{
		temp = pop(a);
		push(b, &temp);
		write(1, "pb\n", 3);
	}
	else if (is_a && (*b))
	{
		temp = pop(b);
		push(a, &temp);
		write(1, "pa\n", 3);
	}
}

void	first_push(t_num **list, int value)
{
	t_num	*node;

	node = malloc(sizeof(t_num));
	if (!node)
		return ;
	if (*list == NULL)
	{
		node->value = value;
		node->next = NULL;
		*list = node;
	}
	else
	{
		node->value = value;
		node->next = *list;
		*list = node;
	}
}
