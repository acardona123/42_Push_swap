/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_op_optimisation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:08:29 by acardona          #+#    #+#             */
/*   Updated: 2022/12/27 23:47:15 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Init the struct containing the to piles and their associated lists of
 waiting operations*/
void	ft_piles_init(t_piles_state *piles)
{
	piles->pa = 0;
	piles->pb = 0;
	piles->opa = 0;
	piles->opb = 0;
}

/*add the operation to the pile(s) of operation corresponding*/
static int	fts_piles_sub_add_op(t_piles_state piles, int op_id)
{
	t_pile_op	**lst;
	t_pile_op	*new;
	t_pile_op	*elem;

	if (op_id < 4)
		lst = &piles.opa;
	else
		lst = &piles.opb;
	new = ft_calloc(sizeof(t_pile_op), 1);
	if (!new)
	{
		do_all_operations(piles, op_id);
		return (printf("Malloc d'optimisation echoue, pas grave\n") / 40);
	}
	new->op = op_id;
	if (!(*lst))
	{
		*lst = new;
		return (0);
	}
	elem = *lst;
	while (elem->next)
		elem = elem->next;
	elem->next = new;
	return (0);
}

/*MAIN FONCTION : Given one new operation to process, it will ether (case op = push) make all
 the registered op (optimizing matches) and execute the push, ether stock the
  new op for later.*/
int	ft_pile_add_op(t_piles_state piles, int op_id)
{
	if (op_id == 0 || op_id == 4)
	{
		ft_piles_do_all_operations(piles);
		ft_piles_do_one_operation(piles, op_id);
	}
	else
		fts_piles_sub_add_op(piles, op_id);
}
