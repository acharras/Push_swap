/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:13:06 by acharras          #+#    #+#             */
/*   Updated: 2021/03/08 15:39:32 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_sort_push(t_sorted *sort, char **push)
{
	int		sort;
	int		max;

	max = sort->max;
	if (sort->command_a == 1)
		ft_swap_a(sort, push);
	if (sort->command_b == 1)
		ft_swap_b(sort, push);
}
