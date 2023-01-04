/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:42:39 by acardona          #+#    #+#             */
/*   Updated: 2022/11/17 11:48:22 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lstbiadd_str(t_listbi **lst_init, char *s, size_t start, size_t len);
int	ft_lstbiadd_arg(va_list *args, t_listbi **lst_init, char c);

static int	ft_isincharset(char c, const char *charset)
{
	size_t	i;

	i = -1;
	while (charset[++i])
		if (charset[i] == c)
			return (1);
	return (0);
}

static int	ft_printf_split(const char *str, va_list *arg, t_listbi **lst_init)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str [i + j] && str[i + j] != '%')
			j++;
		if (j > 0)
			if (ft_lstbiadd_str(lst_init, (char *) str, i, j) == -1)
				return (-1);
		i += j;
		if (str [i])
		{
			i++;
			while (str[i] && ft_isincharset(str[i], "cspdiuxX%") == 0)
				i++;
			if (!str[i] || ft_lstbiadd_arg(arg, lst_init, str[i]) == -1)
				return (ft_lstbiclear(lst_init));
			i++;
		}
	}
	return (0);
}

static int	ft_printf_display(t_listbi **lst_init)
{
	int			n;
	t_listbi	*elem;

	n = 0;
	elem = *lst_init;
	while (elem)
	{
		write(1, elem->content, elem->len);
		n += elem->len;
		elem = elem->next;
	}
	ft_lstbiclear(lst_init);
	return (n);
}

int	ft_printf(const char *str, ...)
{
	t_listbi	**lst_init;
	va_list		arg;
	int			n;

	n = 0;
	lst_init = calloc(1, sizeof(size_t **));
	if (!lst_init)
		return (-1);
	va_start(arg, str);
	if (ft_printf_split(str, &arg, lst_init) == -1)
		return (-1);
	va_end(arg);
	n = ft_printf_display(lst_init);
	return (n);
}
