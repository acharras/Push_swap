/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:17:18 by acharras          #+#    #+#             */
/*   Updated: 2021/04/12 17:12:16 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

int		ft_push_a(t_ps *ps)
{
	if (ps->max_b > 0)
	{
		ps->max_a += 1;
		ps->stack_a = ft_down_stack(ps->stack_a, ps->max_a);
		ps->stack_a[0] = ps->stack_b[0];
		ps->stack_b[0] = 0;
		ps->stack_b = ft_up_stack(ps->stack_b, ps->max_b);
		ps->max_b -= 1;
	}
	return (1);
}

int		ft_push_b(t_ps *ps)
{
	if (ps->max_a > 0)
	{
		ps->max_b += 1;
		ps->stack_b = ft_down_stack(ps->stack_b, ps->max_b);
		ps->stack_b[0] = ps->stack_a[0];
		ps->stack_a[0] = 0;
		ps->stack_a = ft_up_stack(ps->stack_a, ps->max_a);
		ps->max_a -= 1;
	}
	return (1);
}
