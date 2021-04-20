/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:11:14 by acharras          #+#    #+#             */
/*   Updated: 2021/04/20 13:53:56 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

int	*ft_up_stack(int *stack, int len)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int *) * len);
	while (i < len)
	{
		tab[i] = stack[i + 1];
		i++;
	}
	tab[i] = 0;
	free(stack);
	stack = NULL;
	return (tab);
}

int	*ft_down_stack(int *stack, int len)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int *) * len);
	while (i < --len)
		tab[len] = stack[len - 1];
	tab[i] = 0;
	free(stack);
	stack = NULL;
	return (tab);
}

void	ft_up_set_stack(t_ps *ps)
{
	int	i;
	int	tmp1;
	int	tmp2;

	i = 0;
	tmp1 = ps->set_stack[i][0];
	tmp2 = ps->set_stack[i][1];
	while (i < ps->max_a - 1)
	{
		ps->set_stack[i][0] = ps->set_stack[i + 1][0];
		ps->set_stack[i][1] = ps->set_stack[i + 1][1];
		i++;
	}
	ps->set_stack[i][0] = tmp1;
	ps->set_stack[i][1] = tmp2;
}

void	ft_down_set_stack(t_ps *ps)
{
	int	i;
	int	tmp1;
	int	tmp2;
	int	len;

	len = ps->max_a;
	i = 0;
	tmp1 = ps->set_stack[ps->max_a - 1][0];
	tmp2 = ps->set_stack[ps->max_a - 1][1];
	while (i < --len)
	{
		ps->set_stack[len][0] = ps->set_stack[len - 1][0];
		ps->set_stack[len][1] = ps->set_stack[len - 1][1];
	}
	ps->set_stack[i][0] = tmp1;
	ps->set_stack[i][1] = tmp2;
}
