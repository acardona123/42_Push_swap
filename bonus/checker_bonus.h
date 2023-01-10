/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:03:35 by acardona          #+#    #+#             */
/*   Updated: 2023/01/09 23:04:47 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include "../includes/gnl/get_next_line.h"

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

/*../srcs/circlst/circlst_building_bonus.c*/
t_lstcirc	*ft_circlst_new_elem(int nb, unsigned int index);
int			ft_circlst_addtop(t_lstcirc **lst_top, t_lstcirc *new_elem);
int			ft_circlst_addabove(t_lstcirc **lst_origin, t_lstcirc *new_elem);
int			ft_cirlst_clear(t_lstcirc **lst);
int			ft_cirlst_rm1(t_lstcirc **lst);
/*../srcs/circlst/circlst_rotate_bonus.c*/
int			ft_circlst_rotate(t_lstcirc **lst_top, char *msg);
int			ft_circlst_rotate2(t_lstcirc **lst_top1, t_lstcirc **lst_top2);
int			ft_circlst_rev_rotate(t_lstcirc **lst_top, char *msg);
int			ft_circlst_rev_rotate2(t_lstcirc **lst_top1, t_lstcirc **lst_top2);
/*../srcs/circlst/circlst_swap_push_bonus.c*/
int			ft_circlst_swap(t_lstcirc **lst_top, char *msg);
int			ft_circlst_swap2(t_lstcirc **lst_top_1, t_lstcirc **lst_top_2);
int			ft_circlst_push(t_lstcirc **lst1, t_lstcirc **lst2, char *msg);
/*../srcs/circlst/circlst_tools_bonus.c*/
int			ft_circlst_len(t_lstcirc *lst_top);
int			ft_is_sorted(t_lstcirc *lst, int len);
void		ft_piles_push_bottom(t_lstcirc **lsrc, t_lstcirc **ldest);
/*parsing.c*/
int			ft_parsing(int ac, char **av, t_lstcirc **lst);
int			ft_parse_index_table(t_2int *tab, int len_tab);
/*parsing_bis.c*/
int			ft_check_int_format(char *str);
int			ft_check_atoi(char *str);
int			ft_check_double(t_2int **tab, int i_tab, int n);
/*piles_op_optimisation_bonus.c*/
void		ft_piles_init(t_piles_state *piles);
void		ft_piles_do_one_operation(t_piles_state *piles, int op_id);
void		ft_piles_clear(t_piles_state *piles);
/*checker_bonus.c*/
/*tools_bonus.c*/
int			ft_strdiff(char *str1, char *str2);
#endif