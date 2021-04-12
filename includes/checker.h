/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:31:09 by acharras          #+#    #+#             */
/*   Updated: 2021/04/09 13:30:29 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
<<<<<<< HEAD
# include "../Libft/libft.h"
=======
# include "../libft/libft.h"
>>>>>>> acharras
# include <stdio.h>

typedef struct	s_sorted
{
	int         max;
	int         command_a;
	int         command_b;
	int 		*stack_a;
	int			*stack_b;
	char		*line;
}				t_sorted;

<<<<<<< HEAD
typedef struct	s_check
{
	int	*tab;
}				t_check;

void	        ft_swap_a(t_sorted *sort, char **push);
void        	ft_swap_b(t_sorted *sort, char **push);
=======
void	        ft_swap_a(t_sorted *sort);
void        	ft_swap_b(t_sorted *sort);
>>>>>>> acharras
void	        ft_sort_push(t_sorted *sort, char **push);
void	        ft_command(t_sorted *sort, char **argv);



#endif
