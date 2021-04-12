/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurbuche <aurbuche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:30:54 by acharras          #+#    #+#             */
/*   Updated: 2021/04/12 10:57:35 by aurbuche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	init_ck(t_check *ck, int ac)
{
	ck->max = ac - 1;
	ck->command_a = 0;
	ck->command_b = 0;
	// ck->max_a = ac - 1;
	// ck->max_b = 0;
	ck->check = 0;
	ck->cmd = NULL;
	ck->stack_a = malloc(sizeof(int) * (ac - 1));
	ck->stack_b = malloc(sizeof(int) * (ac - 1));
}

static int	*fill_stack_a(int ac, char **av, t_check *ck)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < ac - 1)
	{
		ck->stack_a[i] = ft_atoi(av[j]);
		i++;
		j++;
	}
	return (ck->stack_a);
}

int	main(int ac, char **av)
{
	t_check	ck[1];

	if (!check_num_arg(ac, av))
	{
		printf("Error\n");
		return (0);
	}
	init_ck(ck, ac);
	ck->stack_a = fill_stack_a(ac, av, ck);
	while (get_next_line(1, &ck->cmd) > 0)
	{
		if (!stack_command(ck))
		{
			printf("Error\n");
			return (0);
		}
	}
	printf("----------\n");
	for (int i = 0; i < ac - 1; i++)
		printf("%d  |  %d\n", i, ck->stack_a[i]);
	printf("----------\n");
	int i = 0;
	while (ck->command[i])
	{
		printf("%d  |  %s\n", i, ck->command[i]);
		i++;
	}
	free(ck->stack_a);
	free(ck->stack_b);
	return (0);
}
