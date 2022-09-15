/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:34:54 by yecsong           #+#    #+#             */
/*   Updated: 2022/09/15 16:34:57 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_num
{
	int				value;
	struct s_num	*next;
}	t_num;

void	first_push(t_num **list, int value);
void	push(t_num **list_1, t_num **list_2);
void	op_push(t_num **a, t_num **b, int is_a);
void	op_swap_ss(t_num **a, t_num **b);
void	op_swap(t_num **a, int is_a);
void	op_r_rot(t_num **a, int is_a);
void	op_rot(t_num **a, int is_a);
void	op_rr(t_num **a, t_num **b);
void	op_rrr(t_num **a, t_num **b);
t_num	*pop(t_num **list);
t_num	*last_node(t_num *list);
#endif
