/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:17:08 by acharras          #+#    #+#             */
/*   Updated: 2021/04/12 14:37:03 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

void	ft_reverse_rotate_a(t_ps *ps)
{
	int temp;

	temp = ps->stack_a[ps->max_a];
	ps->stack_a = ft_down_stack(ps->stack_a);
	ps->stack_a[0] = temp;
}

void	ft_reverse_rotate_b(t_ps *ps)
{
	int temp;

	temp = ps->stack_b[ps->max_b];
	ps->stack_b = ft_down_stack(ps->stack_b);
	ps->stack_b[0] = temp;
}

void	ft_reverse_rotate_rr(t_ps *ps)
{
	ft_reverse_rotate_a(ps);
	ft_reverse_rotate_b(ps);
}