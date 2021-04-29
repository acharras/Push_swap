/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:51:28 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:13:20 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strnlen(const char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (str[i] && i < n)
		i++;
	return (i);
}
