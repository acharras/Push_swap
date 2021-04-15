/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurbuche <aurbuche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:13:06 by acharras          #+#    #+#             */
/*   Updated: 2021/04/14 14:58:08 by aurbuche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

void	ft_sort_push(t_ps *ps, char **push)
{
	if (ps->command_a == 1)
		ft_swap_a(ps);
	if (ps->command_b == 1)
		ft_swap_b(ps);
}
