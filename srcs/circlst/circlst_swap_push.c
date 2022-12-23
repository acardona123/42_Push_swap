/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circlst_swap_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:51:40 by acardona          #+#    #+#             */
/*   Updated: 2022/12/21 18:16:10 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Take the first element of lst2 and put it on top of lst1:
pa <=> ...push(A,B)
pb <=> ...push(B,A)
*/
int	ft_circlst_push(t_lstcirc **lst1, t_lstcirc **lst2)
{
	t_lstcirc	*elem;

	if (!(lst1 && lst2))
		return (1);
	if (!(*lst2))
		return (0);
	elem = *lst2;
	*lst2 = (*lst2)->down;
	return (ft_circlst_addtop(lst1, elem));
}

/*Swap the top 2 elemtents of the list initiated by lst_top*/
int	ft_circlst_swap(t_lstcirc **lst_top)
{
	t_lstcirc	*tmp;

	if (!lst_top)
		return (1);
	if (!(*lst_top) || !((*lst_top)->up))
		return (0);
	tmp = (*lst_top)->up;
	(*lst_top)->up = (*lst_top)->down;
	((*lst_top)->down)->up = tmp;
	(*lst_top)->down = (*lst_top)->down->down;
	(*lst_top)->down->down = *lst_top;
	*lst_top = (*lst_top)->up;
	return (0);
}

/*Apply the precedent swap opperation (ft_circlst_swap) to the
 2 given lists*/
int	ft_circlst_swap2(t_lstcirc **lst_top_1, t_lstcirc **lst_top_2)
{
	int	i;

	i = 0;
	i += ft_circlst_swap(lst_top_1);
	i += ft_circlst_swap(lst_top_2);
	return (i);
}
