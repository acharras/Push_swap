/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:30:23 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:15:04 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (src == NULL && dst == NULL && n != 0)
		return (NULL);
	d = dst;
	s = src;
	while (n)
	{
		*d = *s;
		s++;
		d++;
		n--;
	}
	return (dst);
}
