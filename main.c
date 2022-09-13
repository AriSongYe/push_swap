/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:34:22 by yecsong           #+#    #+#             */
/*   Updated: 2022/09/13 13:43:06 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_num **a, t_num **b)
{
   
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
}
