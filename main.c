/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:34:22 by yecsong           #+#    #+#             */
/*   Updated: 2022/09/15 17:12:55 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		struct_len(t_num **a)
{
	t_num	*node;

	node = *a;
	int	i;

	i = 0;
	if (!node)
		return (0);
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}
void	bubble_sort(t_num **a, t_num **b)
{
	int	len;
	int	i;

	len = struct_len(a) -1;
	while (len)
	{
		i = 0;
		while (i < len)
		{
			if ((*a)->value < (*a)->next->value)
				op_push(a, b, 0);
			else
			{
				op_swap(a, 1);
				op_push(a, b, 0);
			}
			i++;
		}
		i = 0;
		while (i++ < len)
			op_push(a, b ,1);
		len--;
	}
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
		first_push(&a, atoi(argv[i]));
		i--;
	}
	bubble_sort(&a, &b);
	/*while (a)
	{
		printf("a = %d\n", a->value);
		a = a->next;
	}
	while (b)
	{
		printf("b = %d\n", b->value);
		b = b->next;
	}
	*/
}