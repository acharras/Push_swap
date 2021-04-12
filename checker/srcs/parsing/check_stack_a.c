/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurbuche <aurbuche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:45:55 by aurbuche          #+#    #+#             */
/*   Updated: 2021/04/12 16:31:09 by aurbuche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

static int	*check_dual(t_ps *ps, int ac)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = ps->stack_a[0];
	while (i < ac - 1)
	{
		j = 0;
		while (j < ac - 1)
		{
			if (i != j && tmp == ps->stack_a[j])
				return (0);
			j++;
		}
		i++;
		tmp = ps->stack_a[i];
	}
	return (ps->stack_a);
}

int	*fill_stack_a(int ac, char **av, t_ps *ps)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (!check_num_arg(ac, av, ps))
		return (0);
	while (i < ac - 1)
	{
		if (ft_atoi_ps(av[j]) == ((long)INT_MIN - 1))
			return (0);
		ps->stack_a[i] = ft_atoi_ps(av[j]);
		i++;
		j++;
	}
	return (check_dual(ps, ac));
}
