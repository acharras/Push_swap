/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurbuche <aurbuche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:38:35 by aurbuche          #+#    #+#             */
/*   Updated: 2021/04/13 13:20:07 by aurbuche         ###   ########lyon.fr   */
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
