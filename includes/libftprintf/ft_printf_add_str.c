/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:14:35 by acardona          #+#    #+#             */
/*   Updated: 2022/11/17 11:47:17 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lstbiadd_str(t_listbi **lst_init, char *str, size_t start, size_t len)
{
	char	*sub_str;

	sub_str = ft_substr(str, (unsigned int) start, len);
	if (!sub_str)
		return (ft_lstbiclear(lst_init));
	return (ft_lstbiaddnewelem(lst_init, sub_str, ft_strlen(sub_str)));
}
