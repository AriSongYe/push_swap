/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:34:44 by yecsong           #+#    #+#             */
/*   Updated: 2022/11/02 17:13:48 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	direction_a(t_node *node, int value)
{
	int	i;

	i = 0;
	while (node->value > value)
	{
		node = node->next;
		i++;
	}
	return (i);
}

int	direction_b(t_node *node, int value)
{
	int	i;

	i = 0;
	while (node->value != value)
	{
		node = node->next;
		i++;
	}
	return (i);
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
	while (i < (*info)->stack_size)
	{
		new = new_node(order[i]);
		last = last_node(a);
		last->next = new;
		i++;
	}
}
