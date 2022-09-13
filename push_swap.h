/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:34:54 by yecsong           #+#    #+#             */
/*   Updated: 2022/09/13 13:37:33 by yecsong          ###   ########.fr       */
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

void	op_swap(t_num **list, int index);
void	op_swap_ss(t_num **list_1, t_num **list_2);
void	op_push(t_num **list_1, t_num **list_2, int index);
void	op_rr(t_num **list_1, t_num **list_2);
void	op_rrot(t_num **list, int index);
void	op_rot(t_num **list, int index);
void	push_num(t_num **list, int value);
t_num	*last_node(t_num *list);
#endif
