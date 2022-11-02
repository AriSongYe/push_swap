/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:30:26 by yecsong           #+#    #+#             */
/*   Updated: 2022/11/02 15:25:33 by yecsong          ###   ########.fr       */
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

void	a_to_b(t_info **info)
{
	int	chunk;
	int	size;
	int	i;

	i = 0;
	if ((*info)->stack_size < 100)
		chunk = 15;
	else
		chunk = 30;
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
		else if ((*info)->a->value > i && (*info)->a->value <= i + chunk)
		{
			pb(info);
			rb(info);
			size--;
			i++;
		}
		else if ((*info)->a->value <= i)
		{
			pb(info);
			i++;
			size--;
		}
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

int	is_sorted(t_info **info)
{
	t_node	*node;

	node = (*info)->a;
	
	while (node->next)
	{
		if (node->value > node->next->value)
			break ;
		node = node->next;
	}
	if (node == last_node((*info)->a))
		return (1);
	return (0);
}
void	num_3(t_info **info, int sign)
{
	if (is_sorted(info))
		return ;
	if ((*info)->a->value  == sign + 0)
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

void	a_few_num(t_info **info)
{
	if ((*info)->stack_size == 2)
		sa(info);
	else if((*info)->stack_size == 3)
		num_3(info, 0);
	else if ((*info)->stack_size == 4)
		num_4(info);
	else if ((*info)->stack_size == 5)
		num_5(info);
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
	if (is_sorted(&info))
		return (0);
	
	if (info->stack_size < 6)
		a_few_num(&info);
	
	else
	{
		a_to_b(&info);
		b_to_a(&info);
	}

//	int i;
	//t_node *node;
	/*
	i = 0;
	while (i < 5)
	{
		printf("order = %d\n", info->order[i++]);
	}
	*/
	
	/*
	node = info->a;
	while (node)
	{
		printf("%d\n", node->value);
		node = node->next;
	}
	*/
	/*
	node = info->b;
	while (node)
	{
		printf("%d\n", node->value);
		node = node->next;
	}
	*/
}
