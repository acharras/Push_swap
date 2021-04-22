#include "../../../includes/checker.h"

static void	algo_three_next(t_ps *ps)
{
	if (ps->stack_a[0] < ps->stack_a[1] && ps->stack_a[1] > ps->stack_a[2]
		&& ps->stack_a[0] < ps->stack_a[2])
	{
		ft_swap_a(ps);
		printf("sa\n");
		ft_rotate_a(ps);
		printf("ra\n");
	}
	else if (ps->stack_a[0] < ps->stack_a[1] && ps->stack_a[1] > ps->stack_a[2]
		&& ps->stack_a[0] > ps->stack_a[2])
	{
		ft_reverse_rotate_a(ps);
		printf("rra\n");
	}
}

void	ft_algo_three(t_ps *ps)
{
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
	algo_three_next(ps);
}
