/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_hundred_more.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:25:41 by aurbuche          #+#    #+#             */
/*   Updated: 2021/04/20 13:32:34 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

void	find_max(t_ps *ps, int i)
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

static int	in_chunk_l(t_ps *ps, int i)
{
	while (i-- > 0)
	{
		ft_rotate_a(ps);
		printf("ra\n");
		ft_rotate_set_stack(ps);
	}
	ft_sort_stack_b(ps);
	return (i);
}

static int	in_chunk_r(t_ps *ps, int j)
{
	while (j++ < ps->max_a)
	{
		ft_reverse_rotate_a(ps);
		printf("rra\n");
		ft_reverse_rotate_set_stack(ps);
	}
	ft_sort_stack_b(ps);
	return (j);
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
			if (ps->set_stack[i][1] < (ps->chunk * ps->nchunk))
				i = in_chunk_l(ps, i);
			else
				j = in_chunk_r(ps, j);
			ft_push_set_stack(ps);
			ft_push_b(ps);
			printf("pb\n");
			i = -1;
			j = ps->max_a;
		}
		i++;
		j--;
	}
}

void	ft_algo_hundred_more(t_ps *ps)
{
	int	i;
	int	j;

	i = 0;
	j = ps->max_a - 1;
	set_stack(ps);
	algo_loop(ps, i, j);
	ft_final_sort_stack_b(ps);
	i = -1;
	while (++i < ps->max)
	{
		ft_push_a(ps);
		printf("pa\n");
	}
}
