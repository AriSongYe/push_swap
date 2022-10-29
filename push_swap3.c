/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:30:26 by yecsong           #+#    #+#             */
/*   Updated: 2022/10/29 11:07:30 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_info	*info;

	info = init_info(argc, argv);
	if (check_valid_num(&info))
	{
		write(2, "Error\n",6);
		return (-1);
	}
	int	i;
	i = 0;
	while (info->order[i])
		printf("order = %d\n", info->order[i++]);
	system("leaks push_swap");
}
