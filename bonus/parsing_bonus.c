/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:06:27 by yecsong           #+#    #+#             */
/*   Updated: 2022/11/02 18:09:41 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	parsing_num(t_info **info)
{
	int	i;
	int	j;
	int	index;

	(*info)->stack = malloc(sizeof(int) * get_stack_size(info));
	index = 0;
	i = 1;
	while (i < (*info)->argc)
	{
		(*info)->str = ft_split((*info)->argv[i], ' ');
		j = 0;
		while (j <= get_first_index(info) - 1)
		{
			(*info)->stack[index++] = ft_atoi((*info)->str[j]);
			j++;
		}
		free_dptr((*info)->str);
		i++;
	}
	(*info)->stack_size = index;
}

void	get_order(t_info **info)
{
	int	i;
	int	j;
	int	cnt;

	(*info)->order = malloc(sizeof(int) * (*info)->stack_size);
	i = 0;
	while (i < (*info)->stack_size)
	{
		j = 0;
		cnt = 0;
		while (j < (*info)->stack_size)
		{
			if ((*info)->stack[i] > (*info)->stack[j])
				cnt++;
			j++;
		}
		(*info)->order[i] = cnt;
		i++;
	}
}

int	get_stack_size(t_info **info)
{
	int	i;
	int	j;
	int	index;

	i = 1;
	index = 0;
	while (i < (*info)->argc)
	{
		(*info)->str = ft_split((*info)->argv[i], ' ');
		j = 0;
		while ((*info)->str[j])
			j++;
		index = index + j;
		free_dptr((*info)->str);
		i++;
	}
	return (index);
}

int	get_first_index(t_info **info)
{
	int	i;

	i = 0;
	while ((*info)->str[i])
		i++;
	return (i);
}
