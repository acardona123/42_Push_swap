#include "../includes/push_swap.h"

void ft_print_table(t_2int *tab, int len_tab)
{
	int i;

	i = 0;
	ft_printf("Tableau :\n");
	while (i < len_tab)
	{
		ft_printf("\tValeur :%d,\t indexe :%d\n", tab[i].value, tab[i].index);
		i++;
	}
	ft_printf("\n");
}

int main()
{
	t_2int	*tab;

	tab = malloc(4 * sizeof(t_2int));
	if (!tab)
	{
		write(1, "Erreur malloc\n", 14);
		return (1);
	}
	tab[0].value = 40;
	tab[0].index = 0;
	tab[1].value = 20;
	tab[1].index = 1;
	tab[2].value = 30;
	tab[2].index = 2;
	tab[3].value = 10;
	tab[3].index = 3;
	tab[4].value = 50;
	tab[4].index = 4;

	ft_print_table(tab, 5);
	ft_parse_index_table(tab, 5);
	ft_printf("\n\n==========\n");
	ft_print_table(tab, 5);
	return 0;
}