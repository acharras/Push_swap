/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:18:32 by acharras          #+#    #+#             */
/*   Updated: 2021/04/30 14:05:11 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

static int	check_then(char **av, int i, int j)
{
	if (i == 1 && (av[i][j + 1] != 'c' && av[i][j + 1] != 'v'
		&& !ft_isdigit(av[i][j + 1])))
		return (0);
	if (i != 1 && (av[i][j + 1] == 'c' && av[i][j + 1] == 'v'))
		return (0);
	if (i != 1 && !ft_isdigit(av[i][j + 1]))
		return (0);
	return (1);
}

static int	check_option_next(int ac, char **av, t_ps *ps)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-')
				if (!check_then(av, i, j))
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_option(int ac, char **av, t_ps *ps)
{
	if (av[1][0] == '-')
	{
		if (!check_char_op(av[1], 1))
			return (0);
		if (!ft_strcmp(av[1], "-cv")
			|| !ft_strcmp(av[1], "-vc"))
		{
			ps->op_c = 1;
			ps->op_v = 1;
		}
		else if (!ft_strcmp(av[1], "-c"))
			ps->op_c = 1;
		else if (!ft_strcmp(av[1], "-v"))
			ps->op_v = 1;
	}
	return (check_option_next(ac, av, ps));
}
