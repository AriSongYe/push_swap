/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pracitce_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:54:03 by yecsong           #+#    #+#             */
/*   Updated: 2022/09/08 14:49:32 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// index == 0 -> a , index == 1 -> b
typedef struct s_num
{
	int				value;
	struct s_num	*next;
}	t_num;

t_num	*last_node(t_num *list)
{
	t_num	*temp;

	if (!list)
		return (NULL);
	temp = list;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	push_num(t_num **list, int value)
{
	t_num	*node;

	node = malloc(sizeof(t_num));
	if (!node)
		return ;
	node->value = value;
	node->next = *list;
	*list = node;
}

void	op_rot(t_num **list, int index)
{
	t_num	*node;
	t_num	*last;

	node = *list;
	last = last_node(*list);
	*list = node->next;
	last->next = node;
	node->next = NULL;
	if (index == 0)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}
void	op_rrot(t_num **list, int index)
{
	t_num	*node;
	t_num	*last;

	node = *list;
	last = last_node(*list);
	last->next = node;
	*list = last;
	while (node->next != *list)
		node = node->next;
	node->next = NULL;
	if (index == 0)
		write(1, "rra\n", 4);
	else if (index == 1)
		write(1, "rrb\n", 4);
	else
		;
}

void	op_rr(t_num **list_1, t_num **list_2)
{
	op_rrot(list_1, 3);
	op_rrot(list_2, 3);
	write(1, "rr\n", 3);
}

void	op_push(t_num **list_1, t_num **list_2, int index)
{
	t_num	*node_1;
	t_num	*node_2;

		node_1 = *list_1;
		node_2 = *list_2;
	if (index == 0)
	{
		*list_2 = node_2->next;
		node_2->next = node_1;
		*list_1 = node_2;
		write(1, "pa\n", 3);
	}
	else if (index == 1)
	{
		*list_1 = node_1->next;
		node_1->next = node_2;
		*list_2 = node_1;
		write(1, "pb\n", 3);
	}
}

void	op_swap_ss(t_num **list_1, t_num **list_2)
{
	t_num	*node;
	int		temp;

	node = *list_1;
	temp = node->value;
	node->value = node->next->value;
	node->next->value = temp;
	node = *list_2;
	temp = node->value;
	node->value = node->next->value;
	node->next->value = temp;
	write(1, "ss\n", 3);
}

void	op_swap(t_num **list, int index)
{
	t_num	*node;
	int		temp;

	node = *list;
	temp = node->value;
	node->value = node->next->value;
	node->next->value = temp;
	if (index == 0)
		write(1, "sa\n", 3);
	else if (index == 1)
		write(1, "sb\n", 3);
}

int main(int argc, char **argv)
{
	t_num	*a;
	t_num	*b;
	int		i;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	i = argc - 1;
	while (i > 0)
	{
		push_num(&a, atoi(argv[i]));
		i--;
	}
	op_rrot(&a, 1);
	op_push(&a, &b, 1);
	while (a)
	{
		printf("a = %d\n", a->value);
		a = a->next;
	}
	while (b)
	{
		printf("b = %d\n", b->value);
		b = b->next;
	}
	//printf("a top3 :%d\n", a->next->next->value);
}
