/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:46:58 by acardona          #+#    #+#             */
/*   Updated: 2023/01/02 21:38:56 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libftprintf/ft_printf.h"
# include <stdlib.h>

#include <stdio.h>

typedef struct s_lstcirc
{
	int					value;
	int					index;
	struct s_lstcirc	*up;
	struct s_lstcirc	*down;	
}	t_lstcirc;

typedef struct s_2int
{
	int				value;
	unsigned int	index;
}	t_2int;

typedef struct s_piles_state
{
	t_lstcirc	*pa;
	t_lstcirc	*pb;
	t_lstcirc	*opa;
	t_lstcirc	*opb;
	t_lstcirc	*opall;
	char		init;
}	t_piles_state;

/*circlst_building.c*/
t_lstcirc	*ft_circlst_new_elem(int nb, unsigned int index);
int			ft_circlst_addtop(t_lstcirc **lst_top, t_lstcirc *new_elem);
int			ft_circlst_addabove(t_lstcirc **lst_origin, t_lstcirc *new_elem);
int			ft_cirlst_clear(t_lstcirc **lst);
int			ft_cirlst_rm1(t_lstcirc **lst);
/*circlst_print.c*/
void		ft_circlst_printduo(char *msg, t_lstcirc **lst1, t_lstcirc **lst2);
/*circlst_rotate.c*/
int			ft_circlst_rotate(t_lstcirc **lst_top, char *msg);
int			ft_circlst_rotate2(t_lstcirc **lst_top1, t_lstcirc **lst_top2);
int			ft_circlst_rev_rotate(t_lstcirc **lst_top, char *msg);
int			ft_circlst_rev_rotate2(t_lstcirc **lst_top1, t_lstcirc **lst_top2);
/*circlst_swap_push.c*/
int			ft_circlst_swap(t_lstcirc **lst_top, char *msg);
int			ft_circlst_swap2(t_lstcirc **lst_top_1, t_lstcirc **lst_top_2);
int			ft_circlst_push(t_lstcirc **lst1, t_lstcirc **lst2, char *msg);
/*circlst_tools.c*/
int			ft_circlst_len(t_lstcirc *lst_top);
int			ft_is_sorted(t_lstcirc *lst, int len);
void		ft_piles_push_bottom(t_lstcirc **lsrc, t_lstcirc **ldest);
/*parsing.c*/
int			ft_parsing(int ac, char **av, t_lstcirc **lst);
int			ft_parse_index_table(t_2int *tab, int len_tab);
/*piles_op_optimisation.c*/
void		ft_piles_and_tab_init(t_piles_state *piles, char *tab_op[11]);
void		ft_piles_do_one_operation(t_piles_state *piles, int op_id);
int			ft_piles_add_op_to(t_piles_state *piles, t_lstcirc	**l_op, int op);
int			ft_piles_add_op(t_piles_state *piles, int op_id);
int			ft_piles_add_3_op(t_piles_state *piles, int op1, int op2, int op3);
void		ft_piles_print_op(t_piles_state piles, char *tab_op[11], int ab, int talk);
/*piles_op_optimisation_bis.c*/
void		ft_piles_merge_all_operations(t_piles_state *piles);
void		ft_piles_delete_consecutive_op_one(t_lstcirc **oplst);
void		ft_piles_delete_consecutive_op_all(t_piles_state *piles);
/*sorting.c*/
void		ft_sort(t_piles_state *piles, int len, int pivot_a);

#endif