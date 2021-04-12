/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurbuche <aurbuche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:38:37 by aurbuche          #+#    #+#             */
/*   Updated: 2021/04/12 10:57:59 by aurbuche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	fill_tmp(t_check *ck)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = (char **)malloc(sizeof(char *) * (sizeof(ck->command) + 2));
	while (ck->command[i])
	{
		tmp[i] = ft_strdup(ck->command[i]);
		i++;
	}
	tmp[i] = ft_strdup(ck->cmd);
	tmp[i + 1] = NULL;
	ft_freetab(ck->command);
	ck->command = tmp;
}

int	stack_command(t_check *ck)
{
	char	**tmp;
	int		i;

	i = 0;
	if (!check_cmd_arg(ck))
		return (0);
	if (ck->check)
		fill_tmp(ck);
	else
	{
		ck->check++;
		ck->command = malloc(sizeof(char *) * 2);
		ck->command[0] = ft_strdup(ck->cmd);
		ck->command[1] = NULL;
	}
	ft_delete(&ck->cmd);
	return (1);
}
