/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:31:06 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:18:25 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

static long	ret_value(long nb, int s)
{
	if ((nb * s) > INT_MAX)
		return ((long)INT_MIN - 1);
	else if ((nb * s) < INT_MIN)
		return ((long)INT_MIN - 1);
	return (nb * s);
}

long	ft_atoi_ps(const char *str)
{
	int		i;
	long	nb;
	int		s;

	i = 0;
	nb = 0;
	s = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (ret_value(nb, s));
}
