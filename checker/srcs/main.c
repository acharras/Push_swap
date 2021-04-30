/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:30:54 by acharras          #+#    #+#             */
/*   Updated: 2021/04/30 14:02:15 by acharras         ###   ########lyon.fr   */
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
	ps->stack_a = malloc(sizeof(int *) * (ac - 1));
	ps->stack_b = malloc(sizeof(int *) * (ac - 1));
	ps->max_op = ac - 2;
}

static void	desalocate_ps(t_ps *ps)
{
	free(ps->stack_a);
	free(ps->stack_b);
	ft_delete(&ps->cmd);
}

static int	ck_order_loop(t_ps *ps, int i, int prev)
{
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
	return (1);
}

static int	ck_order(t_ps *ps)
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
	if (!ck_order_loop(ps, i, prev))
		return (0);
	printf("\033[0;32mEND\n");
	print_stack(ps, 0, 0);
	printf("OK\n\033[0m");
	return (1);
}

int	main(int ac, char **av)
{
	t_ps	ps[1];

	if (ac < 2)
		return (print_error());
	init_ck(ps, ac);
	if (!fill_stack_a(ac, av, ps))
	{
		printf("Error\n");
		free(ps->stack_a);
		free(ps->stack_b);
		return (-1);
	}
	print_stack(ps, 0, 0);
	while (get_next_line(0, &ps->cmd) > 0)
	{
		if (!stack_command(ps))
			return (print_error());
		ft_delete(&ps->cmd);
	}
	ck_order(ps);
	desalocate_ps(ps);
	return (0);
}
