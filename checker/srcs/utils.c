/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:11:14 by acharras          #+#    #+#             */
/*   Updated: 2021/04/09 16:20:13 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		ft_max_stack(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	return (i);
}

int*	ft_up_stack(int *stack)
{
	int	i;
	int	k;
	int	*tab;

	i = 0;
	while (stack[i])
		i++;
	k = i;
	i = 0;
	tab = malloc(sizeof(int) * (i));
	while (i < k - 1)
	{
		tab[i] = stack[i + 1];
		i++;
	}
	tab[i] = 0;
	ft_delete(stack);
	return (tab);
}

int*	ft_down_stack(int *stack)
{
	int	i;
	int	k;
	int	*tab;

	i = 0;
	while (stack[i])
		i++;
	k = i;
	i = 0;
	tab = malloc(sizeof(int) * (i));
	while (i + 1 < k)
	{
		tab[k] = stack[k - 1];
		k--;
	}
	tab[i] = 0;
	ft_delete(stack);
	return (tab);
}