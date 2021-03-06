/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 09:54:33 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:15:26 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_reset_tab(int *tab, int end)
{
	int	i;

	i = 0;
	while (i < end)
	{
		tab[i] = 0;
		i++;
	}
}
