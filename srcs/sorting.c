/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:19:42 by acardona          #+#    #+#             */
/*   Updated: 2022/12/27 19:48:02 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Pivot made in la;
separate the len first elements of la:
(Pivot = median inf =>) push the len/2+len%2  the ones <= pivot toward lb .*/
int	fts_pivot_a(t_lstcirc **la, t_lstcirc **lb, int len, int pivot)
{
	int	cpt_push;
	int	cpt_rot;

	cpt_push = len / 2;
	cpt_rot = 0;
	while (cpt_push > 0)
	{
		if ((*la)->index >= pivot)
		{
			ft_circlst_rotate(la);
			cpt_rot++;
		}
		else
		{
			ft_circlst_push(la, lb);
			cpt_push++;
		}
	}
	while (cpt_rot)
	{
		ft_circlst_rev_rotate(la);
		cpt_rot--;
	}
}

/*Pivot made in lb;
keep len/2+len%2 elem <=pivot dans lb.*/
int	fts_pivot_b(t_lstcirc **la, t_lstcirc **lb, int len, int pivot_a)
{
	int	cpt_push;
	int	cpt_rot;

	cpt_push = len / 2;
	cpt_rot = 0;
	while (cpt_push > 0)
	{
		if ((*lb)->index < pivot)
		{
			ft_circlst_rotate(lb);
			cpt_rot++;
		}
		else
		{
			ft_circlst_push(lb, la);
			cpt_push++;
		}
	}
	while (cpt_rot)
	{
		ft_circlst_rev_rotate(lb);
		cpt_rot--;
	}
}

/*Return 1 if the first n elements of the pile are sorted and 0 if not*/
int	fts_is_sorted(t_lstcirc **lst, int len)
{
	t_lstcirc	*elem;
	int			i;

	if (!lst)
		return (0);
	i = 0;
	elem = *lst;
	if (!(elem->down))
		return (1);
	while (i < len && elem->down != *lst)
	{
		if (elem->index > elem->down->index)
			return (0);
		elem = elem->down;
		i--;
	}
	return (1);
}

/*Sort the top 3 elem of the list, used in la*/
void	fts_sort_trio(t_lstcirc **lst)
{
	
}

/*Sort pile a (smaller at top)*/
void	ft_sort(t_lstcirc **la, t_lstcirc **lb, int len, int pivot_a)
{
	int	remain_b;
	int	pivot_b;

	if (fts_is_sorted(la, len))
		return ;
	if (len <= 3)
	{
		fts_sort_trio(la);
		return ;
	}
	fts_pivot(la, lb, len, pivot_a);
	remain_b = len / 2 + len % 2;
	pivot_b = pivot_a - remain_b / 2;
	pivot_a = pivot_a + (len / 2) / 2 + (len / 2) % 2;
	ft_sort(la, lb, len / 2, pivot_a);
	while (remain_b > 6)
	{
		fts_pivot_b(la, lb, remain_b, pivot_b);
		remain_b = remain_b / 2 + remain_b % 2;
		pivot_b = pivot_b - remain_b / 2;
		pivot_a = pivot_b + (remain_b / 2) / 2 + (remain_b / 2) % 2;
		ft_sort(la, lb, len, pivot_a);
	}
	fts_pivot_b(la, lb, remain_b, pivot_b);
	ft_sort_double_trio(la, lb);
}
