/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:30:54 by acharras          #+#    #+#             */
/*   Updated: 2021/04/06 15:07:37 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void init_ck(t_check *ck, int ac)
{
	ck->max = ac - 1;
	ck->command_a = 0;
	ck->command_b = 0;
//	ck->max_a = ac - 1;
//	ck->max_b = 0;
	ck->stack_a = malloc(sizeof(int) * (ac - 1));
	ck->stack_b = malloc(sizeof(int) * (ac - 1));
}

int	*fill_stack_a(int ac, char **av, t_check *ck)
{
	int	i;
	int j;

	i = 0;
	j = 1;
	while (i < ac - 1)
	{
		ck->stack_a[i] = ft_atoi(av[j]);
		i++;
		j++;
	}
	return ck->stack_a;
}

int check_arg(int ac, char **av)
{
	int	i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j])
				&& av[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_check ck[1];

	if (!check_arg(ac, av))
	{
		printf("Error\n");
		return (0);
	}
	init_ck(ck, ac);
	ck->stack_a = fill_stack_a(ac, av, ck);
	for (int i = 0; i < ac - 1; i++)
		printf("%d  |  %d\n", i, ck->stack_a[i]);
	free(ck->stack_a);
	free(ck->stack_b);
	return 0;
}