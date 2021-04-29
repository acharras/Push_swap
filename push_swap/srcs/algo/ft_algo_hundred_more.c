/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_hundred_more.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:25:41 by aurbuche          #+#    #+#             */
/*   Updated: 2021/04/29 14:21:38 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

static void	in_chunk_l(t_ps *ps, int i)
{
	while (i-- > 0)
	{
		ft_rotate_a(ps);
		printf("ra\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
		ft_rotate_set_stack(ps);
	}
	ft_sort_stack_b(ps);
}

static void	in_chunk_r(t_ps *ps, int j)
{
	while (j++ < ps->max_a)
	{
		ft_reverse_rotate_a(ps);
		printf("rra\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
		ft_reverse_rotate_set_stack(ps);
	}
	ft_sort_stack_b(ps);
}

static void	is_in_chunk(t_ps *ps, int i, int j)
{
	if (ps->set_stack[i][1] < (ps->chunk * ps->nchunk))
		in_chunk_l(ps, i);
	else
		in_chunk_r(ps, j);
	ft_push_set_stack(ps);
	ft_push_b(ps);
	printf("pb\n");
	if (ps->op_v)
		print_stack(ps, 0, 0);
}

static void	algo_loop(t_ps *ps, int i, int j)
{
	while (ps->max_a > 0)
	{
		if (i == ps->max_a || j == -1)
		{
			ps->chunk++;
			i = 0;
			j = ps->max_a - 1;
		}
		if ((0 <= ps->set_stack[i][1]
			 && ps->set_stack[i][1] < (ps->chunk * ps->nchunk))
			|| (0 <= ps->set_stack[j][1]
				&& ps->set_stack[j][1] < (ps->chunk * ps->nchunk)))
		{
			is_in_chunk(ps, i, j);
			i = -1;
			j = ps->max_a;
		}
		i++;
		j--;
	}
}

void	ft_algo_hundred_more(t_ps *ps, int i)
{
	int	j;

	j = ps->max_a - 1;
	set_stack(ps);
	algo_loop(ps, 0, j);
	find_max_a(ps, 0);
	ft_final_sort_stack_b(ps);
	i = -1;
	if (ps->op_c)
		ps->max--;
	while (++i < ps->max)
	{
		ft_push_a(ps);
		printf("pa\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
	}
	if (ps->op_c)
	{
		ps->max++;
		ft_push_a(ps);
		printf("\033[0;34mpa\033[0m\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
	}
}
