/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:30:54 by acharras          #+#    #+#             */
/*   Updated: 2021/04/08 13:29:21 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		main(int argc, char **argv)
{
	t_sorted sort[1];
	int	i;
	char **push;

	i = 0;
	if (argc == 1)
		return (0);
	while(argv[i])
		i++;
	push = malloc(sizeof(char*) * (i + 1));
	if (argc > 1)
	{
		while(i-- >= 0)
			push[i] = argv[i];
		
		if (ft_is_sorted())
			printf("Ok\n");
		else
			printf("KO\n");
	}
	else
		return (0); /* faire une fonction exit qui free */
	while (get_next_line(0, &sort->line) != 0)
	{
		/* fonction pour lire l'entrée standart */
		printf("\n");
	}
	return (0);
}