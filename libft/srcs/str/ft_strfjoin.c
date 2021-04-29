/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 09:08:26 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:14:26 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strfjoin(char *s1, char *s2, int free)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (!str)
		return (0);
	if (free == 1)
		ft_delete(&s1);
	else if (free == 2)
		ft_delete(&s2);
	else if (free == 3)
	{
		ft_delete(&s1);
		ft_delete(&s2);
	}
	return (str);
}
