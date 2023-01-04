/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_op_optimisation_bis.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 23:43:37 by acardona          #+#    #+#             */
/*   Updated: 2023/01/04 21:48:48 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Sub ft_piles_delete_consecutive... : Detect if op cancelled by the next one.*/
static int	fts_piles_op_canceled(t_lstcirc *lst_elem)
{
	int	v0;
	int	v1;

	v0 = lst_elem->value;
	v1 = lst_elem->down->value;
	if ((v0 == 2 && v1 == 3) || (v0 == 3 && v1 == 2) || (v0 == 0 && v1 == 4)
		|| (v0 == 4 && v1 == 0) || (v0 == 1 && v1 == 1) || (v0 == 5 && v1 == 5)
		|| (v0 == 6 && v1 == 7) || (v0 == 7 && v1 == 6))
		return (1);
	return (0);
}

/*sub-function of ft_piles_delete_consecutive_op_one (for the norm)*/
static void	fts_sub_delete_cons_op_one(t_lstcirc **oplst, t_lstcirc	**elem)
{
	t_lstcirc	*tmp;

	if (fts_piles_op_canceled((*elem)) && (*elem) == *oplst)
	{
		ft_cirlst_rm1(oplst);
		ft_cirlst_rm1(oplst);
		(*elem) = *oplst;
	}
	else if (fts_piles_op_canceled((*elem)))
	{
		(*elem) = (*elem)->up;
		(*elem)->down->down->down->up = (*elem);
		tmp = (*elem)->down;
		(*elem)->down = (*elem)->down->down->down;
		free(tmp->down);
		free(tmp);
		if ((*elem)->up == (*elem))
		{
			(*elem)->up = 0;
			(*elem)->down = 0;
		}
	}
	else
		(*elem) = (*elem)->down;
}

/* "clean" the given list of operation removing the cancelling paires*/
void	ft_piles_delete_consecutive_op_one(t_lstcirc **oplst)
{
	t_lstcirc	*elem;

	if (!oplst || !(*oplst) || !((*oplst)->down))
		return ;
	elem = *oplst;
	while (elem && elem->down && elem->down != *oplst)
		fts_sub_delete_cons_op_one(oplst, &elem);
}

/* "clean" the all 3 lists of op removing the  cancelling paires*/
void	ft_piles_delete_consecutive_op_all(t_piles_state *piles)
{
	ft_piles_delete_consecutive_op_one(&(piles->opa));
	ft_piles_delete_consecutive_op_one(&(piles->opb));
	ft_piles_delete_consecutive_op_one(&(piles->opall));
}
