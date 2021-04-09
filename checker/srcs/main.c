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

t_check *init_ck(t_check *ck, int ac)
{
	ck = malloc(sizeof(t_check *) + 1);
	ck->tab = malloc(sizeof(int) * ac);
	return ck;
}

int	*fill_tab(int ac, char **av, t_check *ck)
{
	int		i;

	i = 0;
	while (i <= ac)
	{
		ck->tab[i] = ft_atoi(av[0]);
		i++;
	}
	ck->tab[i] = 0;
	return ck->tab;
}

int main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	t_check *ck;

	ck = NULL;
	ck = init_ck(ck, ac);
	ck->tab = fill_tab(ac, av, ck);
	for (int i = 0; i < ac; i++)
		printf(" %d |", ck->tab[i]);
	printf("\n");
	return 0;
}