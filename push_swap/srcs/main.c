/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:30:54 by acharras          #+#    #+#             */
/*   Updated: 2021/04/15 15:42:42 by acharras         ###   ########lyon.fr   */
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
	ps->nchunk = (int)ft_sqrt(ps->max) / 2;
	ps->chunk = 1;
	ps->median = (ac - 1) / 2;
	ps->hold_first = 0;
	ps->hold_second = 0;
}

int	main(int ac, char **av)
{
	t_ps	ps[1];
	int	i;
	int j;
	char	**push;

	i = 1;
	j = 0;
	if (ac <= 1)
		return (0);
	init_ps(ps, ac);
	ps->stack_a = fill_stack_a(ac, av, ps);
	if (!ps->stack_a || !find_min(ps, 1))
	{
		printf("Error\n");
		return (0);
	}
//	ft_sort_push(ps, push);
//	ft_algo_hundred_more(ps);
	return(0);
}
