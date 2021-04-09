/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:30:54 by acharras          #+#    #+#             */
/*   Updated: 2021/04/09 16:30:42 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void	ft_init(t_sorted *sort, int argc)
{
	sort->max = argc - 1;
	sort->command_a = 0;
	sort->command_b = 0;
	sort->max_a = argc - 1;
	sort->max_b = 0;
	sort->stack_a = malloc(sizeof(int) * (argc - 1));
	sort->stack_b = malloc(sizeof(int) * (argc - 1));
}

int			main(int argc, char **argv)
{
	t_sorted sort[1];
	int	i;

	i = 0;
	if (argc == 1)
		return (0);
	while(argv[i])
		i++;
	ft_init(sort, argc);
	if (argc > 1)
	{
		while(i-- >= 0)
			sort->stack_a[i - 1] = ft_atoi(argv[i]);
	}
	else
		return (0); /* faire une fonction exit qui free */
	while (get_next_line(0, &sort->line) != 0)
	{
		/* fonction pour lire l'entrée standart */
		printf("\n");
	}
	if (ft_is_sorted(sort, argc) == 1)
		printf("Ok\n");
	else
		printf("KO\n");
		
	return (0);
}