/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbesson <pbesson@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:16:18 by pbesson           #+#    #+#             */
/*   Updated: 2020/02/17 18:21:38 by pbesson          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *b, size_t len)
{
	unsigned char *d;

	d = b;
	while (len)
	{
		*d = 0;
		d++;
		len--;
	}
}
