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
	ft_circlst_printduo("Init :", &top_a, &top_b);
	
	if (0) //sa
	{
		ft_circlst_swap(&top_a);
		ft_circlst_printduo("sa", &top_a, &top_b);
	}
	if (1) //pb
	{
		ft_parsing(ac, av, &top_b);
		top_b = top_b->down;
		printf("top :\t%p\nlast :\t%p\nlast->up :\t%p\n\n", top_b, top_b->up, top_b->up->down);


/*quefa ce foutu print qui n'affiche pas bien la liste !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/


		//ft_circlst_push(&top_b, &top_a);
		ft_circlst_printduo("pb", &top_a, &(top_a->up));

		// ft_circlst_push(&top_b, &top_a);
		// ft_circlst_printduo("pb", &top_a, &top_b);
	}
	if (0) //ra
	{
		ft_circlst_printduo("ra", &top_a, &top_b);
	}

	ft_cirlst_clear(&top_a);
	return (0);
}