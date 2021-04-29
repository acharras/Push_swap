/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:11:58 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:11:59 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

static void	sort_a_next(t_ps *ps, int i)
{
	if (ps->save_max > ps->stack_b[0])
	{
		ps->save_sup = ps->save_max;
		while (++i < ps->max_a)
		{
			if (ps->stack_a[i] > ps->stack_b[0]
				&& ps->save_max > ps->stack_a[i])
			{
				ps->save_max = ps->stack_a[i];
				ps->save_sup = ps->stack_a[i];
				ps->save_pos = i;
			}
		}
	}
}

static void	sort_r(t_ps *ps, int i)
{
	while (++i < ps->save_pos)
	{
		ft_rotate_a(ps);
		printf("ra\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
	}
}

static void	sort_rr(t_ps *ps, int i)
{
	i = ps->max_a;
	while (--i > ps->save_pos)
	{
		ft_reverse_rotate_a(ps);
		printf("larra\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
	}
	if (ps->save_sup != 0)
	{
		ft_reverse_rotate_a(ps);
		printf("rra\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
	}
}

void	ft_sort_stack_a(t_ps *ps)
{
	int	i;

	i = -1;
	ps->save_max = 0;
	ps->save_pos = 0;
	ps->save_sup = 0;
	while (++i < ps->max_a)
	{
		if (ps->save_max < ps->stack_a[i])
		{
			ps->save_max = ps->stack_a[i];
			ps->save_pos = i;
		}
	}
	i = -1;
	sort_a_next(ps, i);
	if ((int)(ps->max_a / 2) >= ps->save_pos)
		sort_r(ps, i);
	else
		sort_rr(ps, i);
}

void	ft_final_sort_stack_a(t_ps *ps)
{
	int	len;

	find_max_a(ps, 0);
	len = ps->max_a / 2;
	if (ps->rank > len)
		rank_more_len_a(ps);
	else
	{
		while (ps->rank >= 0)
		{
			ft_rotate_a(ps);
			printf("ra\n");
			if (ps->op_v)
				print_stack(ps, 0, 0);
			ps->rank--;
		}
	}
}
