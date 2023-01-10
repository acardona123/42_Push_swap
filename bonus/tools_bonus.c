/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:56:45 by acardona          #+#    #+#             */
/*   Updated: 2023/01/09 21:02:00 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strdiff(char *str1, char *str2)
{
	if ((!str1 && str2) || (str1 && !str2))
		return (1);
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (1);
		str1++;
		str2++;
	}
	if (*str1 != *str2)
		return (1);
	return (0);
}
