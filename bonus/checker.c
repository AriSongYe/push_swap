/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:10:54 by yecsong           #+#    #+#             */
/*   Updated: 2022/11/02 19:49:43 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_valid_ins(char *inst, t_info **info)
{
	if (ft_strncmp(inst, "sa", 3))
		sa(info);
	else if(ft_strncmp(inst, "sb", 3))
		sb(info);
	else if(ft_strncmp(inst, "ss", 3))
		ss(info);
	else if(ft_strncmp(inst, "ra", 3))
		ra(info);
	else if(ft_strncmp(inst, "rb", 3))
		rb(info);
	else if(ft_strncmp(inst, "rr", 3))
		rr(info);
	else if(ft_strncmp(inst, "pa", 3))
		pa(info);
	else if(ft_strncmp(inst, "pb", 3))
		pb(info);
	else if(ft_strncmp(inst, "rra", 4))
		rra(info);
	else if(ft_strncmp(inst, "rrb", 4))
		rrb(info);
	else if(ft_strncmp(inst, "rrr", 4))
		rrr(info);
	else
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	char	*inst;

	info = init_info(argc, argv);
	if (check_valid_num(&info))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (info->stack_size < 2)
		return (0);
	init_node(&info, info->order);
	while (1)
	{
		inst = get_next_line(0);
		if(!inst)
			break;
		if (check_valid_ins(inst, &info))
		{
			write(2, "Error\n", 6);
			return (-1);
		}
	}
	if (is_sorted(&info))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
