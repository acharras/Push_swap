/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:47:51 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:17:15 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strdup(const char *s1)
{
	char		*dst;
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen(s1);
	dst = (char *)ft_calloc(sizeof(char), len + 1);
	ft_memcpy(dst, s1, len);
	return (dst);
}
