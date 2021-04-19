/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_hundred_more.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:25:41 by aurbuche          #+#    #+#             */
/*   Updated: 2021/04/19 13:00:31 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

static int	check_set_stack(t_ps *ps, int current_nbr, int end)
{
	int	i;

	i = -1;
	while (++i < ps->max)
		if (ps->set_stack[i][0] == current_nbr)
			return (-1);
	return (0);
}


static void	set_stack(t_ps *ps)
{
	int save_min;
	int save_pos;
	int	i;
	int	j;

	i = -1;
	ps->set_stack = malloc(sizeof(int**) * ps->max);
	while (++i < ps->max)
		ps->set_stack[i] = malloc(sizeof(int) * 2);
	i = -1;
	while (++i < ps->max)
	{
		save_min = 2147483647;
		j = -1;
		while (++j < ps->max)
		{
			if (save_min > ps->stack_a[j] && check_set_stack(ps, ps->stack_a[j], i) == 0)
			{
				save_min = ps->stack_a[j];
				save_pos = j;
			}
		}
		ps->set_stack[save_pos][0] = save_min;
		ps->set_stack[save_pos][1] = i;
	}
}

static void	ft_sort_stack_b(t_ps *ps)
{
	int	i;
	int save_pos;
	int save_max;
	int	save_sup;

	i = -1;
	save_max = 0;
	save_pos = 0;
	save_sup = 0;
	while (++i < ps->max_b)
		if (save_max < ps->stack_b[i])
		{
			save_max = ps->stack_b[i];
			save_pos = i;
		}
	i = -1;
	if (save_max > ps->stack_a[0])
	{
		save_sup = save_max;
		while (++i < ps->max_b)
			if (ps->stack_b[i] > ps->stack_a[0] && save_max > ps->stack_b[i])
			{
				save_max = ps->stack_b[i];
				save_sup = ps->stack_b[i];
				save_pos = i;
			}
	}
	i = -1;
	if ((int)(ps->max_b / 2) >= save_pos)
	{
		while (++i < save_pos)
		{
			ft_rotate_b(ps);
			printf("rb\n");
		}
		if (save_sup != 0)
		{
			ft_rotate_b(ps);
			printf("rb\n");
		}
	}
	else
	{
		i = ps->max_b;
		while (--i > save_pos)
		{
			ft_reverse_rotate_b(ps);
			printf("rrb\n");
		}
		ft_reverse_rotate_b(ps);
		printf("rrb\n");
		if (save_sup != 0)
		{
			ft_rotate_b(ps);
			printf("rb\n");
		}
	}
}

void	ft_algo_hundred_more(t_ps *ps)
{
	int i;
	int j;

	i = 0;
	j = ps->max_a - 1;
	set_stack(ps);
	while (ps->max_a > 0)
	{
		if (i == ps->max_a || j == -1)
		{
			ps->chunk++;
			i = 0;
			j = ps->max_a - 1;
		}
		if ((0 <= ps->set_stack[i][1] &&  ps->set_stack[i][1] < (ps->chunk * ps->nchunk)) ||
			(0 <= ps->set_stack[j][1] && ps->set_stack[j][1] < (ps->chunk * ps->nchunk)))
		{
			if (ps->set_stack[i][1] < (ps->chunk * ps->nchunk))
			{
				while (i-- > 0)
				{
					ft_rotate_a(ps);
					printf("ra\n");
					ft_rotate_set_stack(ps);
				}
				ft_sort_stack_b(ps);
			}
			else
			{
				while (j++ < ps->max_a)
				{
					ft_reverse_rotate_a(ps);
					printf("rra\n");
					ft_reverse_rotate_set_stack(ps);
				}
				ft_sort_stack_b(ps);
			}
			ft_push_set_stack(ps);
			ft_push_b(ps);
			printf("pb\n");
			i = -1;
			j = ps->max_a;
		}
		i++;
		j--;
	}
	i = -1;
	while (++i < ps->max)
	{
		ft_push_a(ps);
		printf("pa\n");
	}
}