/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurbuche <aurbuche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:30:54 by acharras          #+#    #+#             */
/*   Updated: 2021/04/14 13:49:11 by aurbuche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void	init_ck(t_ps *ps, int ac)
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
}

static int	check_order(t_ps *ps)
{
	int	i;
	int	prev;

	i = 1;
	prev = ps->stack_a[0];
	if (ps->max_b)
	{
		printf("\033[0;31mKO\n\033[0m");
		return (0);
	}
	while (i < ps->max)
	{
		if (prev >= ps->stack_a[i])
		{
			printf("\033[0;31mEND\n");
			print_stack(ps, 0, 0);
			printf("KO\n\033[0m");
			return (0);
		}
		prev = ps->stack_a[i];
		i++;
	}
	printf("\033[0;32mEND\n");
	print_stack(ps, 0, 0);
	printf("OK\n\033[0m");
	return (1);
}

int	main(int ac, char **av)
{
	t_ps	ps[1];

	init_ck(ps, ac);
	ps->stack_a = fill_stack_a(ac, av, ps);
	if (ps->stack_a == 0)
	{
		printf("Error\n");
		return (0);
	}
	print_stack(ps, 0, 0);
	while (get_next_line(1, &ps->cmd) > 0)
	{
		if (!stack_command(ps))
		{
			printf("Error\n");
			return (0);
		}
	}
	check_order(ps);
	free(ps->stack_a);
	free(ps->stack_b);
	return (0);
}
