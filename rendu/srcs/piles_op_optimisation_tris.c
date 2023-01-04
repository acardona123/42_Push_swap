/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_op_optimisation_tris.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:12:45 by acardona          #+#    #+#             */
/*   Updated: 2023/01/04 21:30:50 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Print the list of operations waiting to be done in both piles*/
void	ft_piles_print_op(t_piles_state piles, char *t_op[11])
{
	t_lstcirc	*elem;

	elem = piles.opall;
	while (elem && elem->down != piles.opall)
	{
		ft_putendl_fd(t_op[elem->value], 1);
		elem = elem->down;
	}
	if (elem)
		ft_putendl_fd(t_op[elem->value], 1);
}

//VERSION LONGUE DE LA FONCTIONPERMETTANT D'AFFICHER AUSSI OPA ET OPB
// /*Print the list of operations waiting to be done in both piles*/
// void	ft_piles_print_op_long
//(t_piles_state piles, char *t_op[11], int ab, int talk)
// {
// 	t_lstcirc	*elem;
// 
// 	if (ab)
// 	{
// 		elem = piles.opa;
// 		ft_printf("\e[34m======\nOp en attente d'execution :\n- LISTE OP A :\n");
// 		while (elem && elem->down != piles.opa)
// 		{
// 			ft_putendl_fd(t_op[elem->value], 1);
// 			elem = elem->down;
// 		}
// 		if (elem)
// 			ft_putendl_fd(t_op[elem->value], 1);
// 		elem = piles.opb;
// 		ft_printf("- LISTE OP B :\n");
// 		while (elem && elem->down != piles.opb)
// 		{
// 			ft_putendl_fd(t_op[elem->value], 1);
// 			elem = elem->down;
// 		}
// 		if (elem)
// 			ft_putendl_fd(t_op[elem->value], 1);
// 	}
// 	elem = piles.opall;
// 	if (talk)
// 		ft_printf("\e[34m\n- LISTE OP all :\n");
// 	while (elem && elem->down != piles.opall)
// 	{
// 		ft_putendl_fd(t_op[elem->value], 1);
// 		elem = elem->down;
// 	}
// 	if (elem)
// 		ft_putendl_fd(t_op[elem->value], 1);
// 	if (talk)
// 		ft_printf("======\e[0m\n");
// }

/*Sub ...merge_all_op : calculate the nb of op in opposit lst to find match*/
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
		return (ft_printf("Erreur : Calcul de dist dans un cas inapproprie.\n"));
	return (dist);
}

/*sub-function of ft_piles_merge_all_operations (for the norm)*/
static void	fts_sub_merge_all_operations(t_piles_state *piles)
{
	int	len_match_a;
	int	len_match_b;

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
			ft_piles_push_bottom(&(piles->opa), &(piles->opall));
		else
			ft_piles_push_bottom(&(piles->opb), &(piles->opall));
	}
}

/*used if push op: merge opa & opb in opall (ordered to maximize op matches).*/
void	ft_piles_merge_all_operations(t_piles_state *piles)
{
	ft_piles_delete_consecutive_op_all(piles);
	while (piles->opa && piles->opb)
		fts_sub_merge_all_operations(piles);
	while (piles->opa)
		ft_piles_push_bottom(&(piles->opa), &(piles->opall));
	while (piles->opb)
		ft_piles_push_bottom(&(piles->opb), &(piles->opall));
}
