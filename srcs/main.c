/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:56:39 by acardona          #+#    #+#             */
/*   Updated: 2023/01/10 18:20:52 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_piles_state	piles;
	char			*tab_op[11];

	ft_piles_and_tab_init(&piles, tab_op);
	if (ac < 2)
		return (1);
	if (ft_parsing(ac, av, &(piles.pa)))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (ft_circlst_len(piles.pa) <= 3)
		ft_sort_lst3(&piles);
	else
		ft_sort(&piles, ac - 1, (ac - 1) / 2 + (ac - 1) % 2);
	ft_piles_merge_all_operations(&piles);
	ft_piles_print_op(piles, tab_op);
	ft_piles_clear(&piles);
	return (0);
}
