/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:19:42 by acardona          #+#    #+#             */
/*   Updated: 2023/01/10 17:38:12 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*pile a : Sort the top 3 elem of the pile a*/
static void	fts_sort_trio_a(t_piles_state *piles, int len)
{
	int			i_max;

	if (!piles->pa || ft_is_sorted(piles->pa, len))
		return ;
	if (len == 2)
	{
		if (piles->pa->index > piles->pa->down->index)
			ft_piles_add_op(piles, 1);
		return ;
	}	
	i_max = (int)(((size_t)piles->pa->index + piles->pa->down->index
				+ piles->pa->down->down->index) / 3) + 1;
	if (piles->pa->index == i_max || piles->pa->down->index == i_max)
	{
		if (piles->pa->index == i_max)
			ft_piles_add_op(piles, 1);
		ft_piles_add_3_op(piles, 2, 1, 3);
		if (!ft_is_sorted(piles->pa, 3))
			ft_piles_add_op(piles, 1);
	}
	else
		ft_piles_add_op(piles, 1);
}

static void	fts_sub_sort_trio_b(t_piles_state *piles, int i_max, int case_index)
{
	if (case_index == 1)
	{
		if (piles->pb->index == i_max - 1)
			ft_piles_add_op(piles, 5);
		ft_piles_add_3_op(piles, 0, 0, 0);
		if (piles->pa->index != i_max - 2)
			ft_piles_add_op(piles, 1);
	}
	else
	{
		ft_piles_add_3_op(piles, 6, 5, 0);
		if (piles->pb->index == i_max - 1)
			ft_piles_add_3_op(piles, 0, 7, 0);
		else
			ft_piles_add_3_op(piles, 7, 0, 0);
	}
}

/*pile b: send the 3 sorted elem to a (method optimised to created colisions)*/
void	fts_sort_trio_b(t_piles_state *piles, int len)
{
	int			i_max;

	if (len == 2)
	{
		ft_piles_add_3_op(piles, 0, 0, -1);
		if (piles->pa->index > piles->pa->down->index)
			ft_piles_add_op(piles, 1);
		return ;
	}
	i_max = (int)(((size_t)piles->pb->index + piles->pb->down->index
				+ piles->pb->down->down->index) / 3) + 1;
	if (piles->pb->down->down->index == i_max - 2 || piles->pb->index == i_max)
		fts_sub_sort_trio_b(piles, i_max, 1);
	else if (piles->pb->down->down->index == i_max)
		fts_sub_sort_trio_b(piles, i_max, 2);
	else
	{
		ft_piles_add_3_op(piles, 5, 0, 5);
		ft_piles_add_3_op(piles, 0, 0, -1);
	}
}

/*Sort pile a (smaller at top)*/
void	ft_sort(t_piles_state *piles, int len_a, int pivot_a)
{
	int	remain_b;
	int	pivot_b;

	if (ft_is_sorted(piles->pa, len_a))
		return ;
	if (len_a <= 3)
		return (fts_sort_trio_a(piles, len_a));
	ft_pivot_a(piles, len_a, pivot_a);
	remain_b = len_a / 2 + len_a % 2;
	len_a = len_a / 2;
	pivot_b = pivot_a - remain_b / 2;
	pivot_a = pivot_a + len_a / 2 + len_a % 2;
	ft_sort(piles, len_a, pivot_a);
	while (remain_b > 3)
	{
		ft_pivot_b(piles, remain_b, pivot_b);
		len_a = remain_b / 2;
		remain_b = remain_b / 2 + remain_b % 2;
		pivot_a = pivot_b + len_a / 2 + len_a % 2;
		pivot_b = pivot_b - remain_b / 2;
		ft_sort(piles, len_a, pivot_a);
	}
	fts_sort_trio_b(piles, remain_b);
}

void	ft_sort_lst3(t_piles_state *piles)
{
	if (ft_circlst_len(piles->pa) == 2 && piles->pa->value != 1)
		ft_piles_add_op(piles, 1);
	else
	{
		if (piles->pa->index == 1 && piles->pa->down->index == 3)
			ft_piles_add_3_op(piles, 3, 1, -1);
		else if (piles->pa->index == 3 && piles->pa->down->index == 1)
			ft_piles_add_op(piles, 2);
		else if (piles->pa->index == 3 && piles->pa->down->index == 2)
			ft_piles_add_3_op(piles, 2, 1, -1);
		else if (piles->pa->index == 2 && piles->pa->down->index == 1)
			ft_piles_add_op(piles, 1);
		else if (piles->pa->index == 2 && piles->pa->down->index == 3)
			ft_piles_add_op(piles, 3);
	}
}
