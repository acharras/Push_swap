/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:37 by acharras          #+#    #+#             */
/*   Updated: 2021/03/08 15:39:54 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_swap_a(t_sorted *sort, char **push)
{
	int		tmp;
	int		i;

	i = 0;
	if (sort->max > 1)
	{
		tmp = push[i + 1];
		push[i + 1] = push[i];
		push[i] = tmp;
	}
}

void	ft_swap_b(t_sorted *sort, char **push)
{
	int		tmp;
	int		i;

	i = 0;
	if (sort->max > 1)
	{
		tmp = push[i + 1];
		push[i + 1] = push[i];
		push[i] = tmp;
	}
}
