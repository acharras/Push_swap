/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:11:14 by acharras          #+#    #+#             */
/*   Updated: 2021/04/16 14:12:17 by acharras         ###   ########lyon.fr   */
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

int	**ft_up_set_stack(int **stack, int len)
{
	int	i;
	int	**tab;

	i = -1;
	tab = malloc(sizeof(int*) * len + 1);
	while (++i < len)
		tab[i] = malloc(sizeof(int) * 2);
	i = 0;
	while (i < len - 1)
	{
		tab[i][0] = stack[i + 1][0];
		tab[i][1] = stack[i + 1][1];
		i++;
	}
	tab[i][0] = 0;
	tab[i][1] = -1;
	i = -1;
	free(stack);
	//while (++i < len)
	//{
	//	dprintf(1, "free i : %d\n", i);
	//	free(stack[i]);
	//}
	return (tab);
}

int	**ft_down_set_stack(int **stack, int len)
{
	int	i;
	int	**tab;

	i = -1;
	tab = malloc(sizeof(int*) * len + 1);
	while (++i < len)
		tab[i] = malloc(sizeof(int) * 2);
	i = 0;
	while (i < --len)
	{
		tab[len][0] = stack[len - 1][0];
		tab[len][1] = stack[len - 1][1];
	}
	tab[i][0] = 0;
	tab[i][1] = -1;
	i = -1;
	free(stack);
	//while (++i < len)
	//	free(stack[i]);
	return (tab);
}