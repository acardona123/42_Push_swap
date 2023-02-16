/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:32:11 by acardona          #+#    #+#             */
/*   Updated: 2023/02/16 20:28:39 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_int_format(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str || *str == 0)
		return (1);
	while (str[i] == '0')
		i++;
	j = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
		j++;
	}
	if (j > 11 || ft_atoi_long(str) > (ssize_t)2147483647
		|| ft_atoi_long(str) < (ssize_t)-2147483648)
		return (1);
	return (0);
}

int	ft_check_atoi(char *str)
{
	size_t	i;

	if (!str || *str == 0)
		return (1);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_double(t_2int **tab, int i_tab, int n)
{
	int	j;

	j = i_tab;
	while (--j > -1)
	{
		if (((*tab)[j]).value == n)
			return (1);
	}
	return (0);
}
