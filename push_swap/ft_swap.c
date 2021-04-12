/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:37 by acharras          #+#    #+#             */
/*   Updated: 2021/04/06 16:04:05 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_swap_a(t_sorted *sort)
{
	char	*tmp;
	int		i;

	i = 0;
	if (sort->max > 1)
	{
		tmp = sort->stack_a[i + 1];
		sort->stack_a[i + 1] = sort->stack_a[i];
		sort->stack_a[i] = tmp;
		printf("sa\n");
	}
}

void	ft_swap_b(t_sorted *sort)
{
	char	*tmp;
	int		i;

	i = 0;
	if (sort->max > 1)
	{
		tmp = sort->stack_b[i + 1];
		sort->stack_b[i + 1] = sort->stack_b[i];
		sort->stack_b[i] = tmp;
		printf("sb\n");
	}
}
