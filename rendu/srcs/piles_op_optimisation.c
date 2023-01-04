/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_op_optimisation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:08:29 by acardona          #+#    #+#             */
/*   Updated: 2023/01/04 21:25:00 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Init the struct containing 2 piles, their op lists. Init tab_op for display*/
void	ft_piles_and_tab_init(t_piles_state *piles, char *tab_op[11])
{
	piles->pa = 0;
	piles->pb = 0;
	piles->opa = 0;
	piles->opb = 0;
	piles->opall = 0;
	piles->init = 2;
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
// void	ft_piles_do_one_operation(t_piles_state *piles, int op_id)
// {
// 	if (op_id == 0)
// 		ft_circlst_push(&(piles->pa), &(piles->pb), "pa");
// 	else if (op_id == 1)
// 		ft_circlst_swap(&(piles->pa), "sa");
// 	else if (op_id == 2)
// 		ft_circlst_rotate(&(piles->pa), "ra");
// 	else if (op_id == 3)
// 		ft_circlst_rev_rotate(&(piles->pa), "rra");
// 	else if (op_id == 4)
// 		ft_circlst_push(&(piles->pb), &(piles->pa), "pb");
// 	else if (op_id == 5)
// 		ft_circlst_swap(&(piles->pb), "sb");
// 	else if (op_id == 6)
// 		ft_circlst_rotate(&(piles->pb), "rb");
// 	else if (op_id == 7)
// 		ft_circlst_rev_rotate(&(piles->pb), "rrb");
// 	else if (op_id == 8)
// 		ft_circlst_swap2(&(piles->pa), &(piles->pb));
// 	else if (op_id == 9)
// 		ft_circlst_rotate2(&(piles->pa), &(piles->pb));
// 	else if (op_id == 10)
// 		ft_circlst_rev_rotate2(&(piles->pa), &(piles->pb));
// }

/*add the operation to the pile(s) of operation corresponding*/
int	ft_piles_add_op_to(t_piles_state *piles, t_lstcirc	**l_op, int op)
{
	t_lstcirc	*new;

	new = ft_circlst_new_elem(op, 0);
	if (!new)
	{
		ft_piles_merge_all_operations(piles);
		ft_printf("Erreur : Malloc d'optimisation echoue, %d impossible\n", op);
		return (1);
	}
	ft_circlst_addabove(l_op, new);
	return (0);
}

/*Add op to the matching op_list. if op=push: merge opa&opb to make collisions*/
int	ft_piles_add_op(t_piles_state *piles, int op_id)
{
	t_lstcirc	**l_op;
	t_lstcirc	*new;

	ft_piles_do_one_operation(piles, op_id);
	if (op_id == 0 || op_id == 4 || op_id > 7)
	{
		l_op = &(piles->opall);
		ft_piles_merge_all_operations(piles);
	}
	else if (op_id < 4)
		l_op = &(piles->opa);
	else
		l_op = &(piles->opb);
	new = ft_circlst_new_elem(op_id, 0);
	if (!new)
	{
		ft_printf("Erreur d'ajouts d'elements\n");
		return (1);
	}
	ft_circlst_addabove(l_op, new);
	return (0);
}

/*Add up to 3 op to the op waiting lists corresponding. (op added if >= 0)*/
int	ft_piles_add_3_op(t_piles_state *piles, int op1, int op2, int op3)
{
	int	err;

	err = 0;
	if (op1 >= 0)
		err += ft_piles_add_op(piles, op1);
	if (op2 >= 0)
		err += ft_piles_add_op(piles, op2);
	if (op3 >= 0)
		err += ft_piles_add_op(piles, op3);
	if (err > 0)
		ft_printf("Erreur dans l'executon des 3 op\n");
	return (err);
}
