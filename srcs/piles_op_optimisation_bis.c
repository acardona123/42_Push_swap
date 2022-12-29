/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_op_optimisation_bis.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 23:43:37 by acardona          #+#    #+#             */
/*   Updated: 2022/12/29 00:51:01 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Sub-function :
Remove an operation from the list of operation (/!\ To use only after
 having done the operation)*/
static void	fts_piles_rm_op(t_piles_state *piles, int op_id)
{
	t_pile_op	*temp;

	if (op_id < 4 || op_id > 7)
	{
		if (!((*piles).opa))
		{
			ft_printf("Operation %d demandee sur une liste a vide.\n", op_id);
			return ;
		}
		temp = (*piles).opa;
		(*piles).opa = ((*piles).opa)->next;
		free(temp);
	}
	if (op_id > 3)
	{
		if (!((*piles).opb))
		{
			ft_printf("Operation %d demandee sur une liste b vide.\n", op_id);
			return ;
		}
		temp = (*piles).opb;
		(*piles).opb = ((*piles).opb)->next;
		free(temp);
	}
}

/*Sub-function.
Calculate the number of operation in the opposite operation list before
 reaching its end or finding the same operation as the one given (ex:
  given sa we look for sb)*/
static int	fts_piles_dist_match(t_piles_state *piles, int op_id)
{
	int			dist;
	t_pile_op	*elem;

	dist = 0;
	if (op_id < 4)
	{
		elem = (*piles).opb;
		while (elem && elem->op != op_id + 4)
		{
			elem = elem->next;
			dist++;
		}
	}
	else if (op_id < 8)
	{
		elem = (*piles).opa;
		while (elem && elem->op != op_id - 4)
		{
			elem = elem->next;
			dist++;
		}
	}
	else
		return (printf("Erreur : Calcul de max dans un cas inapproprie.\n"));
	return (dist);
}

/*Do one operation and remove it from the operation list*/
void	ft_piles_do_one_operation(t_piles_state *piles, int op_id)
{
	if (op_id == 0)
		ft_circlst_push(&((*piles).pa), &((*piles).pb), "pa");
	else if (op_id == 1)
		ft_circlst_swap(&((*piles).pa), "sa");
	else if (op_id == 2)
		ft_circlst_rotate(&((*piles).pa), "ra");
	else if (op_id == 3)
		ft_circlst_rev_rotate(&((*piles).pa), "rra");
	else if (op_id == 4)
		ft_circlst_push(&((*piles).pb), &((*piles).pa), "pb");
	else if (op_id == 5)
		ft_circlst_swap(&((*piles).pb), "sb");
	else if (op_id == 6)
		ft_circlst_rotate(&((*piles).pb), "rb");
	else if (op_id == 7)
		ft_circlst_rev_rotate(&((*piles).pb), "rrb");
	else if (op_id == 8)
		ft_circlst_swap2(&((*piles).pa), &((*piles).pb));
	else if (op_id == 9)
		ft_circlst_rotate2(&((*piles).pa), &((*piles).pb));
	else if (op_id == 10)
		ft_circlst_rev_rotate2(&((*piles).pa), &((*piles).pb));
	if (op_id != 0 && op_id != 4)
		fts_piles_rm_op(piles, op_id);
}

/* Normalement inutile
verifie qu'il n'y a pas de ra rra ou rra ra ou ... a la suite dans les piles
 d'op et les supprime le casecheant.
static void	fts_piles_delete_consecutive(t_piles_state *piles)
{
	if ((*piles).opa && (*piles).opa->next && (*piles).opa->op == 2
		&& (*piles).opa->next->op == 3)
	{
		fts_piles_rm_op(piles, 2);
		fts_piles_rm_op(piles, 3);
	}
	else if ((*piles).opa && (*piles).opa->next && (*piles).opa->op == 3
		&& (*piles).opa->next->op == 2)
	{
		fts_piles_rm_op(piles, 3);
		fts_piles_rm_op(piles, 2);
	}
	else if ((*piles).opb && (*piles).opb->next && (*piles).opb->op == 2
		&& (*piles).opb->next->op == 3)
	{
		fts_piles_rm_op(piles, 2);
		fts_piles_rm_op(piles, 3);
	}
	else if ((*piles).opb && (*piles).opb->next && (*piles).opb->op == 3
		&& (*piles).opb->next->op == 2)
	{
		fts_piles_rm_op(piles, 3);
		fts_piles_rm_op(piles, 2);
	}
}
*/

/*Activated when a push operation is orderd or at the end
 of the program -> execute all the operation trying to have as mutch
 matchs as possible.*/
void	ft_piles_do_all_operations(t_piles_state *piles)
{
	int	len_match_a;
	int	len_match_b;

	while ((*piles).opa && (*piles).opb)
	{
		if (((*piles).opa)->op + 4 == ((*piles).opb)->op)
			ft_piles_do_one_operation(piles, ((*piles).opb)->op + 3);
		else
		{
			len_match_a = fts_piles_dist_match(piles, ((*piles).opa)->op);
			len_match_b = fts_piles_dist_match(piles, ((*piles).opb)->op);
			if (len_match_a > len_match_b)
				ft_piles_do_one_operation(piles, ((*piles).opa)->op);
			else
				ft_piles_do_one_operation(piles, ((*piles).opb)->op);
		}
	}
	while ((*piles).opa)
		ft_piles_do_one_operation(piles, ((*piles).opa)->op);
	while ((*piles).opb)
		ft_piles_do_one_operation(piles, ((*piles).opb)->op);
}
