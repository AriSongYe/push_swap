/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:05:07 by yecsong           #+#    #+#             */
/*   Updated: 2022/11/02 22:00:09 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

t_info	*init_info(int argc, char **argv)
{
	t_info	*info;

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
