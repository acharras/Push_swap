/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:31:09 by acharras          #+#    #+#             */
/*   Updated: 2021/04/12 14:11:40 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"
# include <stdio.h>

typedef struct	s_ps
{
	int			max;
	int			max_a;
	int			max_b;
	int			command_a;
	int			command_b;
	int			*stack_a;
	int			*stack_b;
	char		*line;
}				t_ps;

void	        ft_swap_a(t_ps *ps);
void        	ft_swap_b(t_ps *ps);
void			ft_swap_ss(t_ps *ps);
void			ft_push_a(t_ps *ps);
void			ft_push_b(t_ps *ps);
void			ft_rotate_a(t_ps *ps);
void			ft_rotate_b(t_ps *ps);
void			ft_rotate_rr(t_ps *ps);
void			ft_reverse_rotate_a(t_ps *ps);
void			ft_reverse_rotate_b(t_ps *ps);
void			ft_reverse_rotate_rr(t_ps *ps);
void	        ft_sort_push(t_ps *sort, char **push);
void	        ft_command(t_ps *sort, char **argv);
int				ft_is_sorted(t_ps *sort, int argc);
int				ft_max_stack(int *stack);
int*			ft_up_stack(int *stack);
int*			ft_down_stack(int *stack);



#endif
