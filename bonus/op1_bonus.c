/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:13:52 by yecsong           #+#    #+#             */
/*   Updated: 2022/11/02 20:13:15 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}
