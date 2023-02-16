/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:29:56 by acardona          #+#    #+#             */
/*   Updated: 2023/02/16 20:34:17 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	fts_parse_to_table(int len, char **ar, t_2int **tab)
{
	int		i;
	t_2int	elem;
	int		num;

	if (len < 1)
		return (1);
	*tab = malloc((len) * sizeof(t_2int));
	if (!tab)
		return (1);
	i = -1;
	while (++i < len)
	{
		num = ft_atoi(ar[i]);
		if (ft_check_int_format(ar[i]) || (!num && ft_check_atoi(ar[i]))
			|| ft_check_double(tab, i, num))
		{
			free(*tab);
			return (1);
		}
		elem.value = ft_atoi(ar[i]);
		elem.index = i;
		(*tab)[i] = elem;
	}
	return (0);
}

static int	fts_parse_table_to_lst(t_2int *tab, int len, t_lstcirc **lst_top)
{
	int			i;
	t_lstcirc	*elem;

	if (!tab || len < 1 || !lst_top)
		return (1);
	i = 0;
	while (i < len)
	{
		elem = ft_circlst_new_elem((tab[i]).value, (tab[i].index));
		if (!elem)
			return (1);
		if (ft_circlst_addabove(lst_top, elem))
			return (1);
		i++;
	}
	return (0);
}

/*Parsing of the arguments, binary offset indicates if first elem ignored*/
int	ft_parsing(int len, char **arg, t_lstcirc **lst)
{
	t_2int	*tab;

	if (fts_parse_to_table(len, arg, &tab))
		return (1);
	if (ft_parse_index_table(tab, len)
		|| fts_parse_table_to_lst(tab, len, lst))
	{
		free(tab);
		return (1);
	}
	free(tab);
	return (0);
}
