/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:02:49 by yecsong           #+#    #+#             */
/*   Updated: 2022/10/26 18:04:48 by yecsong          ###   ########.fr       */
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
	t_node	*a_head;
	t_node	*b_head;
}	t_info;

#endif
