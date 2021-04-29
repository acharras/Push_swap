/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:38:37 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:18:22 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

int	stack_command(t_ps *ps)
{
	if (!check_cmd_arg(ps))
		return (0);
	else if (ps->op_v)
		print_stack(ps, 0, 0);
	return (1);
}
