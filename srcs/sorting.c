/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:19:42 by acardona          #+#    #+#             */
/*   Updated: 2022/12/29 21:05:20 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Pivot made in la;
separate the len first elements of la:
(Pivot = median inf =>) push the len/2+len%2  elem <= pivot toward lb .*/
void	fts_pivot_a(t_piles_state *piles, int len, int pivot)
{
	int	cpt_push;
	int	cpt_rot;

	// printf("\e[32m====\nPIVOT A :\n");//
	cpt_push = len / 2;
	cpt_rot = 0;
	while (cpt_push > 0)
	{
		// printf("Pivot : %d\n   Index 1er : %d\n", pivot, ((*piles).pa)->index);//
		if (((*piles).pa)->index > pivot)
		{
			ft_piles_do_one_operation(piles, 2);
			cpt_rot++;
		}
		else
		{
			ft_piles_do_one_operation(piles, 4);
			cpt_push--;
		}
		// ft_circlst_printduo("Situation initiale :", &((*piles).pa), &((*piles).pb));//
		//sleep(1);//
	}
	while (cpt_rot > 0)
	{
		ft_piles_add_op(piles, 3);
		cpt_rot--;
		//sleep(1);//
	}
	// printf("====\e[0m\n");//
}

/*Pivot made in lb;
keep len/2+len%2 elem <=pivot dans lb.*/
void	fts_pivot_b(t_piles_state *piles, int len, int pivot_b)
{
	int	cpt_push;
	int	cpt_rot;

	// printf("\e[34m====\nPIVOT B :\n");//
	cpt_push = len / 2;
	cpt_rot = 0;
	while (cpt_push > 0)
	{
		// printf("Pivot : %d\n   Index 1er : %d\n", pivot_b, ((*piles).pb)->index);//
		if (((*piles).pb)->index <= pivot_b)
		{
			ft_piles_do_one_operation(piles, 6);
			cpt_rot++;
		}
		else
		{
			ft_piles_do_one_operation(piles, 0);
			cpt_push--;
		}
		// ft_circlst_printduo("Situation initiale :", &((*piles).pa), &((*piles).pb));//
		//sleep(1);//
	}
	while (cpt_rot)
	{
		ft_piles_add_op(piles, 7);
		cpt_rot--;
		//sleep(1);//
	}
	// printf("====\e[0m\n");//
}

/*pile a : Sort the top 3 elem of the pile a*/
void	fts_sort_trio_a(t_piles_state *piles, int len)
{
	t_lstcirc	*lsta;
	int			i_max;

	// printf("\e[33m====\nfts_sort_trio_a :\n");//
	lsta = piles->pa;
	if (!lsta || ft_is_sorted(lsta, len))
		return ;
	if (len == 2)
	{
		if (lsta->index > lsta->down->value)
			ft_piles_add_op(piles, 1);
		return ;
	}	
	i_max = (int)(((size_t)lsta->index + lsta->down->index
				+ lsta->down->down->index) / 3) + 1;
	if (lsta->index == i_max || lsta->down->index == i_max)
	{
		if (lsta->index == i_max)
			ft_piles_add_op(piles, 1);
		ft_piles_add_3_op(piles, 2, 1, 3);
		if (lsta->index != i_max - 2)
			ft_piles_add_op(piles, 1);
	}
	else
		ft_piles_add_op(piles, 1);
	// ft_circlst_printduo("Situation initiale :", &(piles->pa), &(piles->pb));
	// printf("====\e[0m\n");//
	//sleep(1);//
}

/*pile b: send the 3 sorted elem to a (method optimised to created colisions)*/
void	fts_sort_trio_b(t_piles_state *piles, int len)
{
	int			i_max;

	// ft_printf("\e[1;35m====\nfts_sort_trio_b :\n");//
	// ft_circlst_printduo("Situation initiale :", &(piles->pa), &(piles->pb));//
	if (len == 2)
	{
		ft_piles_add_3_op(piles, 0, 0, -1);
		// ft_circlst_printduo("Situation initiale :", &(piles->pa), &(piles->pb));//
		if (piles->pa->index > piles->pa->down->index)
			ft_piles_add_op(piles, 1);
		return ;
	}
	i_max = (int)(((size_t)piles->pb->index + piles->pb->down->index
				+ piles->pb->down->down->index) / 3) + 1;
	if (piles->pb->down->down->index == i_max - 2 || piles->pb->index == i_max)
	{
		if (piles->pb->index == i_max - 1)
			ft_piles_add_op(piles, 5);
		ft_piles_add_3_op(piles, 0, 0, 0);
		if (piles->pa->index != i_max - 2)
			ft_piles_add_op(piles, 1);
	}
	else if (piles->pb->down->down->index == i_max)
	{
		ft_piles_add_3_op(piles, 6, 5, 0);
		if (piles->pb->index == i_max - 1)
			ft_piles_add_3_op(piles, 0, 7, 0);
		else
			ft_piles_add_3_op(piles, 7, 7, 0);
	}
	else
	{
		ft_piles_add_3_op(piles, 5, 0, 5);
		ft_piles_add_3_op(piles, 0, 0, -1);
	}
	// ft_circlst_printduo("Situation initiale :", &(piles->pa), &(piles->pb));
	// printf("====\e[0m\n");//
	//sleep(1);//
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
void	ft_sort(t_piles_state *piles, int len_a, int pivot_a)
{
	int	remain_b;
	int	pivot_b;

	// ft_circlst_printduo("\n~~~~\nNouveau tri :", &(piles->pa), &(piles->pb));
	// ft_printf("len_a = %d   et   pivot_a = %d\n", len_a, pivot_a);
	//sleep(2);
	if (ft_is_sorted(piles->pa, len_a))
		return ;
	if (len_a <= 3)
	{
		fts_sort_trio_a(piles, len_a);
		return ;
	}
	fts_pivot_a(piles, len_a, pivot_a);
	remain_b = len_a / 2 + len_a % 2;
	len_a = len_a / 2;
	pivot_b = pivot_a - remain_b / 2;
	pivot_a = pivot_a + len_a / 2 + len_a % 2;
	
	//sleep(2);
	ft_sort(piles, len_a, pivot_a);
	// printf("\n~~~Fin du sort intermediaire, on va sort les parties envoyees dans b.\n");//
	//sleep(2);//
	while (remain_b > 3)
	{
		// printf("\n\e[0;102mICI\e[0m\n\n");//
		//sleep(1);//
		fts_pivot_b(piles, remain_b, pivot_b);
		len_a = remain_b / 2;
		remain_b = remain_b / 2 + remain_b % 2;
		pivot_a = pivot_b + len_a / 2 + len_a % 2;
		pivot_b = pivot_b - remain_b / 2;
		ft_sort(piles, len_a, pivot_a);
	}
	// printf("\n~~~Fin du sort des sous parties de droite.\n");//
	//sleep(2);//
	fts_sort_trio_b(piles, remain_b);
	// printf("\n~~~Fin du sort du double trio.\n");//
	//sleep(2);//
}
