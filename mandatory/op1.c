/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:13:52 by yecsong           #+#    #+#             */
/*   Updated: 2022/10/29 12:01:46 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
