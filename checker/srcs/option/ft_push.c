/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:17:18 by acharras          #+#    #+#             */
/*   Updated: 2021/04/09 16:25:17 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_push_a(t_sorted *sort)
{
	if (sort->max_b > 0)
	{
		sort->stack_a = ft_down_stack(sort->stack_a);
		sort->stack_a[0] = sort->stack_b[0];
		sort->stack_b[0] = 0;
		sort->max_a += 1;
		sort->stack_b = ft_up_stack(sort->stack_b);
		sort->max_b -= 1;
	}
}

void	ft_push_b(t_sorted *sort)
{
	if (sort->max_a > 0)
	{
		sort->stack_b = ft_down_stack(sort->stack_b);
		sort->stack_b[0] = sort->stack_a[0];
		sort->stack_a[0] = 0;
		sort->max_b += 1;
		sort->stack_a = ft_up_stack(sort->stack_a);
		sort->max_a -= 1;
	}
}
