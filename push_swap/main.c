/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:30:54 by acharras          #+#    #+#             */
/*   Updated: 2021/03/08 15:39:37 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		main(int argc, char **argv)
{
	t_sorted	*sort;
	int	i;
	char	**push;

	i = 0;
	if (argc == 1)
		return (0);
	while(argv[i])
		i++;
	sort->max = i;
	push = malloc(sizeof(char*) * (i + 1));
	if()
	{
		while(i-- >= 0)
			push[i] = argv[i];

		ft_sort_push(sort, push);
	}
	return(0);
}