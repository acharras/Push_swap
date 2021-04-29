/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:34:26 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:17:04 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		l;
	size_t		lmalloc;
	char		*str;

	i = 0;
	l = ft_strlen(s);
	if ((start >= l) || (len == 0))
		return (ft_calloc(sizeof(char), 1));
	if (start - l < len)
		lmalloc = start - l;
	else
		lmalloc = len;
	str = (char *)ft_calloc(sizeof(char), lmalloc + 1);
	while (len--)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	return (str);
}
