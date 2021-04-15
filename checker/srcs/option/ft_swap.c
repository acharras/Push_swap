/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:37 by acharras          #+#    #+#             */
/*   Updated: 2021/04/15 14:16:40 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

int	ft_swap_a(t_ps *ps)
{
	int		tmp;
	int		i;

	i = 0;
	if (ps->max_a > 1)
	{
		tmp = ps->stack_a[i + 1];
		ps->stack_a[i + 1] = ps->stack_a[i];
		ps->stack_a[i] = tmp;
	}
	return (1);
}

int	ft_swap_b(t_ps *ps)
{
	int		tmp;
	int		i;

	i = 0;
	if (ps->max_b > 1)
	{
		tmp = ps->stack_b[i + 1];
		ps->stack_b[i + 1] = ps->stack_b[i];
		ps->stack_b[i] = tmp;
	}
	return (1);
}

int	ft_swap_ss(t_ps *ps)
{
	ft_swap_a(ps);
	ft_swap_b(ps);
	return (1);
}
