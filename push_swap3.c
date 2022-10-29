/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:30:26 by yecsong           #+#    #+#             */
/*   Updated: 2022/10/29 12:26:34 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	node_len(t_node *node)
{
	int	i;

	i = 0;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}

int	direction(t_node *node, int value)
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

void	a_to_b(t_info **info)
{
	int	chunk;
	int	i;

	i = 0;
	chunk = 30;
	while (node_len((*info)->a))
	{
		if ((*info)->a->value > i + chunk)
			ra(info);
		else if ((*info)->a->value > i && (*info)->a->value <= i + chunk)
		{
			pb(info);
			rb(info);
			i++;
		}
		else if ((*info)->a->value <= i)
		{
			pb(info);
			i++;
		}
	}
}

void	b_to_a(t_info **info)
{
	int	len;


	while ((*info)->stack_size != -1)
	{
		len = direction((*info)->b, ((*info)->stack_size));
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
		write(2, "Error\n",6);
		return (-1);
	}
	init_node(&info, info->order);
	a_to_b(&info);
	b_to_a(&info);
	t_node *node;

	node = info->a;
	while (node)
	{
		printf("%d\n", node->value);
		node = node->next;
	}
}
