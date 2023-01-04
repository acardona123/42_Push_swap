/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:56:39 by acardona          #+#    #+#             */
/*   Updated: 2023/01/04 22:13:03 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_piles_state	piles;
	char			*tab_op[11];

	ft_piles_and_tab_init(&piles, tab_op);
	if (ac < 2)
	{
		write(1, "Nb d'arguments incorrect.\n", 26);
		return (1);
	}
	if (ft_parsing(ac, av, &(piles.pa)))
	{
		write(1, "Erreur de parsing.\n", 19);
		return (1);
	}
	ft_sort(&piles, ac - 1, (ac - 1) / 2 + (ac - 1) % 2);
	ft_piles_merge_all_operations(&piles);
	ft_piles_print_op(piles, tab_op);
	ft_cirlst_clear(&(piles.pa));
	ft_cirlst_clear(&(piles.pb));
	ft_cirlst_clear(&(piles.opa));
	ft_cirlst_clear(&(piles.opb));
	ft_cirlst_clear(&(piles.opall));
	return (0);
}
