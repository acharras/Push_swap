/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:03:51 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:14:56 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*d;

	d = b;
	while (len)
	{
		*d = c;
		d++;
		len--;
	}
	return (b);
}
