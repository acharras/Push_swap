/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 08:23:06 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:18:17 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

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
		else if (j < ps->max_b)
			printf("%*i  ║\n", 13, ps->stack_b[j]);
		if (i < ps->max_a)
			i++;
		if (j < ps->max_b)
			j++;
	}
	printf("╚══════════════╩═══════════════╝\n");
}
