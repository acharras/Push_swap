/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:46:23 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:17:09 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = (char *)ft_malloc(sizeof(char) * (ft_strnlen(str, n) + 1));
	while (n)
	{
		dst[i] = str[i];
		i++;
		n--;
	}
	dst[i] = '\0';
	return (dst);
}
