/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurbuche <aurbuche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:11:14 by acharras          #+#    #+#             */
/*   Updated: 2021/04/13 07:53:01 by aurbuche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

int	ft_max_stack(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	return (i);
}

int	*ft_up_stack(int *stack, int len)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * len + 1);
	while (i < len)
	{
		tab[i] = stack[i + 1];
		i++;
	}
	tab[i] = 0;
	free(stack);
	return (tab);
}

int	*ft_down_stack(int *stack, int len)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * len + 1);
	while (i < len)
	{
		tab[len] = stack[len - 1];
		len--;
	}
	tab[i] = 0;
	free(stack);
	return (tab);
}
