/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurbuche <aurbuche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:38:35 by aurbuche          #+#    #+#             */
/*   Updated: 2021/04/12 10:44:14 by aurbuche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_num_arg(int ac, char **av)
{
	int	i;
	int	j;

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

int	check_cmd_arg(t_check *ck)
{
	if (!ft_strcmp(ck->cmd, "pa"))
		return (1);
	else if (!ft_strcmp(ck->cmd, "pb"))
		return (1);
	else if (!ft_strcmp(ck->cmd, "sa"))
		return (1);
	else if (!ft_strcmp(ck->cmd, "sb"))
		return (1);
	else if (!ft_strcmp(ck->cmd, "ra"))
		return (1);
	else if (!ft_strcmp(ck->cmd, "rb"))
		return (1);
	else if (!ft_strcmp(ck->cmd, "rr"))
		return (1);
	else if (!ft_strcmp(ck->cmd, "rra"))
		return (1);
	else if (!ft_strcmp(ck->cmd, "rrb"))
		return (1);
	else if (!ft_strcmp(ck->cmd, "rrr"))
		return (1);
	return (0);
}
