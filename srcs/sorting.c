/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:19:42 by acardona          #+#    #+#             */
/*   Updated: 2022/12/29 01:15:31 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Pivot made in la;
separate the len first elements of la:
(Pivot = median inf =>) push the len/2+len%2  the ones <= pivot toward lb .*/
void	fts_pivot_a(t_piles_state *piles, int len, int pivot)
{
	int	cpt_push;
	int	cpt_rot;

	cpt_push = len / 2;
	cpt_rot = 0;
	while (cpt_push > 0)
	{
		if (((*piles).pa)->index >= pivot)
		{
			ft_piles_add_op(piles, 2);
			cpt_rot++;
		}
		else
		{
			ft_piles_add_op(piles, 0);
			cpt_push++;
		}
	}
	while (cpt_rot)
	{
		ft_piles_add_op(piles, 3);
		cpt_rot--;
	}
}

/*Pivot made in lb;
keep len/2+len%2 elem <=pivot dans lb.*/
void	fts_pivot_b(t_piles_state *piles, int len, int pivot_b)
{
	int	cpt_push;
	int	cpt_rot;

	cpt_push = len / 2;
	cpt_rot = 0;
	while (cpt_push > 0)
	{
		if (((*piles).pb)->index < pivot_b)
		{
			ft_piles_add_op(piles, 6);
			cpt_rot++;
		}
		else
		{
			ft_piles_add_op(piles, 4);
			cpt_push++;
		}
	}
	while (cpt_rot)
	{
		ft_piles_add_op(piles, 7);
		cpt_rot--;
	}
}

/*pile a : Sort the top 3 elem of the pile a*/
void	fts_sort_trio_a(t_piles_state *piles, int len)
{
	t_lstcirc	*lsta;
	int			i_max;

	lsta = piles->pa;
	i_max = (int)(((size_t)lsta->index + lsta->down->index
				+ lsta->down->down->index) / 3) + 1;
	if (!lsta || ft_is_sorted(lsta, len))
		return ;
	if (len == 2)
	{
		if (lsta->index > lsta->down->value)
			ft_piles_add_op(piles, 1);
	}	
	else if (lsta->index == i_max || lsta->down->index == i_max)
	{
		if (lsta->index == i_max)
			ft_piles_add_op(piles, 1);
		ft_piles_add_3_op(piles, 2, 1, 3);
		if (lsta->down->down->index == i_max - 2)
			ft_piles_add_op(piles, 1);
	}
	else
		ft_piles_add_op(piles, 1);
}

/*pile b: send the 3 sorted elem to a (method optimised to created colisions)*/
void	fts_sort_trio_b(t_piles_state *piles, int len)
{
	int			i_max;

	i_max = (int)(((size_t)piles->pb->index + piles->pb->down->index
				+ piles->pb->down->down->index) / 3) + 1;
	if (len == 2)
	{
		ft_piles_add_3_op(piles, 0, 0, -1);
		if (piles->pb->index > piles->pb->down->index)
			ft_piles_add_op(piles, 1);
		return ;
	}
	if (piles->pb->down->down->index == i_max - 2 || piles->pb->index == i_max)
	{
		if (piles->pb->index == i_max - 1)
			ft_piles_add_op(piles, 5);
		ft_piles_add_3_op(piles, 0, 0, 0);
		if (piles->pb->down->index == i_max - 2)
			ft_piles_add_op(piles, 1);
	}
	else if (piles->pb->down->down->index == i_max)
	{
		ft_piles_add_3_op(piles, 6, 5, 0);
		if (piles->pb->index == i_max - 2)
			ft_piles_add_3_op(piles, 0, 7, 0);
		else
			ft_piles_add_3_op(piles, 7, 7, 0);
	}
	else
	{
		ft_piles_add_3_op(piles, 5, 0, 5);
		ft_piles_add_3_op(piles, 0, 0, -1);
	}
}

/*Sort the top 3 elem of the 2 piles*/
void	fts_sort_doubletrio(t_piles_state *piles, int lentot)
{
	int	lena;
	int	lenb;

	lena = lentot / 2 + lentot % 2;
	lenb = lentot / 2;
	fts_sort_trio_a(piles, lena);
	fts_sort_trio_b(piles, lenb);
}

/*Sort pile a (smaller at top)*/
void	ft_sort(t_piles_state *piles, int len, int pivot_a)
{
	int	remain_b;
	int	pivot_b;

	if (ft_is_sorted((*piles).pa, len))
		return ;
	if (len <= 3)
	{
		//fts_sort_trio(la);
		return ;
	}
	fts_pivot_a(piles, len, pivot_a);
	remain_b = len / 2 + len % 2;
	pivot_b = pivot_a - remain_b / 2;
	pivot_a = pivot_a + (len / 2) / 2 + (len / 2) % 2;
	ft_sort(piles, len / 2, pivot_a);
	while (remain_b > 6)
	{
		fts_pivot_b(piles, remain_b, pivot_b);
		remain_b = remain_b / 2 + remain_b % 2;
		pivot_b = pivot_b - remain_b / 2;
		pivot_a = pivot_b + (remain_b / 2) / 2 + (remain_b / 2) % 2;
		ft_sort(piles, len, pivot_a);
	}
	fts_pivot_b(piles, remain_b, pivot_b);
//	ft_sort_double_trio(piles, remain_b);
}
