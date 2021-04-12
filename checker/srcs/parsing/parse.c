/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:38:37 by aurbuche          #+#    #+#             */
/*   Updated: 2021/04/12 14:36:48 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

static void	fill_tmp(t_ps *ps)
{
	char	**tmp;
	int		i;
	i = 0;
	tmp = (char **)malloc(sizeof(char *) * (sizeof(ps->command) + 2));
	while (ps->command[i])
	{
		tmp[i] = ft_strdup(ps->command[i]);
		i++;
	}
	tmp[i] = ft_strdup(ps->cmd);
	tmp[i + 1] = NULL;
	ft_freetab(ps->command);
	ps->command = tmp;
}

int	stack_command(t_ps *ps)
{
	char	**tmp;
	int		i;
	i = 0;
	if (!check_cmd_arg(ps))
		return (0);
	if (ps->check)
		fill_tmp(ps);
	else
	{
		ps->check++;
		ps->command = malloc(sizeof(char *) * 2);
		// dprintf(1, "{%s}\n", ps->cmd);
		ps->command[0] = ft_strdup(ps->cmd);
		ps->command[1] = NULL;
	}
	ft_delete(&ps->cmd);
	return (1);
}
