/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:01:46 by acardona          #+#    #+#             */
/*   Updated: 2023/01/04 18:10:59 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(char c)
{
	int	i;

	i = 0;
	while (" \f\n\r\t\v"[i])
		if (c == " \f\n\r\t\v"[i++])
			return (1);
	return (0);
}

ssize_t	ft_atoi_long(const char *nptr)
{
	ssize_t	nb;
	int		neg;
	int		i;
	int		j;

	if (!nptr)
		return (0);
	neg = 1;
	nb = 0;
	i = 0;
	while (ft_iswhitespace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	j = -1;
	while (nptr[i] && ft_isdigit(nptr[i]) && ++j < 20)
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	return (neg * nb);
}
