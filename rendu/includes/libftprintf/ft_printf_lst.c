/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:56:57 by acardona          #+#    #+#             */
/*   Updated: 2022/11/17 11:47:12 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_listbi	*ft_lstbinew(void *content, int n)
{
	t_listbi	*new;

	new = malloc(sizeof(t_listbi));
	if (!new)
		return (NULL);
	new->content = content;
	new->len = n;
	new->next = NULL;
	return (new);
}

void	ft_lstbiadd_back(t_listbi **lst, t_listbi *new)
{
	t_listbi	*elem;

	if (lst)
	{
		elem = *lst;
		if (!elem)
			*lst = new;
		else
		{
			while (elem->next)
				elem = elem->next;
			elem->next = new;
		}
	}
}

int	ft_lstbiclear(t_listbi **lst)
{
	t_listbi	*pelem;
	t_listbi	*pnext;

	if (lst)
	{
		pelem = *lst;
		while (pelem)
		{
			free(pelem->content);
			pnext = pelem->next;
			free(pelem);
			pelem = pnext;
		}
		*lst = NULL;
	}
	free(lst);
	return (-1);
}

int	ft_lstbiaddnewelem(t_listbi **lst_init, char *str, int len)
{
	t_listbi	*elem;

	elem = ft_lstbinew((void *)str, len);
	if (!elem)
	{
		free(str);
		ft_lstbiclear(lst_init);
		return (-1);
	}
	ft_lstbiadd_back(lst_init, elem);
	return (0);
}
