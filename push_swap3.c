/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:30:26 by yecsong           #+#    #+#             */
/*   Updated: 2022/10/28 17:35:49 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_dptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

t_info *init_info(int argc, char **argv)
{
	t_info *info;
	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->argc = argc;
	info->argv = argv;
	info->a = NULL;
	info->b = NULL;
	info->str = NULL;
	info->order = NULL;
	return (info);
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

int	is_over(char **str)
{
	long long	num;
	int			i;

	i = 0;
	while (str[i])
	{
		if (ft_strlen(str[i]) >= 11)
		{
			return (1);
		}
		num = ft_atoll(str[i++]);
		if (num > 2147483647 || num < -2147483648)
			return (1);
	}
	return (0);
}

int	is_repeat(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_strncmp(str[i], str[j], ft_strlen(str[i]) + 1) == 0)
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
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
int	check_valid_num(t_info **info)
{
	int 	i;

	if ((*info)->argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	i = 1;
	while (i < (*info)->argc)
	{
		(*info)->str = ft_split((*info)->argv[i], ' ');
		if (is_num((*info)->str))
			return (1);
		else if (is_over((*info)->str))
			return (1);
		else if (is_repeat((*info)->str))
			return (1);
		i++;
		free_dptr((*info)->str);
	}
	return (0);
}

int	get_size_num(t_info **info)
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
void	parsing_num(t_info **info)
{
	int	i;
	int	j;
	int	index;

	(*info)->order = malloc(sizeof(int) * get_size_num(info));
	index = 0;
	i = 1;
	while (i < (*info)->argc)
	{
		(*info)->str = ft_split((*info)->argv[i], ' ');
		j = 0;
		while ((*info)->str[j])
		{
			(*info)->order[index++] = ft_atoi((*info)->str[j]);
			j++;
		}
		free_dptr((*info)->str);
		i++;
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
	parsing_num(&info);
	system("leaks push_swap");
}
