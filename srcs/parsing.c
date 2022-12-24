/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:29:56 by acardona          #+#    #+#             */
/*   Updated: 2022/12/23 21:52:41 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	fts_check_number_format(char *str)
{
	int	i;

	i = 0;
	if (!str || *str == 0)
		return (1);
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	fts_check_atoi(char *str)
{
	size_t	i;

	if (!str || *str == 0)
		return (1);
	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

static int	fts_parse_to_table(int ac, char **av, t_2int	**tab)
{
	int		i;
	t_2int	elem;

	if (ac < 2)
		return (1);
	*tab = malloc((ac - 1) * sizeof(t_2int));
	if (!tab)
		return (1);
	i = 0;
	while (i < ac - 1)
	{
		if (fts_check_number_format(av[i +1]))
			return (1);
		elem.value = ft_atoi(av[i + 1]);
		elem.index = i;
		if (elem.value == 0 && fts_check_atoi(av[i + 1]))
		{
			free(*tab);
			return (1);
		}
		(*tab)[i] = elem;
		i++;
	}
	return (0);
}

static int	fts_parse_table_to_lst(t_2int *tab, int ac, t_lstcirc**lst_top)
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
		return (1);
	ft_parse_index_table(tab, ac - 1);
	if (ft_parse_index_table(tab, ac -1)
		|| fts_parse_table_to_lst(tab, ac, lst))
	{
		free(tab);
		return (1);
	}
	free(tab);
	return (0);
}
