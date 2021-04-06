/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:31:09 by acharras          #+#    #+#             */
/*   Updated: 2021/03/08 15:38:52 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

typedef struct	s_sorted
{
    int         max;
    int         command_a;
    int         command_b;
}				t_sorted;

void	        ft_swap_a(t_sorted *sort, char **push);
void        	ft_swap_b(t_sorted *sort, char **push);
void	        ft_sort_push(t_sorted *sort, char **push);
void	        ft_command(t_sorted *sort, char **argv);



#endif
