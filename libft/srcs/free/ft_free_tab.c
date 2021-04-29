/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 09:23:03 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:15:31 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_delete(&tab[i]);
		i++;
	}
	free(tab);
}
