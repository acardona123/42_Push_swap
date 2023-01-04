/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circlst_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:09:18 by acardona          #+#    #+#             */
/*   Updated: 2022/12/28 16:17:03 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Print a paire of elements of t_lstfuo lists*/
static void	ft_subprintduo(t_lstcirc *elem1, t_lstcirc *elem2)
{
	if (elem1 && elem2)
	{
		ft_printf("%d\t(i = %d)\t\t||\t\t%d\t(i = %d)\n", elem1->value,
			elem1->index, elem2->value, elem2->index);
	}
	else if (elem1)
		ft_printf("%d\t(i = %d)\t\t||\t\t.\t.\n", elem1->value, elem1->index);
	else if (elem2)
		ft_printf(".\t.\t\t||\t\t%d\t(i = %d)\n", elem2->value, elem2->index);
}

/*Print 2 piles (tops given) next one to another*/
void	ft_circlst_printduo(char *msg, t_lstcirc **lst1, t_lstcirc **lst2)
{
	t_lstcirc	*elem1;
	t_lstcirc	*elem2;

	if (msg)
		ft_putendl_fd(msg, 1);
	elem1 = 0;
	elem2 = 0;
	if (lst1)
		elem1 = *lst1;
	if (lst2)
		elem2 = *lst2;
	while (elem1 || elem2)
	{
		ft_subprintduo(elem1, elem2);
		if (!elem1 || elem1->down == *lst1)
			elem1 = 0;
		else
			elem1 = elem1->down;
		if (!elem2 || elem2->down == *lst2)
			elem2 = 0;
		else
			elem2 = elem2->down;
	}
	ft_putchar_fd('\n', 1);
}
