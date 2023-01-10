#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_lstcirc	*top_elemA;
	t_lstcirc	*top_elemB;

	top_elemA = 0;
	top_elemB = 0;
	if (ac < 3)
	{
		write(1, "Nb d'arguments incorrect.\n", 26);
		return (1);
	}
	if (ft_parsing(ac, av, &top_elemA))
	{
		write(1, "Erreur de parsing.\n", 19);
		return (1);
	}
	ft_circlst_printduo("", &top_elemA, &top_elemB);
	ft_circlst_free(&top_elemA);
	return (0);
}
