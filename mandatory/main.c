/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:30:26 by yecsong           #+#    #+#             */
/*   Updated: 2022/11/02 20:19:35 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b_2(t_info **info, int *size, int *i, int chunk)
{
	if ((*info)->a->value > (*i) && \
			(*info)->a->value <= (*i) + chunk)
	{
		pb(info);
		rb(info);
		(*size)--;
		(*i)++;
	}
	else if ((*info)->a->value <= *i)
	{
		pb(info);
		(*size)--;
		(*i)++;
	}
}

void	a_to_b(t_info **info)
{
	int	size;
	int	chunk;
	int	i;

	i = 0;
	if ((*info)->stack_size <= 100)
		chunk = 17;
	else
		chunk = 29;
	size = (*info)->stack_size;
	while (node_len((*info)->a))
	{
		if ((*info)->a->value > i + chunk)
		{
			if (direction_a((*info)->a, i + chunk) < size / 2)
				ra(info);
			else
				rra(info);
		}
		a_to_b_2(info, &size, &i, chunk);
	}
}

void	b_to_a(t_info **info)
{
	int	len;

	(*info)->stack_size--;
	while ((*info)->stack_size != -1)
	{
		len = direction_b((*info)->b, ((*info)->stack_size));
		if ((*info)->stack_size == (*info)->b->value)
		{
			pa(info);
			(*info)->stack_size--;
		}
		else if (len < (*info)->stack_size / 2)
			rb(info);
		else if (len >= (*info)->stack_size / 2)
			rrb(info);
	}
}

int	main(int argc, char **argv)
{
	t_info	*info;

	info = init_info(argc, argv);
	if (check_valid_num(&info))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (info->stack_size < 2)
		return (0);
	init_node(&info, info->order);
	if (is_sorted(&info))
		return (0);
	if (info->stack_size < 6)
		a_few_num(&info);
	else
	{
		a_to_b(&info);
		b_to_a(&info);
	}
	t_node	*node;
	node = info->a;
}

