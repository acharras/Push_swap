/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:48:07 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:14:19 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	len;

	len = ft_strlen(dst);
	i = 0;
	if (len > size)
		return (ft_strlen(src) + size);
	while (src[i] && size - len > 1)
	{
		dst[len + i] = src[i];
		size--;
		i++;
	}
	dst[len + i] = '\0';
	return (ft_strlen(src) + len);
}
