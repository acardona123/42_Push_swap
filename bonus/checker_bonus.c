/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:20:51 by acardona          #+#    #+#             */
/*   Updated: 2023/02/16 20:38:45 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	fts_exec_action(char *str)
{
	if (!ft_strdiff(str, "pa\n"))
		return (0);
	else if (!ft_strdiff(str, "sa\n"))
		return (1);
	else if (!ft_strdiff(str, "ra\n"))
		return (2);
	else if (!ft_strdiff(str, "rra\n"))
		return (3);
	else if (!ft_strdiff(str, "pb\n"))
		return (4);
	else if (!ft_strdiff(str, "sb\n"))
		return (5);
	else if (!ft_strdiff(str, "rb\n"))
		return (6);
	else if (!ft_strdiff(str, "rrb\n"))
		return (7);
	else if (!ft_strdiff(str, "ss\n"))
		return (8);
	else if (!ft_strdiff(str, "rr\n"))
		return (9);
	else if (!ft_strdiff(str, "rrr\n"))
		return (10);
	else
		return (-1);
}

static int	fts_return_msg(t_piles_state *piles, char error)
{
	ft_piles_free(piles);
	if (error == -1)
		write(1, "Error malloc in checker\n", 24);
	else if (error == 1)
		write(1, "Error\n", 6);
	else if (error)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return (error);
}

static int	fts_set_param(int ac, char **av, char ***arg, int *nb_arg)
{
	if (ac < 2)
		return (1);
	if (ac == 2)
	{
		*arg = ft_split(av[1], ' ');
		*nb_arg = ft_split_len(*arg);
	}
	else if (ac > 2)
	{
		*arg = av + 1;
		*nb_arg = ac - 1;
	}
	return (0);
}

int	main(int ac, char **av)
{
	char			*str;
	t_piles_state	piles;
	char			**av1;
	int				ac1;

	ft_piles_init(&piles);
	if (fts_set_param(ac, av, &av1, &ac1) || ft_parsing(ac1, av1, &(piles.pa)))
		return (fts_return_msg(&piles, 1));
	str = get_next_line(0);
	while (str)
	{
		piles.pa->index = fts_exec_action(str);
		free(str);
		if (piles.pa->index == -1)
			return (fts_return_msg(&piles, 2));
		if (ft_piles_add_op_to(&piles.opall, piles.pa->index))
			return (fts_return_msg(&piles, -1));
		str = get_next_line(0);
	}
	ft_piles_op_do_all_op(&piles);
	if (!ft_is_sorted(piles.pa, ft_circlst_len(piles.pa)) || piles.pb)
		return (fts_return_msg(&piles, 3));
	fts_return_msg(&piles, 0);
	return (0);
}

/*ARG="$(./randomizer.sh 0 99)" && ./push_swap $ARG | ./checker $ARG*/