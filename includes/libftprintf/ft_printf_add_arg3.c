/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:35:07 by acardona          #+#    #+#             */
/*   Updated: 2022/11/15 18:05:28 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_neg_binary_hex(int nb)
{
	char			*str;
	int				i;
	unsigned int	n;

	str = malloc(33 * sizeof(char));
	if (!str)
		return (NULL);
	n = -1 * nb;
	str[32] = 0;
	i = 32;
	while (--i >= 0)
	{
		str[i] = n % 2 + '0';
		n /= 2;
	}
	while (str[++i])
		str[i] = -1 * (str[i] - '0') + 1 + '0';
	while (str[--i] == '1')
		str[i] = '0';
	str[i] = '1';
	return (str);
}

static void	ft_neg_itoxa(char *bin, char *hexbase, char **dest)
{
	int	i;
	int	n;

	*dest = malloc(9 * sizeof(char));
	if ((*dest))
	{
		(*dest)[8] = 0;
		i = 0;
		while (i < 32)
		{
			n = bin[i] - '0';
			i++;
			while (i % 4 != 0)
			{
				n = n * 2 + bin[i] - '0';
				i++;
			}
			(*dest)[i / 4 - 1] = hexbase[n];
		}
	}
}

static void	ft_pos_itoxa(int num, char *hexbase, char **dest)
{
	int		numcpy;
	int		i;

	numcpy = num;
	i = 1;
	while (numcpy / 16 != 0)
	{
		numcpy /= 16;
		i++;
	}
	*dest = malloc((i + 1) * sizeof(char));
	if ((*dest))
	{
		(*dest)[i] = 0;
		i--;
		while (num / 16)
		{
			(*dest)[i] = hexbase[num % 16];
			num /= 16;
			i--;
		}
		(*dest)[i] = hexbase[num % 16];
	}
}

int	ft_printf_itoxa(t_listbi **lst_init, int num, int hexcapital)
{
	char	*result;
	char	*bin;

	if (num < 0)
	{
		bin = ft_neg_binary_hex(num);
		if (!bin)
			return (ft_lstbiclear(lst_init));
		if (hexcapital == 0)
			ft_neg_itoxa(bin, "0123456789abcdef", &result);
		else
			ft_neg_itoxa(bin, "0123456789ABCDEF", &result);
		free(bin);
	}
	else
	{
		if (hexcapital == 0)
			ft_pos_itoxa(num, "0123456789abcdef", &result);
		else
			ft_pos_itoxa(num, "0123456789ABCDEF", &result);
	}
	return (ft_lstbiaddnewelem(lst_init, result, ft_strlen(result)));
}
