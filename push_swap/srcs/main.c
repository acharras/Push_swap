/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurbuche <aurbuche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:30:54 by acharras          #+#    #+#             */
/*   Updated: 2021/04/14 14:28:46 by aurbuche         ###   ########lyon.fr   */
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
	ps->chunk = 0;
	ps->range = ft_sqrt(ps->max);
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
	push = (char **)malloc(sizeof(char *) * (ac));
	while (i < ac)
	{
		push[j] = av[i];
		j++;
		i++;
	}
	push[j] = NULL;
//	ft_sort_push(ps, push);
//	ft_algo_hundred_more(ps);
	return(0);
}
