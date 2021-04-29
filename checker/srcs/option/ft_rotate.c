/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:27:12 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:18:46 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

int	ft_rotate_a(t_ps *ps)
{
	int	temp;

	temp = ps->stack_a[0];
	ps->stack_a = ft_up_stack(ps->stack_a, ps->max_a);
	ps->stack_a[ps->max_a - 1] = temp;
	return (1);
}

int	ft_rotate_set_stack(t_ps *ps)
{
	ft_up_set_stack(ps);
	return (1);
}

int	ft_rotate_b(t_ps *ps)
{
	int	temp;

	temp = ps->stack_b[0];
	ps->stack_b = ft_up_stack(ps->stack_b, ps->max_b);
	ps->stack_b[ps->max_b - 1] = temp;
	return (1);
}

int	ft_rotate_rr(t_ps *ps)
{
	ft_rotate_a(ps);
	ft_rotate_b(ps);
	return (1);
}
