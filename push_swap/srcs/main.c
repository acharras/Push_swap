/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:30:54 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 14:21:40 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void	init_ps(t_ps *ps, int ac)
{
	ps->max = ac - 1;
	ps->command_a = 0;
	ps->command_b = 0;
	ps->max_a = ac - 1;
	ps->max_b = 0;
	ps->check = 0;
	ps->op_v = 0;
	ps->op_c = 0;
	ps->cmd = NULL;
	ps->command = NULL;
	ps->stack_a = malloc(sizeof(int *) * (ac - 1));
	ps->stack_b = malloc(sizeof(int *) * (ac - 1));
	ps->max_op = ac - 2;
	ps->nchunk = (int)ft_sqrt(ps->max);
	ps->chunk = 1;
	ps->median = (ac - 1) / 2;
	ps->hold_first = 0;
	ps->hold_second = 0;
}

static void	desalloc_ps(t_ps *ps)
{
	free(ps->stack_b);
	free(ps->stack_a);
	free(ps->set_stack);
	ps->set_stack = NULL;
}

static void	main_yew_forrest(t_ps *ps, int j)
{
	if (ps->max != 1)
	{
		if (ps->max == 2)
		{
			if (ps->stack_a[0] > ps->stack_a[1])
			{
				ft_swap_a(ps);
				printf("sa\n");
			}
			if (ps->op_v)
				print_stack(ps, 0, 0);
		}
		else if (ps->max >= 11)
			ft_algo_hundred_more(ps, -1);
		else
			ft_algo_til_ten(ps);
		while (++j < ps->max)
		{
			if (ps->max >= 11)
				free(ps->set_stack[j]);
		}
	}
	desalloc_ps(ps);
}

int	main(int ac, char **av)
{
	t_ps	ps[1];
	int		j;

	j = -1;
	if (ac <= 1)
		return (0);
	init_ps(ps, ac);
	if (!fill_stack_a(ac, av, ps))
	{
		printf("Error\n");
		free(ps->stack_a);
		free(ps->stack_b);
		return (-1);
	}
	if (check_order(ps))
	{
		desalloc_ps(ps);
		return (0);
	}
	main_yew_forrest(ps, j);
	return (0);
}
