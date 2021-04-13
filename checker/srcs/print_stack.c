/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurbuche <aurbuche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 08:23:06 by aurbuche          #+#    #+#             */
/*   Updated: 2021/04/13 16:18:22 by aurbuche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	print_color_stack(t_ps *ps, int i)
{
	printf("----------\n");
	while (i < ps->max)
	{
		if (ps->cmd == NULL)
			printf("|%d  |  % d|\n", i, ps->stack_a[i]);
		else if (!ft_strcmp(ps->cmd, "sa"))
		{
			printf("|\033[0;34m%d  \033[0m|\033[0;34m  % d\033[0m|\n", i, ps->stack_a[i]);
			i++;
			printf("|\033[0;34m%d  \033[0m|\033[0;34m  % d\033[0m|\n", i, ps->stack_a[i]);
			ft_delete(&ps->cmd);
		}
		else
			printf("|%d  |  % d|\n", i, ps->stack_a[i]);			
		i++;
	}
	printf("----------\n");
}

void	print_stack(t_ps *ps, int i)
{
	printf("----------\n");
	while (i < ps->max)
	{
		printf("|%d  |  % d|\n", i, ps->stack_a[i]);
		i++;
	}
	printf("----------\n");
}
