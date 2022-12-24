/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_arg0.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:50:33 by acardona          #+#    #+#             */
/*   Updated: 2022/11/15 19:10:06 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_ctoa(t_listbi **lst_init, int c);
int	ft_printf_stos(t_listbi **lst_init, char *str);
int	ft_printf_itoa(t_listbi **lst_init, int n);
int	ft_printf_percent(t_listbi **lst_init);
int	ft_printf_utoa(t_listbi **lst_init, unsigned int n);
int	ft_printf_ptoa(t_listbi **lst_init, void *ptr);
int	ft_printf_itoxa(t_listbi **lst_init, int num, int hexcapital);

int	ft_lstbiadd_arg(va_list *args, t_listbi **lst_init, char c)
{
	if (c == 'c')
		return (ft_printf_ctoa(lst_init, va_arg(*args, int)));
	else if (c == 's')
		return (ft_printf_stos(lst_init, va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_printf_ptoa(lst_init, va_arg(*args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_printf_itoa(lst_init, va_arg(*args, int)));
	else if (c == 'u')
		return (ft_printf_utoa(lst_init, va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (ft_printf_itoxa(lst_init, va_arg(*args, int), 0));
	else if (c == 'X')
		return (ft_printf_itoxa(lst_init, va_arg(*args, int), 1));
	else if (c == '%')
		return (ft_printf_percent(lst_init));
	else
		return (ft_lstbiclear(lst_init));
}
