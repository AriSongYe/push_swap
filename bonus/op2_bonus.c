/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:14:48 by yecsong           #+#    #+#             */
/*   Updated: 2022/11/02 20:18:42 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	write(1, "ss\n", 3);
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
