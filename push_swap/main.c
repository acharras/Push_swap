/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:30:54 by acharras          #+#    #+#             */
/*   Updated: 2021/04/06 15:40:05 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		main(int argc, char **argv)
{
	t_sorted	sort[1];
	int j;
	char	**push;

	j = 0;
	if (argc == 1)
		return (0);
	sort->max = argc;
	push = malloc(sizeof(char*) * (argc));
	if(argv)
	{
		while(j++ < (argc - 1))
		{
			push[j] = argv[j];
			dprintf(1 , "%s\n", argv[j]);
		}
		ft_sort_push(sort, push);
	}
	return(0);
}