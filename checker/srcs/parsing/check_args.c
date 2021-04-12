/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurbuche <aurbuche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:38:35 by aurbuche          #+#    #+#             */
/*   Updated: 2021/04/12 13:47:04 by aurbuche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_num_arg(int ac, char **av, t_ps *ps)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			// if (i == 1 && av[i][j] == '-')
			// {
			// 	if (av[i][j] == 'v' && !ps->op_v)
			// 		ps->op_v = 1;
			// 	else if (av[i][j] == 'c' && !ps->op_c)
			// 		ps->op_c = 1;
			// 	else
			// 		return (0);
			// }
			if (!ft_isdigit(av[i][j])
				&& av[i][j] != ' '
				&& av[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_cmd_arg(t_ps *ps)
{
	if (!ft_strcmp(ps->cmd, "pa"))
		return (1);
	else if (!ft_strcmp(ps->cmd, "pb"))
		return (1);
	else if (!ft_strcmp(ps->cmd, "sa"))
		return (1);
	else if (!ft_strcmp(ps->cmd, "sb"))
		return (1);
	else if (!ft_strcmp(ps->cmd, "ra"))
		return (1);
	else if (!ft_strcmp(ps->cmd, "rb"))
		return (1);
	else if (!ft_strcmp(ps->cmd, "rr"))
		return (1);
	else if (!ft_strcmp(ps->cmd, "rra"))
		return (1);
	else if (!ft_strcmp(ps->cmd, "rrb"))
		return (1);
	else if (!ft_strcmp(ps->cmd, "rrr"))
		return (1);
	return (0);
}
