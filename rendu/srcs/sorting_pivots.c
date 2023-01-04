/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_pivots.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:59:24 by acardona          #+#    #+#             */
/*   Updated: 2023/01/04 22:00:31 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	fts_conditional_rot(t_piles_state *pil, char lst_name, int *cpt_rot)
{
	t_lstcirc	*lst;
	int			op_rr;

	op_rr = 7;
	lst = pil->pb;
	if (lst_name == 'a')
	{
		op_rr = 3;
		lst = pil->pa;
	}
	if (*cpt_rot <= ft_circlst_len(lst) / 2)
	{
		ft_piles_add_op(pil, op_rr);
		(*cpt_rot)--;
	}
	else
	{
		ft_piles_add_op(pil, op_rr - 1);
		(*cpt_rot)++;
	}
}

/*Pivot made in la; send the len/2 + len%2 smallest elem of la to lb*/
void	ft_pivot_a(t_piles_state *pil, int len, int piv)
{
	int	cpt_push;
	int	cpt_rot;

	cpt_push = len / 2 + len % 2;
	cpt_rot = 0;
	while (cpt_push > 0)
	{
		if (pil->pa->index > piv)
		{
			ft_piles_add_op(pil, 2);
			cpt_rot++;
		}
		else
		{
			ft_piles_add_op(pil, 4);
			if (pil->init == 2 && pil->pb->index <= piv - (len - len / 2) / 2)
				ft_piles_add_op(pil, 6);
			cpt_push--;
		}
	}
	while (!(pil->init) && cpt_rot > 0 && cpt_rot <= ft_circlst_len(pil->pa))
		fts_conditional_rot(pil, 'a', &cpt_rot);
	if (pil->init == 2)
		pil->init--;
}

/*Pivot made in lb; keep len/2+len%2 elem <=pivot dans lb.*/
void	ft_pivot_b(t_piles_state *piles, int len, int pivot_b)
{
	int	cpt_push;
	int	cpt_rot;

	piles->init = 0;
	cpt_push = len / 2;
	cpt_rot = 0;
	while (cpt_push > 0)
	{
		if (((*piles).pb)->index <= pivot_b)
		{
			ft_piles_add_op(piles, 6);
			cpt_rot++;
		}
		else
		{
			ft_piles_add_op(piles, 0);
			cpt_push--;
		}
	}
	while (cpt_rot && cpt_rot <= ft_circlst_len(piles->pb))
		fts_conditional_rot(piles, 'b', &cpt_rot);
}
