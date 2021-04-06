/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:30:54 by acharras          #+#    #+#             */
/*   Updated: 2021/03/08 15:39:35 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		main(int argc, char **argv)
{
	int	i;
	char **push;

	i = 0;
	if (argc == 1)
		return (0);
	while(argv[i])
		i++;
	push = malloc(sizeof(char*) * (i + 1));
	if (/* condition */)
	{
		while(i-- >= 0)
			push[i] = argv[i];
		if (ft_is_sorted())
			ft_printf("Ok\n");
		else
			ft_printf("KO\n");
	}
	else
		ft_printf(2, "Error\n");
	return (0);
}