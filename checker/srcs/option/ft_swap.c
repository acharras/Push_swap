/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:37 by acharras          #+#    #+#             */
/*   Updated: 2021/04/09 16:24:58 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_swap_a(t_sorted *sort)
{
	char	*tmp;
	int		i;

	i = 0;
	if (sort->max_a > 1)
	{
		tmp = sort->stack_a[i + 1];
		sort->stack_a[i + 1] = sort->stack_a[i];
		sort->stack_a[i] = tmp;
	}
}

void	ft_swap_b(t_sorted *sort)
{
	char	*tmp;
	int		i;

	i = 0;
	if (sort->max_b > 1)
	{
		tmp = sort->stack_b[i + 1];
		sort->stack_b[i + 1] = sort->stack_b[i];
		sort->stack_b[i] = tmp;
	}
}

void	ft_swap_ss(t_sorted *sort)
{
	ft_swap_a(sort);
	ft_swap_b(sort);
}