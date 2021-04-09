/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:57:45 by acharras          #+#    #+#             */
/*   Updated: 2021/04/09 14:34:17 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		ft_is_sorted(t_sorted *sort, int argc)
{
	int		i;

	i = 0;
	while((argc < i) && (sort->stack_a[i] < sort->stack_a[i + 1]))
	{
		i++;
		if (sort->stack_b[i])
			break ;
	}
	if (i != argc - 1)
		return (0);
	return (1);
}
