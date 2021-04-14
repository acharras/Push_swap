/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurbuche <aurbuche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:37 by acharras          #+#    #+#             */
/*   Updated: 2021/04/14 14:23:18 by aurbuche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_swap_a(t_ps *ps)
{
	char	*tmp;
	int		i;

	i = 0;
	if (ps->max > 1)
	{
		tmp = ps->stack_a[i + 1];
		ps->stack_a[i + 1] = ps->stack_a[i];
		ps->stack_a[i] = tmp;
		printf("sa\n");
	}
}

void	ft_swap_b(t_ps *ps)
{
	char	*tmp;
	int		i;

	i = 0;
	if (ps->max > 1)
	{
		tmp = ps->stack_b[i + 1];
		ps->stack_b[i + 1] = ps->stack_b[i];
		ps->stack_b[i] = tmp;
		printf("sb\n");
	}
}
