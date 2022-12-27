/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:56:39 by acardona          #+#    #+#             */
/*   Updated: 2022/12/27 21:11:03 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_piles_state	piles;

	piles.pa = 0;
	piles.pb = 0;
	piles.opa = 0;
	piles.opb = 0;
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
	ft_circlst_printduo("Situation initiale :", &(piles.pa), &(piles.pb));
	ft_pile_sort(&(piles.pa), &(piles.pb), ft_circlst_len(piles.pa) / 2 + 1);
	while (piles.pb)
		ft_circlst_push(&(piles.pa), &(piles.pb));
	ft_circlst_printduo("Resultat :", &(piles.pa), &(piles.pb));
	ft_cirlst_clear(&(piles.pa));
	return (0);
}
