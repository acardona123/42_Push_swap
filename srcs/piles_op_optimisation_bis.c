/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_op_optimisation_bis.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 23:43:37 by acardona          #+#    #+#             */
/*   Updated: 2022/12/29 21:02:33 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Sub-function.
Calculate the number of operation in the opposite operation list before
 reaching its end or finding the same operation as the one given (ex:
  given sa we look for sb)*/
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

/*Move the first elem of src to the top of dest*/
static void	fts_piles_move(t_lstcirc **lsrc, t_lstcirc **ldest)
{
	ft_circlst_push(ldest, lsrc, 0);
	ft_circlst_rotate(ldest, 0);
}

/* Normalement inutile
verifie qu'il n'y a pas de ra rra ou rra ra ou ... a la suite dans les piles
 d'op et les supprime le casecheant.
static void	fts_piles_delete_consecutive(t_piles_state *piles)
{
	if (piles->opa && piles->opa->next && piles->opa->op == 2
		&& piles->opa->next->op == 3)
	{
		fts_piles_rm_op(piles, 2);
		fts_piles_rm_op(piles, 3);
	}
	else if (piles->opa && piles->opa->next && piles->opa->op == 3
		&& piles->opa->next->op == 2)
	{
		fts_piles_rm_op(piles, 3);
		fts_piles_rm_op(piles, 2);
	}
	else if (piles->opb && piles->opb->next && piles->opb->op == 2
		&& piles->opb->next->op == 3)
	{
		fts_piles_rm_op(piles, 2);
		fts_piles_rm_op(piles, 3);
	}
	else if (piles->opb && piles->opb->next && piles->opb->op == 3
		&& piles->opb->next->op == 2)
	{
		fts_piles_rm_op(piles, 3);
		fts_piles_rm_op(piles, 2);
	}
}
*/

/*Activated when a push operation is orderd or at the end
 of the program -> execute all the operation trying to have as mutch
 matchs as possible.*/
void	ft_piles_merge_all_operations(t_piles_state *piles)
{
	int	len_match_a;
	int	len_match_b;
	// ft_circlst_printduo("\n\nAvant merge:\nopa et opb", &(piles->opa), &(piles->opb));//
	// ft_circlst_printduo("opall", &(piles->opall), 0);//
	while (piles->opa && piles->opb)
	{
		if (piles->opa->value + 4 == piles->opb->value)
		{
			ft_piles_add_op_to(piles, &(piles->opall), piles->opb->value + 3);
			ft_cirlst_rm1(&(piles->opa));
			ft_cirlst_rm1(&(piles->opb));
		}
		else
		{
			len_match_a = fts_piles_dist_match(piles, piles->opa->value);
			len_match_b = fts_piles_dist_match(piles, piles->opb->value);
			if (len_match_a > len_match_b)
				fts_piles_move(&(piles->opa), &(piles->opall));
			else
				fts_piles_move(&(piles->opb), &(piles->opall));
		}
	}
	// ft_circlst_printduo("Merge :", &(piles->opa), &(piles->opall));//
	while (piles->opa)
		fts_piles_move(&(piles->opa), &(piles->opall));
	while (piles->opb)
		fts_piles_move(&(piles->opb), &(piles->opall));
}
