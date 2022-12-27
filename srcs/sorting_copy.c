/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:19:42 by acardona          #+#    #+#             */
/*   Updated: 2022/12/26 17:48:27 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Sort a pile l1 of 3 consecutive integers*/
static void	fts_pile_sort_trio(t_lstcirc **l)
{
	int	max;

	max = (int)(((long long int)((*l)->index) + (*l)->up->index
				+ (*l)->down->index) / 3 + 1);
	if (!l || !(*l))
		return ;
	if ((*l)->index == max)
	{
		ft_circlst_rotate(l);
		write (1, "1\n", 2);
	}
	if ((*l)->down->index == max)
	{
		ft_circlst_rev_rotate(l);
		write (1, "1\n", 2);
	}
	if ((*l)->value == max - 1)
	{
		ft_circlst_swap(l);
		write (1, "1\n", 2);
	}
}

/*Sorts the given using a second one as a buffer (quicksort methode)*/
void	ft_pile_sort(t_lstcirc **l_a, t_lstcirc **l_b, int pivot)
{
	int	len;
	int	cpt; //compte le nb d'elements superierus deja transferes vers b, evite de regarder encore si ils ont tous etes trouves.
	int nb_sup_next;

	len = ft_circlst_len(*l_a);
	// tri dans le cas ou il n'y a qu'un ou deux elements a comparer
	if (len < 3) 
	{
		//ft_printf("\e[0;101m\n");//rouge
		if ((*l_a)->down && ((*l_a)->down)->index < (*l_a)->index)
		{
			ft_circlst_swap(l_a);
			write (1, "1\n", 2);
			//ft_circlst_printduo("sa", l_a, l_b);
		}
		ft_circlst_push(l_b, l_a);
		write (1, "1\n", 2);
		//ft_circlst_printduo("pb", l_a, l_b);
		ft_circlst_rotate(l_b);
		write (1, "1\n", 2);
		//ft_circlst_printduo("rb", l_a, l_b);
		if (*l_a)
		{
			ft_circlst_push(l_b, l_a);
			write (1, "1\n", 2);
		//ft_circlst_printduo("pb", l_a, l_b);
			ft_circlst_rotate(l_b);
			write (1, "1\n", 2);
			//ft_circlst_printduo("rb", l_a, l_b);
		}
		return ;
	}
	if (len == 3)
		return (fts_pile_sort_trio(l_b));
	//passage des elements > pivot vers l_b
	nb_sup_next = len / 2 + len % 2;
	//ft_printf("\e[2;102mPivot : %d\e[0;102m\n", pivot);//vert
	//ft_circlst_printduo("Etat avant pivot :", l_a, l_b);
	cpt = 0;
	while (cpt < nb_sup_next)
	{
		//ft_printf("cpt : %d, nb_sup_next : %d\n", cpt, nb_sup_next);
		if ((*l_a)->index >= pivot)
		{
			ft_circlst_push(l_b, l_a);
			write (1, "1\n", 2);
			//ft_circlst_printduo("pb", l_a, l_b);
			cpt ++;
		}
		else
		{
			ft_circlst_rotate(l_a);
			write (1, "1\n", 2);
			//ft_circlst_printduo("ra", l_a, l_b);
		}
	}
	//ft_printf("\e[0m\n\n");

	//trie par recusion de la liste dt les elem sont < pivot. Ca envoie la liste triee en dessous de l_b. A la fin l_a vide
	len = ft_circlst_len(*l_a);
	ft_pile_sort(l_a, l_b, pivot - len / 2 - len % 2);

	//Recuperation des elem > pivot depuis l_b et meme tri par recursion
	//ft_printf("\e[0;103m\n");//kaki
	if (nb_sup_next > 0)
	{
		while (nb_sup_next > 0)
		{
			ft_circlst_push(l_a, l_b);
			write (1, "1\n", 2);
			//ft_circlst_printduo("pa", l_a, l_b);
			nb_sup_next--;
		}
		len = ft_circlst_len(*l_a);
		ft_pile_sort(l_a, l_b, pivot + len / 2);
	}
	//ft_printf("\e[0m\n");
}



void	ft_pile_sort(t_lstcirc **l_a, t_lstcirc **l_b, int pivot, int len)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (i < len / 2) //on envoie les 	
}