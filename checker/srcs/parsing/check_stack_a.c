/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurbuche <aurbuche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:45:55 by aurbuche          #+#    #+#             */
/*   Updated: 2021/04/13 16:07:20 by aurbuche         ###   ########lyon.fr   */
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
	while (i < ps->max - 1)
	{
		j = 0;
		while (j < ps->max - 1)
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

static int	check_char_op(char *str, int i)
{
	while (str[i])
	{
		if (str[i] != 'c' && str[i] != 'v'
			&& !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_option(int ac, char **av, t_ps *ps)
{
	if (av[1][0] == '-')
	{
		if (!check_char_op(av[1], 1))
			return (0);
		if (!ft_strcmp(av[1], "-cv")
			|| !ft_strcmp(av[1], "-vc"))
		{
			ps->op_c = 1;
			ps->op_c = 1;
		}
		else if (!ft_strcmp(av[1], "-c"))
			ps->op_c = 1;
		else if (!ft_strcmp(av[1], "-v"))
			ps->op_v = 1;
		else
			return (0);
	}
	return (1);
}

static int	rea_stack(t_ps *ps)
{
	free(ps->stack_a);
	free(ps->stack_b);
	ps->stack_a = malloc(sizeof(int *) * (ps->max));
	ps->stack_b = malloc(sizeof(int *) * (ps->max));
	ps->max--;
	ps->max_a--;
	return (2);
}

int	*fill_stack_a(int ac, char **av, t_ps *ps)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (!check_option(ac, av, ps) || !check_num_arg(ac, av, ps))
		return (0);
	if (ps->op_v || ps->op_c)
		j = rea_stack(ps);
	while (i < ps->max)
	{
		if (ft_atoi_ps(av[j]) == ((long)INT_MIN - 1))
			return (0);
		ps->stack_a[i] = ft_atoi_ps(av[j]);
		i++;
		j++;
	}
	return (check_dual(ps, ps->max));
}
