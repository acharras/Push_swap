/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurbuche <aurbuche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:30:54 by acharras          #+#    #+#             */
/*   Updated: 2021/04/14 14:54:25 by aurbuche         ###   ########lyon.fr   */
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
	while(argv[i])
		i++;
	sort->max = i;
	push = malloc(sizeof(char*) * (i + 1));
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