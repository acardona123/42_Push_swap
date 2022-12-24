/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circlst_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:09:18 by acardona          #+#    #+#             */
/*   Updated: 2022/12/23 22:41:00 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Print a paire of elements of t_lstfuo lists*/
static void	ft_subprintduo(t_lstcirc *elem1, t_lstcirc *elem2)
{
	if (elem1)
	{
		ft_putnbr_fd(elem1->value, 1);
	}
	else
		ft_putchar_fd('\t', 1);
	ft_putstr_fd("\t\t", 1);
	if (elem2)
		ft_putnbr_fd(elem2->value, 1);
	else
		ft_putchar_fd('.', 1);
	ft_putchar_fd('\n', 1);
}

/*Print 2 piles (tops given) next one to another*/
void	ft_circlst_printduo(char *msg, t_lstcirc **lst1, t_lstcirc **lst2)
{
	t_lstcirc	*elem1;
	t_lstcirc	*elem2;

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
		if (!elem2 || elem2->down == *lst1)
			elem2 = 0;
		else
			elem2 = elem2->down;
	}
	ft_putchar_fd('\n', 1);
}
