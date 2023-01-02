/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:19:42 by acardona          #+#    #+#             */
/*   Updated: 2023/01/02 19:16:03 by acardona         ###   ########.fr       */
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

	cpt_push = len / 2;
	cpt_rot = 0;
	// printf("\e[32m====\nPIVOT A :\n");//
	// printf("Pivot : %d , cpt_push = %d\n", pivot, cpt_push);//
	// ft_circlst_printduo("  Avant pivot :", &(piles->pa), &(piles->pb));//
	while (cpt_push > 0)
	{
		// ft_printf("Boucle 1 :");
		if ((piles->pa)->index >= pivot)
		{
			// ft_circlst_printduo("ra", &(piles->pa), &(piles->pb));
			ft_piles_add_op(piles, 2);
			cpt_rot++;
		}
		else
		{
			// ft_circlst_printduo("pb", &(piles->pa), &(piles->pb));
			ft_piles_add_op(piles, 4);
			cpt_push--;
		}
		// usleep(50000);//
	}
	while (!(piles->init) && cpt_rot > 0)
	{
		ft_piles_add_op(piles, 3);
		cpt_rot--;
		// sleep(1);//
	}
	// ft_circlst_printduo("  Apres pivot :", &(piles->pa), &(piles->pb));//
	// printf("====\e[0m\n");//
}

/*Pivot made in lb;
keep len/2+len%2 elem <=pivot dans lb.*/
void	fts_pivot_b(t_piles_state *piles, int len, int pivot_b)
{
	int	cpt_push;
	int	cpt_rot;

	piles->init = 0;
	// printf("\e[34m====\nPIVOT B :\n");//
	cpt_push = len / 2 + len % 2;
	cpt_rot = 0;
	//printf("Pivot : %d\nlen : len", pivot_b);//
	//ft_circlst_printduo("  Avant pivot :", &(piles->pa), &(piles->pb));//
	while (cpt_push > 0)
	{
		//printf("boucle, cpt_push = %d\n", cpt_push);
		if ((piles->pb)->index < pivot_b)
		{
			ft_piles_add_op(piles, 6);
			cpt_rot++;
		}
		else
		{
			ft_piles_add_op(piles, 0);
			cpt_push--;
		}
		//usleep(50000);//
	}
	while (cpt_rot)
	{
		ft_piles_add_op(piles, 7);
		cpt_rot--;
		//sleep(1);//
	}
	//ft_circlst_printduo("  Apres pivot :", &(piles->pa), &(piles->pb));//
	//printf("====\e[0m\n");//
}

/*pile a : Sort the top 3 elem of the pile a*/
void	fts_sort_trio_a(t_piles_state *piles, int len)
{
	int			i_max;

	//printf("\e[47m====\nfts_sort_trio_a :\nlen = %d\n", len);//
	if (!piles->pa || ft_is_sorted(piles->pa, len))
		return ;
	if (len == 2)
	{
		if (piles->pa->index > piles->pa->down->index)
			ft_piles_add_op(piles, 1);
		//printf("Simple duo\n");
		//ft_circlst_printduo("Apres tri trio a :", &(piles->pa), &(piles->pb));//
		//printf("====\e[0m\n");//
		return ;
	}	
	i_max = (int)(((size_t)piles->pa->index + piles->pa->down->index
				+ piles->pa->down->down->index) / 3) + 1;
	//printf("imax = %d\n", i_max);
	//ft_circlst_printduo("Avant tri trio a :", &(piles->pa), &(piles->pb));
	if (piles->pa->index == i_max || piles->pa->down->index == i_max)
	{
		if (piles->pa->index == i_max)
			ft_piles_add_op(piles, 1);
		//ft_circlst_printduo("Pendant trio 1 :", &(piles->pa), &(piles->pb));
		ft_piles_add_3_op(piles, 2, 1, 3);
		//ft_circlst_printduo("Pendant trio 2 :", &(piles->pa), &(piles->pb));
		if (!ft_is_sorted(piles->pa, 3))
		{
			// ft_printf("piles->pa->index = %d  et i_max - 2 = %d\n", piles->pa->index,  i_max - 2);
			ft_piles_add_op(piles, 1);
		}
			
	}
	else
		ft_piles_add_op(piles, 1);
	//ft_circlst_printduo("Apres tri trio a :", &(piles->pa), &(piles->pb));
	//printf("====\e[0m\n");//
	//sleep(3);//
}

/*pile b: send the 3 sorted elem to a (method optimised to created colisions)*/
void	fts_sort_trio_b(t_piles_state *piles, int len)
{
	int			i_max;

	//ft_printf("\e[1;35m====\nfts_sort_trio_b :\nlen = %d\n", len);//
	//ft_circlst_printduo("Avant tri trio b :", &(piles->pa), &(piles->pb));//
	if (len == 2)
	{
		ft_piles_add_3_op(piles, 0, 0, -1);
		if (piles->pa->index > piles->pa->down->index)
			ft_piles_add_op(piles, 1);
		//ft_circlst_printduo("Apres tri trio b :", &(piles->pa), &(piles->pb));//
		//printf("====\e[0m\n");//
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
			ft_piles_add_3_op(piles, 7, 0, 0);
	}
	else
	{
		ft_piles_add_3_op(piles, 5, 0, 5);
		ft_piles_add_3_op(piles, 0, 0, -1);
	}
	//ft_circlst_printduo("Apres tri trio b :", &(piles->pa), &(piles->pb));//
	//printf("====\e[0m\n");//
	//sleep(1);//
}

/*Sort the top 3 elem of the 2 piles*/
void	fts_sort_doubletrio(t_piles_state *piles, int lentot)
{
	int	lena;
	int	lenb;

	lena = lentot / 2;
	lenb = lentot / 2 + lentot % 2;
	fts_sort_trio_a(piles, lena);
	fts_sort_trio_b(piles, lenb);
}

/*Sort pile a (smaller at top)*/
void	ft_sort(t_piles_state *piles, int len_a, int pivot_a)
{
	int	remain_b;
	int	pivot_b;

	//ft_circlst_printduo("\n~~~~\nNouveau tri :", &(piles->pa), &(piles->pb));
	//ft_printf("len_a = %d   et   pivot_a = %d\n", len_a, pivot_a);
	//sleep(2);
	if (ft_is_sorted(piles->pa, len_a))
		return ;
	if (len_a <= 3)
	{
		fts_sort_trio_a(piles, len_a);
		return ;
	}
	fts_pivot_a(piles, len_a, pivot_a);
	remain_b = len_a / 2;
	len_a = len_a / 2 + len_a % 2;
	pivot_b = pivot_a - remain_b / 2 - remain_b % 2;
	pivot_a = pivot_a + len_a / 2;
	
	//sleep(2);
	ft_sort(piles, len_a, pivot_a);
	//printf("\n~~~Fin du sort intermediaire, on va sort les parties envoyees dans b.\n");//
	//sleep(2);//
	while (remain_b > 3)
	{
		//sleep(1);//
		fts_pivot_b(piles, remain_b, pivot_b);
		len_a = remain_b / 2 + remain_b % 2;
		remain_b = remain_b / 2;
		pivot_a = pivot_b + len_a / 2;
		pivot_b = pivot_b - remain_b / 2 - remain_b % 2;
		ft_sort(piles, len_a, pivot_a);
	}
	//printf("\n~~~Fin du sort des sous parties stockees dans b\n");//
	//sleep(2);//
	fts_sort_trio_b(piles, remain_b);
	//sleep(2);//
}
