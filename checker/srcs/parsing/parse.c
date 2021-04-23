/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:38:37 by aurbuche          #+#    #+#             */
/*   Updated: 2021/04/23 16:45:34 by acharras         ###   ########lyon.fr   */
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
