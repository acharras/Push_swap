/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurbuche <aurbuche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 08:10:50 by aurbuche          #+#    #+#             */
/*   Updated: 2021/04/14 12:15:47 by aurbuche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

static void	print_last_lign(t_ps *ps, int i, int j)
{
	if ((ps->cmd[1] == 'a' || ps->cmd[2] == 'a') && i < ps->max_a)
	{
		printf("║\033[0;34m%*i\033[0m ║", 13, ps->stack_a[i]);
	}
	else
		printf("║              ║");
	if ((ps->cmd[1] == 'b' || ps->cmd[2] == 'b') && i < ps->max_b)
		printf("║\033[0;34m%*i\033[0m ║", 13, ps->stack_b[i]);
	else
		printf("               ║\n");
}

static void	stack_loop(t_ps *ps, int i, int j)
{
	while (i < ps->max_a - 1 || j < ps->max_b - 1)
	{
		if (i >= ps->max_a)
			printf("║              ║");
		else if (i < ps->max_a)
			printf("║%*i ║", 13, ps->stack_a[i]);
		if (j >= ps->max_b)
			printf("               ║\n");
		else if (j < ps->max_b)
			printf("%*i  ║\n", 13, ps->stack_b[j]);
		if (i < ps->max_a)
			i++;
		if (j < ps->max_b)
			j++;
	}
	print_last_lign(ps, i, j);
}

static void	stack_a(t_ps *ps, int i, int j)
{
	if (ps->max_a)
	{
		printf("╔══════════════╦═══════════════╗\n");
		printf("║   Stack A    ║    Stack B    ║\n");
		printf("╠══════════════╬═══════════════╣\n");
		printf("║\033[0;34m%*i\033[0m ║", 13, ps->stack_a[i]);
		if (j >= ps->max_b)
			printf("               ║\n");
		else if (j < ps->max_a)
			printf("%*i  ║\n", 13, ps->stack_b[j]);
		if (i < ps->max_a)
			i++;
		if (j < ps->max_b)
			j++;
		stack_loop(ps, i, j);
		printf("╚══════════════╩═══════════════╝\n");
	}
}

static void	stack_b(t_ps *ps, int i, int j)
{
	if (ps->max_b)
	{
		printf("╔══════════════╦═══════════════╗\n");
		printf("║   Stack A    ║    Stack B    ║\n");
		printf("╠══════════════╬═══════════════╣\n");
		if (i >= ps->max_a)
			printf("║              ║");
		else if (i < ps->max_a)
			printf("║%*i ║", 13, ps->stack_a[i]);
		printf(" \033[0;34m%*i\033[0m ║\n", 13, ps->stack_b[i]);
		if (i < ps->max_a)
			i++;
		if (j < ps->max_b)
			j++;
		stack_loop(ps, i, j);
		printf("╚══════════════╩═══════════════╝\n");
	}
}

void	color_r(t_ps *ps, int i, char c)
{
	if (c == 'a' || (c == 'r' && ps->cmd[2] == 'a'))
		stack_a(ps, i, 0);
	else if (c == 'b')
		stack_b(ps, i, 0);
	else if (c == 'r' && ps->cmd[2] == 0)
	{
		stack_a(ps, i, 0);
		stack_b(ps, i, 0);
	}
}
