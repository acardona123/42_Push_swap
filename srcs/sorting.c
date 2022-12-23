/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:19:42 by acardona          #+#    #+#             */
/*   Updated: 2022/12/23 21:04:43 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Sorts the given using a second one as a buffer (quicksort methode)*/
void	ft_pile_sort(t_lstcirc **l_a, t_lstcirc **l_b, int pivot, int nb_sup)
{
	int	len;
	int	cpt; //compte le nb d'elements superierus deja transferes vers b, evite de regarder encore si ils ont tous etes trouves.
	int	nb_sup; // nb d'elements au sperieurs au pivot, deplaces vers b.

	// tri dans le cas ou il n'y a qu'un ou deux elements a comparer
	if (ft_circlst_len(*l_a) < 3) 
	{
		ft_circlst_push(l_b, l_a);
		printf("pb\n");
		if (*l_a && ((*l_b)->index) > ((*l_a)-> index))
		{
			ft_circlst_push(l_b, l_a);
			ft_circlst_rotate(l_b);
			printf("pb\nrb\n");
		}
		else if (*l_a)
		{
			ft_circlst_rotate(l_b);
			ft_circlst_push(l_b, l_a);
			printf("rb\npb\n");
		}
		ft_circlst_rotate(l_b);
		printf("rb\n");
		return ;
	}

	//passage des elements > pivot vers l_b
	len = ft_circlst_len(l_a);
	nb_sup = len / 2 + len % 2;
	cpt = 0;
	while (cpt < nb_sup)
	{
		if ((*l_a)->index >= pivot)
		{
			ft_circlst_push(l_b, l_a);
			intf("pb\n");
		}
		else
		{
			ft_circlst_rotate(l_a);
			printf("ra\n");
		}
	}

	//trie par recusion de la liste dt es elem sont < pivot. Ca envoie la liste triee en dessous de l_b. A la fin l_a vide
	ft_pile_sort(l_a, l_b, pivot - len / 2 + 1, len / 2);

	//Recuperation des elem > pivot depuis l_b et meme tri par recursion
	while (nb_sup > 0)
	{
		ft_circlst_push(l_a, l_b);
		printf("pa\n");
		nb_sup--;
	}
	ft_pile_sort(l_a, l_b, pivot + len / 2, 0);
}
