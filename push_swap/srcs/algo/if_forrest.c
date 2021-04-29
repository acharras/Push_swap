/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_forrest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:11:38 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:11:39 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

static int	forrest_one_next(t_ps *ps, int i)
{
	if (ps->max >= 9)
	{
		i++;
		ft_push_b(ps);
		printf("pb\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
		if (ps->max == 10)
		{
			i++;
			ft_push_b(ps);
			printf("pb\n");
			if (ps->op_v)
				print_stack(ps, 0, 0);
		}
	}
	return (i);
}

int	if_forrest_one(t_ps *ps, int i)
{
	if (ps->max >= 7)
	{
		i++;
		ft_push_b(ps);
		printf("pb\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
		if (ps->max >= 8)
		{
			i++;
			ft_push_b(ps);
			printf("pb\n");
			if (ps->op_v)
				print_stack(ps, 0, 0);
			i = forrest_one_next(ps, i);
		}
	}
	return (i);
}

void	if_forrest_two(t_ps *ps, int i)
{
	if (i >= 4)
	{
		ft_sort_stack_a(ps);
		ft_push_a(ps);
		printf("pa\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
		if (i >= 5)
		{
			ft_sort_stack_a(ps);
			ft_push_a(ps);
			printf("pa\n");
			if (ps->op_v)
				print_stack(ps, 0, 0);
			if (i == 6)
			{
				ft_sort_stack_a(ps);
				ft_push_a(ps);
				printf("pa\n");
				if (ps->op_v)
					print_stack(ps, 0, 0);
			}
		}
	}
}
