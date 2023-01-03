/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:56:39 by acardona          #+#    #+#             */
/*   Updated: 2023/01/02 19:24:15 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_piles_state	piles;
	char			*tab_op[11];

	ft_piles_and_tab_init(&piles, tab_op);
	if (ac < 3)
	{
		write(1, "Nb d'arguments incorrect.\n", 26);
		return (1);
	}
	if (ft_parsing(ac, av, &(piles.pa)))
	{
		write(1, "Erreur de parsing.\n", 19);
		return (1);
	}
	//ft_circlst_printduo("Situation initiale :", &(piles.pa), &(piles.pb));
	ft_sort(&piles, ac - 1, (ac - 1) / 2 + (ac - 1) % 2);
	//ft_circlst_printduo("Resultat :", &(piles.pa), &(piles.pb));
	//ft_piles_print_op(piles, tab_op, 1, 1);
	ft_piles_merge_all_operations(&piles);
	ft_piles_print_op(piles, tab_op, 0, 0);
	ft_cirlst_clear(&(piles.pa));
	ft_cirlst_clear(&(piles.pb));
	ft_cirlst_clear(&(piles.opa));
	ft_cirlst_clear(&(piles.opb));
	ft_cirlst_clear(&(piles.opall));
	return (0);
}
