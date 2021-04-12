/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:27:12 by acharras          #+#    #+#             */
/*   Updated: 2021/04/12 14:37:00 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

void	ft_rotate_a(t_ps *ps)
{
	int temp;

	temp = ps->stack_a[0];
	ps->stack_a = ft_up_stack(ps->stack_a);
	ps->stack_a[ps->max_a] = temp;
}

void	ft_rotate_b(t_ps *ps)
{
	int temp;

	temp = ps->stack_b[0];
	ps->stack_b = ft_up_stack(ps->stack_b);
	ps->stack_b[ps->max_b] = temp;
}

void	ft_rotate_rr(t_ps *ps)
{
	ft_rotate_a(ps);
	ft_rotate_b(ps);
}