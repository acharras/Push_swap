/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:31:09 by acharras          #+#    #+#             */
/*   Updated: 2021/04/22 13:28:05 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/include/libft.h"
# include <stdio.h>
# include <ctype.h>

typedef struct s_ps
{
	char	*line;
	char	*cmd;
	char	**command;
	int		max;
	int		max_a;
	int		max_b;
	int		command_a;
	int		command_b;
	int		*stack_a;
	int		*stack_b;
	int		check;
	int		op_v;
	int		op_c;
	int		max_op;
	int		nchunk;
	int		chunk;
	int		median;
	int		lower;
	int		bigger;
	int		hold_first;
	int		hold_second;
	int		middle;
	int		**set_stack;
	int		rank;
	int		save_max;
	int		save_pos;
	int		save_sup;
}					t_ps;

void		print_stack(t_ps *ps, int i, int j);
void		print_color_stack(t_ps *ps, int i);
void		color_s(t_ps *ps, int i, char c);
void		color_r(t_ps *ps, int i, char c);
void		color_p(t_ps *ps, int i, char c);

//PARSING FILE
int			check_num_arg(int ac, char **av, t_ps *ps);
int			check_cmd_arg(t_ps *ps);
int			stack_command(t_ps *ps);
long		ft_atoi_ps(const char *str);
int			*fill_stack_a(int ac, char **av, t_ps *ps);

//OPTION FILE
void		ft_sort_push(t_ps *sort, char **push);
void		ft_command(t_ps *sort, char **argv);
void		ft_up_set_stack(t_ps *ps);
void		ft_down_set_stack(t_ps *ps);
int			ft_swap_a(t_ps *ps);
int			ft_swap_b(t_ps *ps);
int			ft_swap_ss(t_ps *ps);
int			ft_push_a(t_ps *ps);
int			ft_push_b(t_ps *ps);
int			ft_rotate_a(t_ps *ps);
int			ft_rotate_b(t_ps *ps);
int			ft_rotate_rr(t_ps *ps);
int			ft_reverse_rotate_b(t_ps *ps);
int			ft_reverse_rotate_a(t_ps *ps);
int			ft_is_sorted(t_ps *sort, int argc);
int			ft_reverse_rotate_rr(t_ps *ps);
int			ft_max_stack(int *stack);
int			*ft_up_stack(int *stack, int len);
int			*ft_down_stack(int *stack, int len);
int			ft_reverse_rotate_set_stack(t_ps *ps);
int			ft_rotate_set_stack(t_ps *ps);
int			ft_push_set_stack(t_ps *ps);

/**********************PUSH_SWAP***************************/
float		ft_sqrt(int nb);
void		ft_algo_hundred_more(t_ps *ps);
void		set_stack(t_ps *ps);
void		ft_sort_stack_b(t_ps *ps);
void		ft_final_sort_stack_b(t_ps *ps);
void		find_max_a(t_ps *ps, int i);
void		find_max_b(t_ps *ps, int i);
int			*fill_stack_a(int ac, char **av, t_ps *ps);
int			check_set_stack(t_ps *ps, int current_nbr, int end);
void		ft_algo_til_ten(t_ps *ps);

#endif
