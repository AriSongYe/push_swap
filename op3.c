/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:15:19 by yecsong           #+#    #+#             */
/*   Updated: 2022/10/29 11:20:33 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
