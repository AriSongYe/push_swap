/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:15:59 by yecsong           #+#    #+#             */
/*   Updated: 2022/10/29 11:17:06 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
