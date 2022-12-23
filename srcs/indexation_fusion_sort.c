/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation_fusion_sort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:14:53 by acardona          #+#    #+#             */
/*   Updated: 2022/12/21 21:42:32 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Copy the len_tot elem of tab_src in tab_dest*/
static void	fts_tab_moove(t_2int *tab_dest, t_2int *tab_src, int len_tot)
{
	int	i;

	i = 0;
	while (i < len_tot)
	{
		tab_dest[i] = tab_src[i];
		i++;
	}
}

/*Fusion of two t_2int list (already sorted) in one sorted list*/
static int	fts_sub_fusion(t_2int *tab_l, t_2int *tab_r, int len_tot)
{
	t_2int	*tmp_tab;
	int		i_l;
	int		i_r;

	tmp_tab = malloc(len_tot * sizeof(t_2int));
	if (!tmp_tab)
		return (1);
	i_l = 0;
	i_r = 0;
	while (i_l + i_r < len_tot)
	{
		if (i_l >= len_tot / 2 || (tab_r[i_r]).value > (tab_l[i_l]).value)
		{
			tmp_tab[i_l + i_r] = tab_r [i_r];
			i_r++;
		}
		else
		{
			tmp_tab[i_l + i_r] = tab_l[i_l];
			i_l++;
		}
	}
	fts_tab_moove(tab_l, tab_r, len_tot);
	free(tmp_tab);
	return (0);
}

/*Fusion methode for sorting a table of len t_2int elements by increasing
 values of value*/
t_2int	*ft_index_fusion(t_2int *tab, unsigned int lentab)
{
	t_2int	*tmp_tab_left;
	t_2int	*tmp_tab_right;

	if (lentab <= 1)
		return (tab);
	if (!tab)
		return (0);
	tmp_tab_left = ft_index_fusion(tab, lentab / 2);
	tmp_tab_right = ft_index_fusion(tab + lentab / 2, lentab / 2 + lentab % 2);
	if (fts_sub_fusion(tmp_tab_left, tmp_tab_right, lentab))
		return (0);
	return (tab);
}
