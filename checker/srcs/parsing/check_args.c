/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurbuche <aurbuche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:38:35 by aurbuche          #+#    #+#             */
/*   Updated: 2021/04/12 16:51:53 by aurbuche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

int	check_num_loop(char **av, int i, int j, t_ps *ps)
{
	if (i == 1 && av[i][j] == '-')
	{
		if (av[i][j] == 'v' && !ps->op_v)
			ps->op_v = 1;
		else if (av[i][j] == 'c' && !ps->op_c)
			ps->op_c = 1;
		else
			return (0);
	}
	if (!ft_isdigit(av[i][j])
		&& av[i][j] != ' '
		&& av[i][j] != '-')
		return (0);
	return (1);
}

int	check_num_arg(int ac, char **av, t_ps *ps)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!check_num_loop(av, i, j, ps))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_cmd_arg(t_ps *ps)
{
	if (!ft_strcmp(ps->cmd, "pa"))
		return (ft_push_a(ps));
	else if (!ft_strcmp(ps->cmd, "pb"))
		return (ft_push_b(ps));
	else if (!ft_strcmp(ps->cmd, "sa"))
		return (ft_swap_a(ps));
	else if (!ft_strcmp(ps->cmd, "sb"))
		return (ft_swap_b(ps));
	else if (!ft_strcmp(ps->cmd, "ss"))
		return (ft_swap_ss(ps));
	else if (!ft_strcmp(ps->cmd, "ra"))
		return (ft_rotate_a(ps));
	else if (!ft_strcmp(ps->cmd, "rb"))
		return (ft_rotate_b(ps));
	else if (!ft_strcmp(ps->cmd, "rr"))
		return (ft_rotate_rr(ps));
	else if (!ft_strcmp(ps->cmd, "rra"))
		return (ft_reverse_rotate_a(ps));
	else if (!ft_strcmp(ps->cmd, "rrb"))
		return (ft_reverse_rotate_b(ps));
	else if (!ft_strcmp(ps->cmd, "rrr"))
		return (ft_reverse_rotate_rr(ps));
	return (0);
}
