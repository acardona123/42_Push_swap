/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circlst_tools_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:25:33 by acardona          #+#    #+#             */
/*   Updated: 2023/01/10 19:40:32 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_circlst_len(t_lstcirc *lst_top)
{
	int			i;
	t_lstcirc	*elem;

	if (!lst_top)
		return (0);
	if ((*lst_top).down == 0)
		return (1);
	elem = lst_top;
	i = 1;
	while (elem->down != lst_top)
	{
		i++;
		elem = elem->down;
	}
	return (i);
}

/*Return 1 if the first n elements of the pile are sorted and 0 if not*/
int	ft_is_sorted(t_lstcirc *lst, int len)
{
	t_lstcirc	*elem;
	int			i;

	if (!lst)
		return (0);
	i = 0;
	elem = lst;
	if (!(elem->down))
		return (1);
	while (i < len && elem->down != lst)
	{
		if (elem->value > elem->down->value)
			return (0);
		elem = elem->down;
		i--;
	}
	return (1);
}
