/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circlst_building.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:23:39 by acardona          #+#    #+#             */
/*   Updated: 2023/01/10 18:43:50 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_lstcirc	*ft_circlst_new_elem(int nb, unsigned int index)
{
	t_lstcirc	*elem;

	elem = malloc(sizeof(t_lstcirc));
	if (!elem)
		return (0);
	elem->value = nb;
	elem->index = index;
	elem->up = 0;
	elem->down = 0;
	return (elem);
}

/*Add new element above the origine (origin unchanged): origin=top->new=bottom*/
int	ft_circlst_addabove(t_lstcirc **lst_origin, t_lstcirc *new_elem)
{
	new_elem->up = 0;
	new_elem->down = 0;
	if (!lst_origin)
		return (1);
	if (!(*lst_origin))
	{
		*lst_origin = new_elem;
		return (0);
	}
	new_elem->down = *lst_origin;
	if (!((*lst_origin)->up))
	{
		new_elem->up = *lst_origin;
		(*lst_origin)->down = new_elem;
	}
	else
	{
		new_elem->up = (*lst_origin)->up;
		(*lst_origin)->up->down = new_elem;
	}
	(*lst_origin)->up = new_elem;
	return (0);
}

/*new_elem add to lst and become the new top of the list*/
int	ft_circlst_addtop(t_lstcirc **lst_top, t_lstcirc *new_elem)
{
	if (!lst_top || ft_circlst_addabove(lst_top, new_elem))
		return (1);
	if ((*lst_top)->up)
		*lst_top = (*lst_top)->up;
	return (0);
}

/*Free he given list*/
int	ft_circlst_free(t_lstcirc **lst)
{
	t_lstcirc	*tmp;

	if (lst && *lst)
	{
		if (!((*lst)->up))
		{
			free(*lst);
			return (0);
		}
		tmp = (*lst)->up;
		(*lst)->up = 0;
		*lst = tmp;
		while (*lst)
		{
			tmp = (*lst)->up;
			free(*lst);
			(*lst) = tmp;
		}
	}
	return (0);
}

/*Remove the top element of the list*/
int	ft_cirlst_rm1(t_lstcirc **lst)
{
	t_lstcirc	*tmp;

	tmp = *lst;
	if ((*lst)->up)
	{
		if ((*lst)->down->down == *lst)
		{
			(*lst)->down->down = 0;
			(*lst)->down->up = 0;
		}
		else
		{
			(*lst)->up->down = (*lst)->down;
			(*lst)->down->up = (*lst)->up;
		}
		*lst = (*lst)->down;
		free(tmp);
	}
	else
	{
		free(*lst);
		*lst = 0;
	}
	return (0);
}
