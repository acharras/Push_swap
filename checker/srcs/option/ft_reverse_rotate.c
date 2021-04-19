/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:17:08 by acharras          #+#    #+#             */
/*   Updated: 2021/04/19 17:09:36 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

int	ft_reverse_rotate_a(t_ps *ps)
{
	int	temp;

	temp = ps->stack_a[ps->max_a - 1];
	ps->stack_a = ft_down_stack(ps->stack_a, ps->max_a);
	ps->stack_a[0] = temp;
	return (1);
}

int	ft_reverse_rotate_set_stack(t_ps *ps)
{
	int	temp1;
	int	temp2;

	temp1 = ps->set_stack[ps->max_a - 1][0];
	temp2 = ps->set_stack[ps->max_a - 1][1];
	ps->set_stack = ft_down_set_stack(ps->set_stack, ps->max_a);
	ps->set_stack[0][0] = temp1;
	ps->set_stack[0][1] = temp2;
	return (1);
}

int	ft_reverse_rotate_b(t_ps *ps)
{
	int	temp;

	temp = ps->stack_b[ps->max_b - 1];
	ps->stack_b = ft_down_stack(ps->stack_b, ps->max_b);
	ps->stack_b[0] = temp;
	return (1);
}

int	ft_reverse_rotate_rr(t_ps *ps)
{
	ft_reverse_rotate_a(ps);
	ft_reverse_rotate_b(ps);
	return (1);
}
