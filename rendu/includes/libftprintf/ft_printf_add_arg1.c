/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_arg1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:32:39 by acardona          #+#    #+#             */
/*   Updated: 2022/11/16 15:40:39 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_ctoa(t_listbi **lst_init, int c)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (!str)
		return (ft_lstbiclear(lst_init));
	str[0] = c;
	str[1] = '\0';
	return (ft_lstbiaddnewelem(lst_init, str, 1));
}

int	ft_printf_percent(t_listbi **lst_init)
{
	char	*str;

	str = malloc(2 * sizeof(char));
	if (!str)
		return (ft_lstbiclear(lst_init));
	str[0] = '%';
	str[1] = 0;
	return (ft_lstbiaddnewelem(lst_init, str, 1));
}

int	ft_printf_stos(t_listbi **lst_init, char *str)
{
	char	*str_dup;

	if (!str)
		str_dup = ft_strdup("(null)");
	else
		str_dup = ft_strdup(str);
	if (!str_dup)
		return (ft_lstbiclear(lst_init));
	return (ft_lstbiaddnewelem(lst_init, str_dup, ft_strlen(str_dup)));
}

int	ft_printf_itoa(t_listbi **lst_init, int n)
{
	char	*str;

	str = NULL;
	str = ft_itoa(n);
	if (!str)
		return (ft_lstbiclear(lst_init));
	return (ft_lstbiaddnewelem(lst_init, str, ft_strlen(str)));
}
