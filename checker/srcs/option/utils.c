/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:11:14 by acharras          #+#    #+#             */
/*   Updated: 2021/04/19 17:08:13 by acharras         ###   ########lyon.fr   */
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

int	**ft_up_set_stack(int **stack, int len)
{
	int	i;
	int	**tab;

	i = -1;
	tab = malloc(sizeof(int **) * len);
	while (++i < len)
		tab[i] = malloc(sizeof(int *) * 2);
	i = 0;
	while (i < len - 1)
	{
		tab[i][0] = stack[i + 1][0];
		tab[i][1] = stack[i + 1][1];
		i++;
	}
	tab[i][0] = stack[0][0];
	tab[i][1] = stack[0][1];
	i = 0;
	while (i < len)
	{
		free(stack[i]);
		stack[i] = NULL;
		i++;
	}
	free(stack);
	stack = NULL;
	return (tab);
}

int	**ft_down_set_stack(int **stack, int len)
{
	int	i;
	int	tmp;
	int	**tab;

	i = -1;
	tmp = len;
	tab = malloc(sizeof(int **) * len);
	while (++i < len)
		tab[i] = malloc(sizeof(int *) * 2);
	i = 0;
	while (i < --len)
	{
		tab[len][0] = stack[len - 1][0];
		tab[len][1] = stack[len - 1][1];
	}
	tab[i][0] = 0;
	tab[i][1] = -1;
	i = 0;
	while (i < tmp)
	{
		free(stack[i]);
		stack[i] = NULL;
		i++;
	}
	free(stack);
	stack = NULL;
	return (tab);
}