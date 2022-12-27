/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:56:39 by acardona          #+#    #+#             */
/*   Updated: 2022/12/27 17:08:38 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_lstcirc	*top_a;
	t_lstcirc	*top_b;

	top_a = 0;
	top_b = 0;
	if (ac < 3)
	{
		write(1, "Nb d'arguments incorrect.\n", 26);
		return (1);
	}
	if (ft_parsing(ac, av, &top_a))
	{
		write(1, "Erreur de parsing.\n", 19);
		return (1);
	}
	ft_circlst_printduo("Situation initiale :", &top_a, &top_b);
	ft_pile_sort(&top_a, &top_b, ft_circlst_len(top_a) / 2 + 1);
	while (top_b)
		ft_circlst_push(&top_a, &top_b);
	ft_circlst_printduo("Resultat :", &top_a, &top_b);
	ft_cirlst_clear(&top_a);
	return (0);
}
