/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:10:47 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:10:48 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

float	ft_sqrt(int nb)
{
	float	tmp;
	float	sqrt;

	tmp = 0;
	sqrt = nb / 2;
	if (nb > 2147395600)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	if (nb < 0)
		return (0);
	while (sqrt != tmp)
	{
		tmp = sqrt;
		sqrt = (nb / tmp + tmp) / 2;
	}
	return (sqrt);
}
