/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_few_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:14:18 by yecsong           #+#    #+#             */
/*   Updated: 2022/11/02 16:20:31 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_few_num(t_info **info)
{
	if ((*info)->stack_size == 2)
		sa(info);
	else if ((*info)->stack_size == 3)
		num_3(info, 0);
	else if ((*info)->stack_size == 4)
		num_4(info);
	else if ((*info)->stack_size == 5)
		num_5(info);
}

int	find_small_num(t_info **info)
{
	t_node	*node;
	int		small;

	small = 6;
	node = (*info)->a;
	while (node)
	{
		if (small > node->value)
			small = node->value;
		node = node->next;
	}
	return (small);
}

void	num_3(t_info **info, int sign)
{
	if (is_sorted(info))
		return ;
	if ((*info)->a->value == sign + 0)
	{
		rra(info);
		sa(info);
	}
	else if ((*info)->a->value == sign + 1)
	{
		if ((*info)->a->next->value == sign + 0)
			sa(info);
		else
			rra(info);
	}
	else if ((*info)->a->value == sign + 2)
	{
		if ((*info)->a->next->value == sign + 0)
			ra(info);
		else
		{
			sa(info);
			rra(info);
		}
	}
}

void	num_4(t_info **info)
{
	int	small;

	small = find_small_num(info);
	while ((*info)->a->value != small)
		ra(info);
	pb(info);
	num_3(info, 1);
	pa(info);
}

void	num_5(t_info **info)
{
	int	small;

	small = find_small_num(info);
	while ((*info)->a->value != small)
		ra(info);
	pb(info);
	small = find_small_num(info);
	while ((*info)->a->value != small)
		ra(info);
	pb(info);
	num_3(info, 2);
	if ((*info)->b->value < (*info)->b->next->value)
		rb(info);
	pa(info);
	pa(info);
}
