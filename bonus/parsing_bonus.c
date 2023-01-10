/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:29:56 by acardona          #+#    #+#             */
/*   Updated: 2023/01/09 22:58:16 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	fts_parse_to_table(int ac, char **av, t_2int **tab)
{
	int		i;
	t_2int	elem;
	int		num;

	if (ac < 2)
		return (1);
	*tab = malloc((ac - 1) * sizeof(t_2int));
	if (!tab)
		return (1);
	i = -1;
	while (++i < ac - 1)
	{
		num = ft_atoi(av[i + 1]);
		if (ft_check_int_format(av[i +1]) || (!num && ft_check_atoi(av[i + 1]))
			|| ft_check_double(tab, i, num))
		{
			free(*tab);
			return (1);
		}
		elem.value = ft_atoi(av[i + 1]);
		elem.index = i;
		(*tab)[i] = elem;
	}
	return (0);
}

static int	fts_parse_table_to_lst(t_2int *tab, int ac, t_lstcirc **lst_top)
{
	int			i;
	t_lstcirc	*elem;

	if (!tab || ac < 2 || !lst_top)
		return (1);
	i = 0;
	while (i < ac - 1)
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

int	ft_parsing(int ac, char **av, t_lstcirc **lst)
{
	t_2int	*tab;

	if (fts_parse_to_table(ac, av, &tab))
	{
		return (1);
	}
	if (fts_parse_table_to_lst(tab, ac, lst))
	{
		free(tab);
		return (1);
	}
	free(tab);
	return (0);
}
