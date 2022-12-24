#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_lstcirc	*top_a;
	t_lstcirc	*top_b;

	top_a = 0;
	top_b = 0;
	if (ac < 2)
	{
		write(1, "Nb d'arguments incorrect.\n", 26);
		return (1);
	}
	if (ft_parsing(ac, av, &top_a))
	{
		write(1, "Erreur de parsing.\n", 19);
		return (1);
	}
	ft_parsing(ac, av, &top_b);
	top_b = top_b->down->down->down;
	ft_circlst_printduo("Init :", &top_a, &top_b);
	if (1) //sa
	{
		ft_circlst_swap2(&top_a, &top_b);
		ft_circlst_printduo("ss", &top_a, &top_b);
		ft_circlst_swap2(&top_a, &top_b);
		ft_circlst_printduo("ss", &top_a, &top_b);
	}
	if (1) //pb
	{
		ft_circlst_push(&top_b, &top_a);
		ft_circlst_printduo("pb", &top_a, &top_b);
		ft_circlst_push(&top_a, &top_b);
		ft_circlst_printduo("pa", &top_a, &top_b);
	}
	if (1) //ra et rra
	{
		ft_circlst_rotate2(&top_a, &top_b);
		ft_circlst_printduo("rr", &top_a, &top_b);
		ft_circlst_rev_rotate2(&top_a, &top_b);
		ft_circlst_printduo("rrr", &top_a, &top_b);
	}
	ft_cirlst_clear(&top_a);
	ft_cirlst_clear(&top_b);
	return (0);
}
