/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:10:54 by yecsong           #+#    #+#             */
/*   Updated: 2022/11/16 17:19:36 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_valid_ins(char *inst, t_info **info)
{
	if (!ft_strncmp(inst, "sa\n", 4))
		sa(info);
	else if (!ft_strncmp(inst, "sb\n", 4))
		sb(info);
	else if (!ft_strncmp(inst, "ss\n", 4))
		ss(info);
	else if (!ft_strncmp(inst, "ra\n", 4))
		ra(info);
	else if (!ft_strncmp(inst, "rb\n", 4))
		rb(info);
	else if (!ft_strncmp(inst, "rr\n", 4))
		rr(info);
	else if (!ft_strncmp(inst, "pa\n", 4))
		pa(info);
	else if (!ft_strncmp(inst, "pb\n", 4))
		pb(info);
	else if (!ft_strncmp(inst, "rra\n", 5))
		rra(info);
	else if (!ft_strncmp(inst, "rrb\n", 5))
		rrb(info);
	else if (!ft_strncmp(inst, "rrr\n", 5))
		rrr(info);
	else
		return (1);
	return (0);
}

int	read_inst(t_info **info)
{
	char	*inst;

	while (1)
	{
		inst = get_next_line(0);
		if (!inst)
			break ;
		if (check_valid_ins(inst, info))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		free(inst);
	}
	return (0);
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
	if (read_inst(&info))
		return (-1);
	if (is_sorted(&info))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
