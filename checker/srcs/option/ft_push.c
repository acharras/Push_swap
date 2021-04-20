/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:17:18 by acharras          #+#    #+#             */
/*   Updated: 2021/04/20 13:39:44 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

int	ft_push_a(t_ps *ps)
{
	if (ps->max_b > 0)
	{
		ps->max_a += 1;
		ps->stack_a = ft_down_stack(ps->stack_a, ps->max_a);
		ps->stack_a[0] = ps->stack_b[0];
		ps->stack_b[0] = 0;
		ps->max_b -= 1;
		ps->stack_b = ft_up_stack(ps->stack_b, ps->max_b);
	}
	return (1);
}

int	ft_push_b(t_ps *ps)
{
	if (ps->max_a > 0)
	{
		ps->max_b += 1;
		ps->stack_b = ft_down_stack(ps->stack_b, ps->max_b);
		ps->stack_b[0] = ps->stack_a[0];
		ps->stack_a[0] = 0;
		ps->max_a -= 1;
		ps->stack_a = ft_up_stack(ps->stack_a, ps->max_a);
	}
	return (1);
}

int	ft_push_set_stack(t_ps *ps)
{
	if (ps->max_a > 0)
	{
		ps->set_stack[0][0] = 0;
		ps->set_stack[0][1] = -1;
		ft_up_set_stack(ps);
	}
	return (1);
}