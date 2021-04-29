/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:34:03 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:15:15 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (src == NULL && dst == NULL && n != 0)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n)
	{
		*d = *s;
		if (*s == (unsigned char)c)
			return (d + 1);
		s++;
		d++;
		n--;
	}
	return (0);
}
