/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:26:48 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:16:08 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_itoa(int n)
{
	static char	buf[12] = {0};
	int			i;
	int			neg;

	i = 10;
	neg = 1;
	if (n == INT_MIN)
		return (ft_strdup(STR_INT_MIN));
	if (n < 0)
	{
		neg = -1;
		n = -n;
	}
	while (1)
	{
		buf[i--] = n % 10 + '0';
		n /= 10;
		if (n == 0)
			break ;
	}
	if (neg == -1)
		buf[i] = '-';
	if (neg == -1)
		return (ft_strdup(buf + i));
	return (ft_strdup(buf + 1 + i));
}
