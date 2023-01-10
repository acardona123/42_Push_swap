/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:20:51 by acardona          #+#    #+#             */
/*   Updated: 2023/01/10 16:59:56 by acardona         ###   ########.fr       */
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
	ft_piles_clear(piles);
	if (error == 1)
		write(1, "Error\n", 6);
	else if (error)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return (error);
}

#include <stdio.h>


int	main(int ac, char **av)
{
	char			*str;
	t_piles_state	piles;
	int				op;

	ft_piles_init(&piles);
	if (ac < 2 || ft_parsing(ac, av, &(piles.pa)))
		return (fts_return_msg(&piles, 1));
	str = get_next_line(0);
	while (str)
	{
		op = fts_exec_action(str);
		free(str);
		if (op == -1)
			return (fts_return_msg(&piles, 2));
		ft_piles_do_one_operation(&piles, op);
		str = get_next_line(0);
	}
	if (!ft_is_sorted(piles.pa, ft_circlst_len(piles.pa)))
		return (fts_return_msg(&piles, 3));
	if (piles.pb)
		return (fts_return_msg(&piles, 4));
	fts_return_msg(&piles, 0);
	return (0);
}



//make bonus  && echo "$(< "rdmvalues.txt")" && ./push_swap $(< "rdmvalues.txt") | ./checker $(< "rdmvalues.txt") | cat -e