/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_hundred_more.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:25:41 by aurbuche          #+#    #+#             */
/*   Updated: 2021/04/15 15:45:19 by acharras         ###   ########lyon.fr   */
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


void	set_stack(t_ps *ps)
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

static void		ft_sort_stack_b(t_ps *ps)
{
	  
}

void		ft_algo_hundred_more(t_ps *ps)
{
	int i;
	int j;

	i = 0;
	j = ps->max_a;
	set_stack(ps);
	while (i < (int)(ps->max / 2) && j > (int)(ps->max / 2))
	{
		if (ps->set_stack[i][1] < (ps->chunk * ps->nchunk) ||
			ps->set_stack[j][1] < (ps->chunk * ps->nchunk))
		{
			//mettre le nombre au top de la stack
			if (ps->set_stack[i][1] < (ps->chunk * ps->nchunk))
			{
				while (i-- > 0)
					ft_rotate_a(ps);
				//sort la stack_b
			}
			else
			{
				while (j++ < ps->max_a + 1)
					ft_reverse_rotate_a(ps);
				//sort la stack_b
			}
			//push le nombre sur b
			ft_push_b(ps);
			i = 0;
			j = ps->max_a;
		}
		i++;
		j--;
	}
}