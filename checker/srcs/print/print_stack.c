/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurbuche <aurbuche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 08:23:06 by aurbuche          #+#    #+#             */
/*   Updated: 2021/04/14 12:03:40 by aurbuche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

void	print_color_stack(t_ps *ps, int i)
{
	if (ps->cmd[0] == 's')
		color_s(ps, i, ps->cmd[1]);
	else if (ps->cmd[0] == 'p')
		color_p(ps, i, ps->cmd[1]);
	else if (ps->cmd[0] == 'r')
		color_r(ps, i, ps->cmd[1]);
}

void	print_stack(t_ps *ps, int i, int j)
{
	printf("╔══════════════╦═══════════════╗\n");
	printf("║   Stack A    ║    Stack B    ║\n");
	printf("╠══════════════╬═══════════════╣\n");
	while (i < ps->max_a || j < ps->max_b)
	{
		if (i >= ps->max_a)
			printf("║              ║");
		else if (i < ps->max_a)
			printf("║%*i ║", 13, ps->stack_a[i]);
		if (j >= ps->max_b)
			printf("               ║\n");
		else if (j < ps->max_a)
			printf("%*i  ║\n", 13, ps->stack_b[j]);
		if (i < ps->max_a)
			i++;
		if (j < ps->max_b)
			j++;
	}
	printf("╚══════════════╩═══════════════╝\n");
}