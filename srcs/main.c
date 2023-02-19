/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:56:39 by acardona          #+#    #+#             */
/*   Updated: 2023/02/19 17:57:43 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	fts_set_param(int ac, char **av, char ***arg, int *nb_arg)
{
	*arg = 0;
	*nb_arg = 0;
	if (ac == 2)
	{
		*arg = ft_split(av[1], ' ');
		if (!*arg)
			return (1);
		if (!**arg && ft_strlen(av[1]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		*nb_arg = ft_split_len(*arg);
	}
	else if (ac > 2)
	{
		*arg = av + 1;
		*nb_arg = ac - 1;
	}
	return (0);
}

static void	fts_sub_main(t_piles_state	*piles, int nb_arg, char *tab_op[11])
{
	if (ft_circlst_len(piles->pa) <= 3)
		ft_sort_lst3(piles);
	else
		ft_sort(piles, nb_arg, nb_arg / 2 + nb_arg % 2);
	ft_piles_merge_all_operations(piles);
	ft_piles_print_op(*piles, tab_op);
}

int	main(int ac, char **av)
{
	t_piles_state	piles;
	char			*tab_op[11];
	char			**arg;
	int				nb_arg;

	if (ac < 2)
		return (0);
	ft_piles_and_tab_init(&piles, tab_op);
	fts_set_param(ac, av, &arg, &nb_arg);
	if (!arg || (nb_arg >= 1 && ft_parsing(nb_arg, arg, &(piles.pa))))
	{
		if (ac == 2)
			ft_split_free(arg);
		return (write(2, "Error\n", 6), 1);
	}
	if (nb_arg > 1)
		fts_sub_main(&piles, nb_arg, tab_op);
	ft_piles_free(&piles);
	if (ac == 2)
		ft_split_free(arg);
	return (0);
}
