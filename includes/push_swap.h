/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:46:58 by acardona          #+#    #+#             */
/*   Updated: 2022/12/27 23:51:05 by acardona         ###   ########.fr       */
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

typedef struct s_pile_op
{
	int					op;
	struct s_pile_op	*next;
}	t_pile_op;

typedef struct s_piles_state
{
	t_lstcirc	*pa;
	t_lstcirc	*pb;
	t_pile_op	*opa;
	t_pile_op	*opb;
}	t_piles_state;

/*circlst_building.c*/
t_lstcirc	*ft_circlst_new_elem(int nb, unsigned int index);
int			ft_circlst_addtop(t_lstcirc **lst_top, t_lstcirc *new_elem);
int			ft_circlst_addabove(t_lstcirc **lst_origin, t_lstcirc *new_elem);
int			ft_cirlst_clear(t_lstcirc **lst);
/*circlst_print.c*/
void		ft_circlst_printduo(char *msg, t_lstcirc **lst1, t_lstcirc **lst2);
/*circlst_rotate.c*/
int			ft_circlst_rotate(t_lstcirc **lst_top);
int			ft_circlst_rotate2(t_lstcirc **lst_top1, t_lstcirc **lst_top2);
int			ft_circlst_rev_rotate(t_lstcirc **lst_top);
int			ft_circlst_rev_rotate2(t_lstcirc **lst_top1, t_lstcirc **lst_top2);
/*circlst_swap_push.c*/
int			ft_circlst_swap(t_lstcirc **lst_top);
int			ft_circlst_swap2(t_lstcirc **lst_top_1, t_lstcirc **lst_top_2);
int			ft_circlst_push(t_lstcirc **lst1, t_lstcirc **lst2);
/*circlst_tools.c*/
int			ft_circlst_len(t_lstcirc *lst_top);
int			ft_is_sorted(t_lstcirc **lst, int len);
/*parsing.c*/
int			ft_parsing(int ac, char **av, t_lstcirc **lst);
int			ft_parse_index_table(t_2int *tab, int len_tab);
/*piles_op_optimisation.c*/
void		ft_piles_init(t_piles_state *piles);
int			ft_pile_add_op(t_piles_state piles, int op_id);
/*piles_op_optimisation_bis.c*/
int			ft_piles_do_all_operations(t_piles_state piles);
/*sorting.c*/
void		ft_pile_sort(t_lstcirc **la, t_lstcirc **lb, int pivot);

#endif