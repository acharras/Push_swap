/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:38:35 by aurbuche          #+#    #+#             */
/*   Updated: 2021/04/28 17:26:49 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

int	check_num_loop(char **av, int i, int j, t_ps *ps)
{
	if (i == 1 && av[i][j] == '-')
		return (2);
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
	int	ret;

	i = 1;
	ret = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			ret = check_num_loop(av, i, j, ps);
			if (!ret)
				return (0);
			else if (ret == 2)
				break ;
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
