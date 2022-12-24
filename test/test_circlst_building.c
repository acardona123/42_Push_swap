#include "../includes/push_swap.h"

int main()
{
	int			tab[10];
	int			i;
	t_lstcirc	*lst_top;
	t_lstcirc	*elem;
	t_lstcirc	*new;
	t_lstcirc	*new1;

	if (0) //Construction manuelle d'une liste a trois elements
	{
		write(1, "Cas avec contruction manuelle :\n", 32);
		elem = ft_circlst_new_elem(10, 0);//pas de verif malloc
		new = ft_circlst_new_elem(8, 0);//idem
		ft_circlst_addabove(&elem, new);
		new1 = ft_circlst_new_elem(2, 0);//idem
		ft_circlst_addabove(&elem, new1);
		// if (0)
		// {
		// 	printf("Top (%p):\n -value : %d\n -up : %p\n -down : %p\n\n", elem, elem->value, elem->up, elem->down);
		// 	printf("Middle (%p):\n -value : %d\n -up : %p\n -down : %p\n\n", elem->down, elem->down->value, elem->down->up, elem->down->down);
		// 	printf("Bottom (%p):\n -value : %d\n -up : %p\n -down : %p\n\n", elem->up, elem->up->value, elem->up->up, elem->up->down);
		// }
		ft_circlst_printduo("", &elem, 0);
		ft_cirlst_clear(&elem);
	}
	if (1)
	{
		lst_top = 0;
		i = -1;
		while (++i < 9)
			tab[i] = i + 1;
		tab[9] = 0;
		i = 0;
		while (tab[i])
		{
			new = ft_circlst_new_elem(tab[i], i);
			if (ft_circlst_addabove(&lst_top, new))
			{
				ft_cirlst_clear(&lst_top);
				ft_putstr_fd("/!\\ Pb => liste free", 1);
				return (1);
			}
			printf("Element %d:\n -Address : %p\n -value : %d\n -up : %p\n -down : %p\n\n", i, new, new->value, new->up, new->down);
			i++;
		}
		printf("=== First :\n\n -Address : %p\n -value : %d\n -up : %p\n -down : %p\n\n", lst_top, lst_top->value, lst_top->up, lst_top->down);
		write(1, "\n-----\n", 7);
		ft_circlst_printduo("", &lst_top, 0);
		printf("===\nNombre d'elements : %d\n", ft_circlst_len(lst_top));
		ft_cirlst_clear(&lst_top);
	}
}
