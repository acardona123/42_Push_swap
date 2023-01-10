/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_op_optimisation_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:08:29 by acardona          #+#    #+#             */
/*   Updated: 2023/01/10 20:57:18 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*Init the struct containing 2 piles, their op lists. Init tab_op for display*/
void	ft_piles_init(t_piles_state *piles)
{
	piles->pa = 0;
	piles->pb = 0;
	piles->opa = 0;
	piles->opb = 0;
	piles->opall = 0;
	piles->init = 2;
}

/*add the operation to the pile(s) of operation corresponding*/
int	ft_piles_add_op_to(t_lstcirc **l_op, int op)
{
	t_lstcirc	*new;

	new = ft_circlst_new_elem(op, 0);
	if (!new)
		return (1);
	ft_circlst_addabove(l_op, new);
	return (0);
}

/*Do one operation and remove it from the operation list*/
void	ft_piles_do_one_operation(t_piles_state *piles, int op_id)
{
	if (op_id == 0)
		ft_circlst_push(&(piles->pa), &(piles->pb), 0);
	else if (op_id == 1)
		ft_circlst_swap(&(piles->pa), 0);
	else if (op_id == 2)
		ft_circlst_rotate(&(piles->pa), 0);
	else if (op_id == 3)
		ft_circlst_rev_rotate(&(piles->pa), 0);
	else if (op_id == 4)
		ft_circlst_push(&(piles->pb), &(piles->pa), 0);
	else if (op_id == 5)
		ft_circlst_swap(&(piles->pb), 0);
	else if (op_id == 6)
		ft_circlst_rotate(&(piles->pb), 0);
	else if (op_id == 7)
		ft_circlst_rev_rotate(&(piles->pb), 0);
	else if (op_id == 8)
		ft_circlst_swap2(&(piles->pa), &(piles->pb));
	else if (op_id == 9)
		ft_circlst_rotate2(&(piles->pa), &(piles->pb));
	else if (op_id == 10)
		ft_circlst_rev_rotate2(&(piles->pa), &(piles->pb));
}

/*Do all the operations of opall*/
void	ft_piles_op_do_all_op(t_piles_state *piles)
{
	t_lstcirc	*elem;

	if (piles->opall)
	{
		elem = piles->opall;
		ft_piles_do_one_operation(piles, elem->value);
		elem = elem->down;
		while (elem && elem != piles->opall)
		{
			ft_piles_do_one_operation(piles, elem->value);
			elem = elem->down;
		}
	}
}

/*free al the circlst of piles*/
void	ft_piles_free(t_piles_state *piles)
{
	ft_circlst_free(&(piles->pa));
	ft_circlst_free(&(piles->pb));
	ft_circlst_free(&(piles->opa));
	ft_circlst_free(&(piles->opb));
	ft_circlst_free(&(piles->opall));
}
