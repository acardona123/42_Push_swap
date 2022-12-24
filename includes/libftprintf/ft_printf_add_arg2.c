/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_arg2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:32:39 by acardona          #+#    #+#             */
/*   Updated: 2022/11/17 12:45:04 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lutoa_count(long unsigned int n, int lenbase)
{
	int	i;

	i = 1;
	while (n / lenbase != 0)
	{
		n /= lenbase;
		i++;
	}
	return (i);
}

int	ft_printf_utoa(t_listbi **lst_init, unsigned int n)
{
	int		len;
	char	*str;

	len = ft_lutoa_count((long unsigned int) n, 10);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (ft_lstbiclear(lst_init));
	str[len] = 0;
	while (len > 0)
	{
		str[len - 1] = '0' + n % 10;
		n /= 10;
		len--;
	}
	return (ft_lstbiaddnewelem(lst_init, str, ft_strlen(str)));
}

int	ft_printf_ptoa(t_listbi **lst_init, void *ptr)
{
	char				*dest;
	long unsigned int	num_adress;
	int					i;

	if (!ptr)
	{
		dest = ft_strdup("(nil)");
		return (ft_lstbiaddnewelem(lst_init, dest, 5));
	}
	num_adress = (long unsigned int) ptr;
	i = ft_lutoa_count(num_adress, 16) + 2;
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (ft_lstbiclear(lst_init));
	dest[0] = '0';
	dest[1] = 'x';
	dest[i--] = 0;
	while (num_adress / 16)
	{
		dest[i] = "0123456789abcdef"[num_adress % 16];
		num_adress /= 16;
		i--;
	}
	dest[i] = "0123456789abcdef"[num_adress % 16];
	return (ft_lstbiaddnewelem(lst_init, dest, ft_strlen(dest)));
}
