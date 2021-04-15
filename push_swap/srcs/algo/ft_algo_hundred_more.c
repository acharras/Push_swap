/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_hundred_more.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:25:41 by aurbuche          #+#    #+#             */
/*   Updated: 2021/04/15 17:19:05 by acharras         ###   ########lyon.fr   */
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

	i = -1;
	save_max = 0;
	save_pos = 0;
	while (++i < ps->max_b)
		if (save_max < ps->stack_b[i])
		{
			save_max = ps->stack_b[i];
			save_pos = i;
		}
	i = -1;
	if ((int)(ps->max_b / 2) >= save_pos)
	{
		while (++i < save_pos)
			ft_rotate_b(ps);
		ft_rotate_b(ps);
	}
	else
	{
		i = ps->max_b;
		while (i-- > save_pos)
			ft_reverse_rotate_b(ps);
	}
}

void	ft_algo_hundred_more(t_ps *ps)
{
	int i;
	int j;
	int	tmp;

	i = 0;
	j = ps->max_a - 1;
	tmp = 0;
	set_stack(ps);
	while (ps->max_a > 0)
	{
		if (ps->set_stack[i][1] < (ps->chunk * ps->nchunk) ||
			ps->set_stack[j][1] < (ps->chunk * ps->nchunk))
		{
			printf("emplacement set stack i : %d \nemplacement set stack j : %d\nchunk : %d\n\n", ps->set_stack[i][1], ps->set_stack[j][1], ps->chunk * ps->nchunk);
			//mettre le nombre au top de la stack
			if (ps->set_stack[i][1] < (ps->chunk * ps->nchunk))
			{
				printf("i : %d\n", i);
				printf("stack_a[i] : %d\n", ps->stack_a[i]);
				while (i-- > 0)
				{
					ft_rotate_a(ps);
					printf("rotate n fois\n");
				}
				ft_sort_stack_b(ps);
			}
			else
			{
				printf("j : %d\n", j);
				while (j++ < ps->max_a)
				{
					ft_reverse_rotate_a(ps);
					printf("reverse rotate n fois\n");
				}
				ft_sort_stack_b(ps);
			}
			//push le nombre sur b
			tmp++;
			ft_push_b(ps);
			printf("push sur B : %d\n\n", ps->stack_b[0]);
			i = -1;
			j = ps->max_a;
			if (tmp == ps->nchunk)
			{
				tmp = 0;
				ps->chunk++;
			}
			
		}
		i++;
		j--;
	}
	i = -1;
	while (++i < ps->max)
		ft_push_a(ps);
}