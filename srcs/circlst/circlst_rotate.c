/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circlst_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:00:07 by acardona          #+#    #+#             */
/*   Updated: 2022/12/24 11:38:27 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*ra || rb : rotation, move the origin one element upward. It corresponds to
 moving each element of the pile downward and puting the bottom one on top*/
int	ft_circlst_rotate(t_lstcirc **lst_top)
{
	if (!lst_top)
		return (1);
	else if (!(*lst_top) || !((*lst_top)->up))
		return (0);
	*lst_top = (*lst_top)->down;
	return (0);
}

/*rr : double rotation, apply the previous rotation (ft_circlst_rotate) to the
 2 given lists*/
int	ft_circlst_rotate2(t_lstcirc **lst_top1, t_lstcirc **lst_top2)
{
	int	i;

	i = 0;
	i += ft_circlst_rotate(lst_top1);
	i += ft_circlst_rotate(lst_top2);
	return (i);
}

/*rra || rrb : reverse rotation, opposit of ft_circlst_rotate : move all
 elements upward, the first one become the lastone*/
int	ft_circlst_rev_rotate(t_lstcirc **lst_top)
{
	if (!lst_top)
		return (1);
	else if (!(*lst_top) || !((*lst_top)->up))
		return (0);
	*lst_top = (*lst_top)->up;
	return (0);
}

/*rrr : double reverse rotation, apply the previous reversed rotation 
(ft_circlst_rev_rotate) to the 2 given lists*/
int	ft_circlst_rev_rotate2(t_lstcirc **lst_top1, t_lstcirc **lst_top2)
{
	int	i;

	i = 0;
	i += ft_circlst_rev_rotate(lst_top1);
	i += ft_circlst_rev_rotate(lst_top2);
	return (i);
}
