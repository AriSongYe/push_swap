/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:02:49 by yecsong           #+#    #+#             */
/*   Updated: 2022/10/29 12:00:49 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"

typedef	struct	s_node
{
	struct	s_node *next;
	int		value;
}	t_node;

typedef	struct	s_info
{
	t_node	*a;
	t_node	*b;
	int		argc;
	int		*order;
	int		*stack;
	int		stack_size;
	char	**argv;
	char	**str;
}	t_info;

t_info	*init_info(int argc,  char **argv);
void	init_node(t_info **info, int *order);
void	free_dptr(char **ptr);
void	get_order(t_info **info);
void	parsing_num(t_info **info);
int		is_num(char **str);
int		is_over(char **str);
int		is_repeat(int *stack);
int		check_valid_num(t_info **info);
int		get_stack_size(t_info **info);
int		get_first_index(t_info **info);
long long	ft_atoll(const char *str);
t_node	*last_node(t_node *node);
t_node	*pop_a(t_info **info);
t_node	*pop_b(t_info **info);
void	push_front(t_info **info, t_node **new_node, int is_a);
void	push_back(t_info **info, t_node **new_node, int is_a);
void	sa(t_info **info);
void	sb(t_info **info);
void	ss(t_info **info);
void	pa(t_info **info);
void	pb(t_info **info);
void	ra(t_info **info);
void	rb(t_info **info);
void	rr(t_info **info);
void	rra(t_info **info);
void	rrb(t_info **info);
void	rrr(t_info **info);

#endif
