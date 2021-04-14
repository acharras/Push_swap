/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_hundred_more.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurbuche <aurbuche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:25:41 by aurbuche          #+#    #+#             */
/*   Updated: 2021/04/14 14:25:42 by aurbuche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void		ft_sort_stack_b(t_ps *ps)
{
	  
}

// créer une fonction pour mettre la position de chaque int dans la chaine de base par rapport aux autres + sa valeur dans un int **
// et remplacer stack_a[i]/[j] par le int**
// genre chaine 48 20 17 39 74 45
//              5  2  1  3  6  4


void		ft_algo_hundred_more(t_ps *ps)
{
	int i;
	int j;

	i = 0;
	j = ps->max_a;
	ps->range = /*racine carré*/ps->max;
	ps->chunk = 1;
	while (i < (int)(ps->max / 2) && j > (int)(ps->max / 2))
	{
		if (ps->stack_a[i] < (ps->chunk * ps->range) ||
			ps->stack_a[j] < (ps->chunk * ps->range))
		{
			//mettre le nombre au top de la stack
			if (ps->stack_a[i] < (ps->chunk * ps->range))
			{
				while (i-- > 0)
					ft_rotate_a(ps);
				//sort la stack_b
				
			}
			else
			{
				while (j++ < ps->max_a + 1)
					ft_reverse_rotate_a(ps);
				//sort la stack_b
			}			
			//push le nombre sur b
			ft_push_b(ps);
			i = 0;
			j = ps->max_a;
		}
		i++;
		j--;
	}
}