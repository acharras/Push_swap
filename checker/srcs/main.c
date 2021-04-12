/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:30:54 by acharras          #+#    #+#             */
/*   Updated: 2021/04/12 14:36:12 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void init_ck(t_ps *ps, int ac)
{
    ps->max = ac - 1;
    ps->command_a = 0;
    ps->command_b = 0;
    // ps->max_a = ac - 1;
    // ps->max_b = 0;
    ps->check = 0;
    ps->op_v = 0;
    ps->op_c = 0;
    ps->cmd = NULL;
    ps->stack_a = malloc(sizeof(int) * (ac - 1));
    ps->stack_b = malloc(sizeof(int) * (ac - 1));
}

static int  *fill_stack_a(int ac, char **av, t_ps *ps)
{
    int i;
    int j;
    i = 0;
    j = 1;
    if (!check_num_arg(ac, av, ps))
        return (0);
    while (i < ac - 1)
    {
        if (ft_atoi_ps(av[j]) == ((long)INT_MIN - 1))
            return (0);
        ps->stack_a[i] = ft_atoi_ps(av[j]);
        i++;
        j++;
    }
    return (ps->stack_a);
}

int main(int ac, char **av)
{
    t_ps    ps[1];
    init_ck(ps, ac);
    ps->stack_a = fill_stack_a(ac, av, ps);
    if (ps->stack_a == 0)
    {
        printf("Error\n");
        return (0);
    }
    while (get_next_line(1, &ps->cmd) > 0)
    {
        if (!stack_command(ps))
        {
            printf("Error\n");
            return (0);
        }
    }
    printf("----------\n");
    for (int i = 0; i < ac - 1; i++)
        printf("%d  |  %d\n", i, ps->stack_a[i]);
    printf("----------\n");
    int i = 0;
    // while (ps->command[i])
    // {
    //  printf("%d  |  %s\n", i, ps->command[i]);
    //  i++;
    // }
    free(ps->stack_a);
    free(ps->stack_b);
    return (0);
}