/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_twelve_less.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:14:24 by acharras          #+#    #+#             */
/*   Updated: 2021/04/20 16:49:59 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/checker.h"

static void	find_max(t_ps *ps, int i)
{
	ps->bigger = ps->stack_a[0];
	while (i < ps->max_a)
	{
		if (ps->stack_a[i] > ps->bigger)
		{
			ps->bigger = ps->stack_a[i];
			ps->rank = i;
		}
		i++;
	}
}

static void	ft_sort_stack_a(t_ps *ps)
{
	int	i;
	int	save_pos;
	int	save_max;
	int	save_sup;

	i = -1;
	save_max = 0;
	save_pos = 0;
	save_sup = 0;
	while (++i < ps->max_a)
	{
		if (save_max < ps->stack_a[i])
		{
			save_max = ps->stack_a[i];
			save_pos = i;
		}
	}
	i = -1;
	if (save_max > ps->stack_b[0])
	{
		save_sup = save_max;
		while (++i < ps->max_a)
		{
			if (ps->stack_a[i] > ps->stack_b[0] && save_max > ps->stack_a[i])
			{
				save_max = ps->stack_a[i];
				save_sup = ps->stack_a[i];
				save_pos = i;
			}
		}
	}
	i = -1;
	if ((int)((ps->max_a - 1) / 2) >= save_pos)
	{
		while (++i < save_pos)
		{
			ft_rotate_a(ps);
			printf("ra\n");
		}
	}
	else
	{
		i = ps->max_a;
		while (--i > save_pos)
		{
			ft_reverse_rotate_a(ps);
			printf("rra\n");
		}
		if (save_sup != 0)
		{
			ft_reverse_rotate_a(ps);
			printf("ra\n");
		}
	}
}

static void	ft_final_sort_stack_a(t_ps *ps)
{
	int	len;

	find_max(ps, 0);
	len = ps->max_a / 2;
	if (ps->rank > len)
	{
		while (ps->rank < ps->max_a - 1)
		{
			ft_reverse_rotate_a(ps);
			printf("rra\n");
			ps->rank++;
		}
	}
	else
	{
		while (ps->rank >= 0)
		{
			ft_rotate_a(ps);
			printf("ra\n");
			ps->rank--;
		}
	}
}


void	ft_algo_twelve_less(t_ps *ps)
{
	int i;
	int j;
	
	i = 0;
	j = ps->max_a - 1;
	if (ps->max >= 4)
	{
		ft_push_b(ps);
		printf("pb\n");
		if (ps->max >= 5)
		{
			i++;
			ft_push_b(ps);
			printf("pb\n");
			if (ps->max >= 6)
			{
				i++;
				ft_push_b(ps);
				printf("pb\n");
				if (ps->max >= 7)
				{
					i++;
					ft_push_b(ps);
					printf("pb\n");
					if (ps->max >= 8)
					{
						i++;
						ft_push_b(ps);
						printf("pb\n");
						if (ps->max >= 9)
						{
							i++;
							ft_push_b(ps);
							printf("pb\n");
							if (ps->max == 10)
							{
								i++;
								ft_push_b(ps);
								printf("pb\n");
							}
						}
					}
				}
			}
		}
	}	
	if (ps->stack_a[0] > ps->stack_a[1] && ps->stack_a[0] < ps->stack_a[2])
	{
		ft_swap_a(ps);
		printf("sa\n");
	}
	else if (ps->stack_a[0] > ps->stack_a[1] && ps->stack_a[1] > ps->stack_a[2])
	{
		ft_swap_a(ps);
		printf("sa\n");
		ft_reverse_rotate_a(ps);
		printf("rra\n");
	}
	else if (ps->stack_a[0] > ps->stack_a[1] && ps->stack_a[1] < ps->stack_a[2])
	{
		ft_rotate_a(ps);
		printf("ra\n");
	}
	else if (ps->stack_a[0] < ps->stack_a[1] && ps->stack_a[1] > ps->stack_a[2] && ps->stack_a[0] < ps->stack_a[2])
	{
		ft_swap_a(ps);
		printf("sa\n");
		ft_rotate_a(ps);
		printf("ra\n");
	}
	else if (ps->stack_a[0] < ps->stack_a[1] && ps->stack_a[1] > ps->stack_a[2] && ps->stack_a[0] > ps->stack_a[2])
	{
		ft_reverse_rotate_a(ps);
		printf("rra\n");
	}
	if (ps->max >= 4)
	{
		ft_sort_stack_a(ps);
		ft_push_a(ps);
		printf("pa\n");
		if (i >= 1)
		{
			ft_sort_stack_a(ps);
			ft_push_a(ps);
			printf("pa\n");
			if (i >= 2)
			{
				ft_sort_stack_a(ps);
				ft_push_a(ps);
				printf("pa\n");
				if (i >= 3)
				{
					ft_sort_stack_a(ps);
					ft_push_a(ps);
					printf("pa\n");
					if (i >= 4)
					{
						ft_sort_stack_a(ps);
						ft_push_a(ps);
						printf("pa\n");
						if (i >= 4)
						{
							ft_sort_stack_a(ps);
							ft_push_a(ps);
							printf("pa\n");
							if (i >= 5)
							{
								ft_sort_stack_a(ps);
								ft_push_a(ps);
								printf("pa\n");
								if (i == 6)
								{
									ft_sort_stack_a(ps);
									ft_push_a(ps);
									printf("pa\n");
								}
							}
						}
					}
				}
			}
		}
		ft_final_sort_stack_a(ps);
	}
	
}
