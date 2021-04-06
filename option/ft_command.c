/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:15:46 by acharras          #+#    #+#             */
/*   Updated: 2021/04/06 15:04:54 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_command(t_sorted *sort, char **argv)
{
	if (ft_strcmp(argv[1], "sa"))
		sort->command_a = 1;
	if (ft_strcmp(argv[1], "sb"))
		sort->command_b = 1;
}
