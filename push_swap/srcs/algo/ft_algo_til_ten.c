/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_til_ten.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:11:41 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:11:42 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

static int	pb_necessary(t_ps *ps, int i)
{
	if (ps->max >= 4)
	{
		ft_push_b(ps);
		printf("pb\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
		if (ps->max >= 5)
		{
			i++;
			ft_push_b(ps);
			printf("pb\n");
			if (ps->op_v)
				print_stack(ps, 0, 0);
			if (ps->max >= 6)
			{
				i++;
				ft_push_b(ps);
				printf("pb\n");
				if (ps->op_v)
					print_stack(ps, 0, 0);
				i = if_forrest_one(ps, i);
			}
		}
	}
	return (i);
}

int	check_order_loop(t_ps *ps, int i, int prev)
{
	while (i < ps->max)
	{
		if (prev >= ps->stack_a[i])
		{
			return (0);
		}
		prev = ps->stack_a[i];
		i++;
	}
	return (1);
}

int	check_order(t_ps *ps)
{
	int	i;
	int	prev;

	i = 1;
	prev = ps->stack_a[0];
	if (ps->max_b)
	{
		return (0);
	}
	if (!check_order_loop(ps, i, prev))
		return (0);
	return (1);
}

void	ft_algo_til_ten(t_ps *ps)
{
	int	i;

	i = 0;
	i = pb_necessary(ps, i);
	ft_algo_three(ps);
	if (ps->max >= 4)
	{
		ft_sort_stack_a(ps);
		ft_push_a(ps);
		printf("pa\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
		pa_til_end(ps, i);
	}
}
