/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_op_optimisation_bis.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 23:43:37 by acardona          #+#    #+#             */
/*   Updated: 2023/01/02 21:41:58 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Sub of ft_piles_delete_consecutive_op_one:
 Detect if the given operation is cancelled by the next one.*/
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

/* "clean" the given list of operation removing the cancelling paires*/
void	ft_piles_delete_consecutive_op_one(t_lstcirc **oplst)
{
	t_lstcirc	*elem;
	t_lstcirc	*tmp;

	if (!oplst || !(*oplst) || !((*oplst)->down))
		return ;
	elem = *oplst;
	while (elem && elem->down && elem->down != *oplst)
	{
		if (fts_piles_op_canceled(elem))
		{
			//printf("a suppr : %d et %d\n", elem->value,elem->down->value);//
			if (elem == *oplst)
			{
				ft_cirlst_rm1(oplst);
				ft_cirlst_rm1(oplst);
				elem = *oplst;
			}
			else
			{
				elem = elem->up;
				elem->down->down->down->up = elem;
				tmp = elem->down;
				elem->down = elem->down->down->down;
				free(tmp->down);
				free(tmp);
				if (elem->up == elem)
				{
					elem->up = 0;
					elem->down = 0;
				}
			}
		}
		else
			elem = elem->down;
	}
}

/* "clean" the all 3 lists of operation of piles removing the
 cancelling paires*/
void	ft_piles_delete_consecutive_op_all(t_piles_state *piles)
{
	ft_piles_delete_consecutive_op_one(&(piles->opa));
	ft_piles_delete_consecutive_op_one(&(piles->opb));
	ft_piles_delete_consecutive_op_one(&(piles->opall));
}

/*===========*/
/*Sub-function of ft_piles_merge_all_operations :
Calculate the number of operation in the opposite operation list before
 reaching its end or finding the same operation as the one given (ex:
 given sa in list a we look for sb in list b)*/
static int	fts_piles_dist_match(t_piles_state *piles, int op_id)
{
	int			dist;
	t_lstcirc	*elem;

	dist = 0;
	if (op_id < 4)
	{
		elem = piles->opb;
		while (elem && elem->down != piles->opb && elem->value != op_id + 4)
		{
			elem = elem->down;
			dist++;
		}
	}
	else if (op_id < 8)
	{
		elem = piles->opa;
		while (elem && elem->down != piles->opa && elem->value != op_id - 4)
		{
			elem = elem->down;
			dist++;
		}
	}
	else
		return (printf("Erreur : Calcul de dist dans un cas inapproprie.\n"));
	return (dist);
}

/*Activated when a push operation is orderd or at the end
 of the program -> execute all the operation trying to have as mutch
 matchs as possible.*/
void	ft_piles_merge_all_operations(t_piles_state *piles)
{
	int	len_match_a;
	int	len_match_b;
	// ft_circlst_printduo("\n\nAvant merge:\nopa et opb", &(piles->opa), &(piles->opb));//
	// ft_circlst_printduo("opall", &(piles->opall), 0);//
	ft_piles_delete_consecutive_op_all(piles);
	while (piles->opa && piles->opb)
	{
		// ft_circlst_printduo ("\e[0mMERGE\nopa et opb :", &piles->opa, &piles->opb);//
		// ft_circlst_printduo ("opall :", &piles->opall, 0);//
		if (piles->opa->value + 4 == piles->opb->value)
		{
			// ft_printf("boucle1\n");
			ft_piles_add_op_to(piles, &(piles->opall), piles->opb->value + 3);
			// ft_printf("arrive ici :\n\tFirst opa = %d\n\tFirst opb = %d\n", piles->opa->value, piles->opb->value);//
			ft_cirlst_rm1(&(piles->opa));
			ft_cirlst_rm1(&(piles->opb));
		}
		else
		{
			// ft_printf("boucle2\n");
			len_match_a = fts_piles_dist_match(piles, piles->opa->value);
			len_match_b = fts_piles_dist_match(piles, piles->opb->value);
			if (len_match_a > len_match_b)
				ft_piles_push_bottom(&(piles->opa), &(piles->opall));
			else
				ft_piles_push_bottom(&(piles->opb), &(piles->opall));
		}
		// sleep(1);//
	}
	// ft_printf("Sortie de boucle\n");
	// ft_circlst_printduo("Merge :", &(piles->opa), &(piles->opall));//
	while (piles->opa)
		ft_piles_push_bottom(&(piles->opa), &(piles->opall));
	while (piles->opb)
		ft_piles_push_bottom(&(piles->opb), &(piles->opall));
}
