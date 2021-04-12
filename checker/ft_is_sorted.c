/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurbuche <aurbuche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:57:45 by acharras          #+#    #+#             */
/*   Updated: 2021/04/12 16:33:47 by aurbuche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_is_sorted(t_ps *ps, int argc)
{
	int	i;

	i = 0;
	while ((argc < i) && (ps->stack_a[i] < ps->stack_a[i + 1]))
	{
		i++;
		if (ps->stack_b[i])
			break ;
	}
	if (i != argc - 1)
		return (0);
	return (1);
}
