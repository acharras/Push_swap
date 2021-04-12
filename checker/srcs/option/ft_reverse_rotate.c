/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurbuche <aurbuche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:17:08 by acharras          #+#    #+#             */
/*   Updated: 2021/04/12 16:54:31 by aurbuche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

int	ft_reverse_rotate_a(t_ps *ps)
{
	int	temp;

	temp = ps->stack_a[ps->max_a];
	ps->stack_a = ft_down_stack(ps->stack_a);
	ps->stack_a[0] = temp;
	return (1);
}

int	ft_reverse_rotate_b(t_ps *ps)
{
	int	temp;

	temp = ps->stack_b[ps->max_b];
	ps->stack_b = ft_down_stack(ps->stack_b);
	ps->stack_b[0] = temp;
	return (1);
}

int	ft_reverse_rotate_rr(t_ps *ps)
{
	ft_reverse_rotate_a(ps);
	ft_reverse_rotate_b(ps);
	return (1);
}
