/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_num_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:56:23 by yecsong           #+#    #+#             */
/*   Updated: 2022/11/17 16:56:21 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_valid_num(t_info **info)
{
	int	i;

	i = 1;
	while (i < (*info)->argc)
	{
		(*info)->str = ft_split((*info)->argv[i], ' ');
		if (is_num((*info)->str))
			return (1);
		else if (is_over((*info)->str))
			return (1);
		free_dptr((*info)->str);
		i++;
	}
	parsing_num(info);
	get_order(info);
	if (is_repeat(info))
		return (1);
	return (0);
}

int	is_over(char **str)
{
	long long	num;
	int			i;

	i = 0;
	while (str[i])
	{
		if (ft_strlen(str[i]) >= 12)
		{
			return (1);
		}
		num = ft_atoll(str[i++]);
		if (num > 2147483647 || num < -2147483648)
			return (1);
	}
	return (0);
}

int	is_repeat(t_info **info)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*info)->stack_size)
	{
		j = i + 1;
		while (j < (*info)->stack_size)
		{
			while ((*info)->order[i] == (*info)->order[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_num(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!((str[i][j] >= '0' && str[i][j] <= '9')
						|| str[i][j] == '-' || str[i][j] == '+'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

long long	ft_atoll(const char *str)
{
	int			sign;
	size_t		i;
	long long	num;

	num = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * num);
}
