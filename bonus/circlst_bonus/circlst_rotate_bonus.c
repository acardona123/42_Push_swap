/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circlst_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:00:07 by acardona          #+#    #+#             */
/*   Updated: 2023/01/10 20:50:08 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*ra || rb. msg is a mesage to be printed (0 if nothing)*/
int	ft_circlst_rotate(t_lstcirc **lst_top, char *msg)
{
	if (msg)
		ft_putendl_fd(msg, 1);
	if (!lst_top)
		return (1);
	else if (!(*lst_top) || !((*lst_top)->up))
		return (0);
	*lst_top = (*lst_top)->down;
	return (0);
}

/*rr*/
int	ft_circlst_rotate2(t_lstcirc **lst_top1, t_lstcirc **lst_top2)
{
	int	i;

	i = 0;
	i += ft_circlst_rotate(lst_top1, 0);
	i += ft_circlst_rotate(lst_top2, 0);
	return (i);
}

/*rra || rrb*/
int	ft_circlst_rev_rotate(t_lstcirc **lst_top, char *msg)
{
	if (msg)
		ft_putendl_fd(msg, 1);
	if (!lst_top)
		return (1);
	else if (!(*lst_top) || !((*lst_top)->up))
		return (0);
	*lst_top = (*lst_top)->up;
	return (0);
}

/*rrr*/
int	ft_circlst_rev_rotate2(t_lstcirc **lst_top1, t_lstcirc **lst_top2)
{
	int	i;

	i = 0;
	i += ft_circlst_rev_rotate(lst_top1, 0);
	i += ft_circlst_rev_rotate(lst_top2, 0);
	return (i);
}
