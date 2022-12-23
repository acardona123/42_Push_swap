#include "../includes/push_swap.h"

void ft_print_table(t_2int *tab, int len_tab)
{
	int i;

	i = 0;
	printf("Tableau :\n");
	while (i < len_tab)
	{
		printf("\tValeur :%d,\t indexe :%d\n", tab[i].value, tab[i].index);
		i++;
	}
	printf("\n");
}
