/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circlst_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:25:33 by acardona          #+#    #+#             */
/*   Updated: 2022/12/23 19:37:22 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_circlst_len(t_lstcirc *lst_top)
{
	int			i;
	t_lstcirc	*elem;

	if (!lst_top)
		return (0);
	elem = lst_top;
	i = 1;
	while (elem->down != lst_top)
	{
		i++;
		elem = elem->down;
	}
	return (i);
}
