#include "../includes/push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_piles_state	piles;
	char			*tab_op[11];

	ft_piles_and_tab_init(&piles, tab_op);
	if (ac < 3)
	{
		write(1, "Nb d'arguments incorrect.\n", 26);
		return (1);
	}
	if (ft_parsing(ac, av, &(piles.opa)))
	{
		write(1, "Erreur de parsing.\n", 19);
		return (1);
	}
	ft_circlst_printduo("Init :", &piles.opa, 0);
	ft_piles_delete_consecutive_op_one(&piles.opa);
	ft_circlst_printduo("Apres :", &piles.opa, 0);
	ft_cirlst_clear(&piles.opa);
	return (0);
}
