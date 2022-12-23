/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation_fusion_sort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:14:53 by acardona          #+#    #+#             */
/*   Updated: 2022/12/23 17:19:36 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Copy the len_tot elem of tab_src in tab_dest*/
static void	fts_tab_cpy(t_2int *tab_dest, t_2int *tab_src, int len_tot)
{
	int	i;

	i = -1;
	while (++i < len_tot)
		tab_dest[i] = tab_src[i];
}

/*Fusion of two t_2int list (already sorted) in one sorted list*/
static int	fts_sub_fusion(t_2int *l, t_2int *r, int len_l, int len_r)
{
	t_2int	*tmp_tab;
	int		i_l;
	int		i_r;

	tmp_tab = malloc((len_l + len_r) * sizeof(t_2int));
	if (!tmp_tab)
		return (1);
	i_l = 0;
	i_r = 0;
	while (i_l + i_r < len_l + len_r)
	{
		if (i_l >= len_l || (i_r < len_r && (r[i_r]).value < (l[i_l]).value))
		{
			tmp_tab[i_l + i_r] = r[i_r];
			i_r++;
		}
		else
		{
			tmp_tab[i_l + i_r] = l[i_l];
			i_l++;
		}
	}
	fts_tab_cpy(l, tmp_tab, len_l + len_r);
	free(tmp_tab);
	return (0);
}

/*Fusion methode for sorting a table of len t_2int elements by increasing
 values of value*/
t_2int	*fts_index_fusion(t_2int *tab, int lentab)
{
	t_2int	*tmp_tab_left;
	t_2int	*tmp_tab_right;
	int		len_left;
	int		len_right;

	if (lentab <= 1)
		return (tab);
	if (!tab)
		return (0);
	len_left = lentab / 2;
	len_right = lentab / 2 + lentab % 2;
	tmp_tab_left = fts_index_fusion(tab, len_left);
	tmp_tab_right = fts_index_fusion(tab + len_left, len_right);
	if (!tmp_tab_left || !tmp_tab_right)
		return (0);
	if (fts_sub_fusion(tmp_tab_left, tmp_tab_right, len_left, len_right))
		return (0);
	return (tab);
}

int	ft_parse_index_table(t_2int *tab, int len_tab)
{
	int		i;
	t_2int	*tab_cpy;

	tab_cpy = malloc(len_tab * sizeof(t_2int));
	if (!tab_cpy)
		return (1);
	fts_tab_cpy(tab_cpy, tab, len_tab);
	if (fts_index_fusion(tab_cpy, len_tab) == 0)
		return (1);
	i = 0;
	while (i < len_tab)
	{
		(tab[(tab_cpy[i]).index]).index = i + 1;
		i++;
	}
	return (0);
}
