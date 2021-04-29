/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:11:52 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:11:52 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

void	find_max_b(t_ps *ps, int i)
{
	ps->bigger = ps->stack_b[0];
	while (i < ps->max_b)
	{
		if (ps->stack_b[i] > ps->bigger)
		{
			ps->bigger = ps->stack_b[i];
			ps->rank = i;
		}
		i++;
	}
}

void	find_max_a(t_ps *ps, int i)
{
	ps->bigger = ps->stack_a[0];
	while (i < ps->max_a)
	{
		if (ps->stack_a[i] > ps->bigger)
		{
			ps->bigger = ps->stack_a[i];
			ps->rank = i;
		}
		i++;
	}
}
