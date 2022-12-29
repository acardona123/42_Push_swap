/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_op_optimisation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:08:29 by acardona          #+#    #+#             */
/*   Updated: 2022/12/29 00:52:06 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Init the struct containing the to piles and their associated lists of
 waiting operations
 &
 Init the given tab_op table used to visualize registered */
void	ft_piles_and_tab_init(t_piles_state *piles, char *tab_op[11])
{
	piles->pa = 0;
	piles->pb = 0;
	piles->opa = 0;
	piles->opb = 0;
	tab_op[0] = "pa";
	tab_op[1] = "sa";
	tab_op[2] = "ra";
	tab_op[3] = "rra";
	tab_op[4] = "pb";
	tab_op[5] = "sb";
	tab_op[6] = "rb";
	tab_op[7] = "rrb";
	tab_op[8] = "ss";
	tab_op[9] = "rr";
	tab_op[10] = "rrr";
}

/*add the operation to the pile(s) of operation corresponding*/
static int	fts_piles_sub_add_op(t_piles_state *piles, int op_id)
{
	t_pile_op	**lst;
	t_pile_op	*new;
	t_pile_op	*elem;

	if (op_id < 4)
		lst = &(*piles).opa;
	else
		lst = &(*piles).opb;
	new = ft_calloc(sizeof(t_pile_op), 1);
	if (!new)
	{
		ft_piles_do_all_operations(piles);
		ft_piles_do_one_operation(piles, op_id);
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

/*Given one new operation to process, it will ether (case op = push) make all
 the registered op (optimizing matches) and execute the push, ether stock the
  new op for later.*/
void	ft_piles_add_op(t_piles_state *piles, int op_id)
{
	if (op_id == 0 || op_id == 4)
	{
		ft_piles_do_all_operations(piles);
		ft_piles_do_one_operation(piles, op_id);
	}
	else
		fts_piles_sub_add_op(piles, op_id);
}

/*Add up to three op to the op waiting lists corresponding.
 All op >=0 given will be added */
void	ft_piles_add_3_op(t_piles_state *piles, int op1, int op2, int op3)
{
	if (op1 >= 0)
		fts_piles_sub_add_op(piles, op1);
	if (op2 >= 0)
		fts_piles_sub_add_op(piles, op2);
	if (op3 >= 0)
		fts_piles_sub_add_op(piles, op3);
}

/*Print the list of operations waiting to be done in both piles*/
void	ft_piles_print_op(t_piles_state *piles, char *tab_op[11])
{
	t_pile_op	*elem;

	elem = (*piles).opa;
	ft_putendl_fd("\e[34m======\nAffichage des op en attente d'execution :", 1);
	ft_putendl_fd("- LISTE OP A :", 1);
	while (elem)
	{
		ft_putendl_fd(tab_op[elem->op], 1);
		elem = elem->next;
	}
	elem = (*piles).opb;
	ft_putendl_fd("\n- LISTE OP B :", 1);
	while (elem)
	{
		ft_putendl_fd(tab_op[elem->op], 1);
		elem = elem->next;
	}
	ft_putendl_fd("======\e[0m\n", 1);
}
