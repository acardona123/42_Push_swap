#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_piles_state	piles;
	char			*tab_op[11];

	if (ac < 2)
	{
		write(1, "Nb d'arguments incorrect.\n", 26);
		return (1);
	}
	ft_piles_and_tab_init(&piles, tab_op);

	if (ft_parsing(ac, av, &(piles.pa)))
	{
		write(1, "Erreur de parsing.\n", 19);
		return (1);
	}
	ft_parsing(ac, av, &(piles.pb));
	piles.pb = piles.pb->down->down->down;
	ft_circlst_printduo("Init :", &(piles.pa), &(piles.pb));


	/*individual op testing*/
	if (1)
	{
		if (0) //pa
		{
			ft_piles_add_op(&piles, 0);
			ft_piles_print_op_long(piles, tab_op, 1, 1);
			ft_circlst_printduo("pa :", &(piles.pa), &(piles.pb));
		}
		if (1) //sa
		{
			ft_piles_add_op(&piles, 1);
			ft_piles_print_op_long(piles, tab_op, 1, 1);
			// ft_piles_do_all_operations(&piles);
			// ft_piles_print_op_long(piles, tab_op, 1, 1);
			ft_printf("Premier index : %d\n", piles.pa->index);
			ft_circlst_printduo("sa :", &(piles.pa), &(piles.pb));
		}
		if (0) //ra
		{
			ft_piles_add_op(&piles, 2);
			ft_piles_print_op_long(piles, tab_op, 1, 1);
			// ft_piles_do_all_operations(&piles);
			// ft_piles_print_op_long(piles, tab_op, 1, 1);
			ft_circlst_printduo(0, &(piles.pa), &(piles.pb));
		}
		if (0) //rra
		{
			ft_piles_add_op(&piles, 3);
			ft_piles_print_op_long(piles, tab_op, 1, 1);
			// ft_piles_do_all_operations(&piles);
			// ft_piles_print_op_long(piles, tab_op, 1, 1);
			ft_circlst_printduo(0, &(piles.pa), &(piles.pb));
		}
		if (0) //pb
		{
			ft_piles_add_op(&piles, 4);
			ft_piles_print_op_long(piles, tab_op, 1, 1);
			ft_circlst_printduo("pb :", &(piles.pa), &(piles.pb));
		}
		if (0) //sb
		{
			ft_piles_add_op(&piles, 5);
			ft_piles_print_op_long(piles, tab_op, 1, 1);
			// ft_piles_do_all_operations(&piles);
			// ft_piles_print_op_long(piles, tab_op, 1, 1);
			ft_circlst_printduo("sa :", &(piles.pa), &(piles.pb));
		}
		if (0) //rb
		{
			ft_piles_add_op(&piles, 6);
			ft_piles_print_op_long(piles, tab_op, 1, 1);
			// ft_piles_do_all_operations(&piles);
			// ft_piles_print_op_long(piles, tab_op, 1, 1);
			ft_circlst_printduo(0, &(piles.pa), &(piles.pb));
		}
		if (0) //rrb
		{
			ft_piles_add_op(&piles, 7);
			ft_piles_print_op_long(piles, tab_op, 1, 1);
			// ft_piles_do_all_operations(&piles);
			// ft_piles_print_op_long(piles, tab_op, 1, 1);
			ft_circlst_printduo(0, &(piles.pa), &(piles.pb));
		}
		if (0) //ss
		{
			ft_piles_add_op(&piles, 1);
			ft_piles_add_op(&piles, 5);
			ft_piles_print_op_long(piles, tab_op, 1, 1);
			// ft_piles_do_one_operation(&piles, 8);
			// ft_piles_print_op_long(piles, tab_op, 1, 1);
			ft_circlst_printduo(0, &(piles.pa), &(piles.pb));
		}
		if (0) //rr
		{
			ft_piles_add_op(&piles, 2);
			ft_piles_add_op(&piles, 6);
			ft_piles_print_op_long(piles, tab_op, 1, 1);
			ft_piles_do_one_operation(&piles, 9);
			ft_piles_print_op_long(piles, tab_op, 1, 1);
			ft_circlst_printduo(0, &(piles.pa), &(piles.pb));
		}
		if (0) //rrr
		{
			ft_piles_add_op(&piles, 3);
			ft_piles_add_op(&piles, 7);
			ft_piles_print_op_long(piles, tab_op, 1, 1);
			ft_piles_do_one_operation(&piles, 10);
			ft_piles_print_op_long(piles, tab_op, 1, 1);
			ft_circlst_printduo(0, &(piles.pa), &(piles.pb));
		}
	}
	
	/*Multiple op testing*/
	if (0)
	{
		ft_piles_add_op(&piles, 1);
		ft_piles_add_op(&piles, 2);
		ft_piles_add_op(&piles, 2);
		ft_piles_add_op(&piles, 1);

		ft_piles_add_op(&piles, 6);
		ft_piles_add_op(&piles, 6);
		ft_piles_add_op(&piles, 6);
		ft_piles_add_op(&piles, 5);

		ft_piles_print_op_long(piles, tab_op, 1, 1);
		ft_piles_add_op(&piles, 0);
		ft_circlst_printduo("Resultat :", &(piles.pa), &(piles.pb));
		ft_piles_print_op_long(piles, tab_op, 1, 1);
	}

	ft_cirlst_clear(&(piles.pa));
	ft_cirlst_clear(&(piles.pb));
	ft_cirlst_clear(&(piles.opa));
	ft_cirlst_clear(&(piles.opb));
	ft_cirlst_clear(&(piles.opall));
	return (0);
}
