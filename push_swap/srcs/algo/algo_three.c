#include "../../../includes/checker.h"

static void	algo_three_next(t_ps *ps)
{
	if (ps->stack_a[0] < ps->stack_a[1] && ps->stack_a[1] > ps->stack_a[2]
		&& ps->stack_a[0] < ps->stack_a[2])
	{
		ft_swap_a(ps);
		printf("sa\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
		ft_rotate_a(ps);
		printf("ra\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
	}
	else if (ps->stack_a[0] < ps->stack_a[1] && ps->stack_a[1] > ps->stack_a[2]
		&& ps->stack_a[0] > ps->stack_a[2])
	{
		ft_reverse_rotate_a(ps);
		printf("rra\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
	}
}

static void	algo_thre_norme(t_ps *ps)
{
	if (ps->stack_a[0] > ps->stack_a[1] && ps->stack_a[1] < ps->stack_a[2])
	{
		ft_rotate_a(ps);
		printf("ra\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
	}
	else if (ps->stack_a[0] > ps->stack_a[1] && ps->stack_a[1] < ps->stack_a[2])
	{
		ft_rotate_a(ps);
		printf("ra\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
	}
}

void	ft_algo_three(t_ps *ps)
{
	if (ps->stack_a[0] > ps->stack_a[1] && ps->stack_a[0] < ps->stack_a[2])
	{
		ft_swap_a(ps);
		printf("sa\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
	}
	else if (ps->stack_a[0] > ps->stack_a[1] && ps->stack_a[1] > ps->stack_a[2])
	{
		ft_swap_a(ps);
		printf("sa\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
		ft_reverse_rotate_a(ps);
		printf("rra\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
	}
	else if ((ps->stack_a[0] > ps->stack_a[1]
			&& ps->stack_a[1] < ps->stack_a[2])
		|| (ps->stack_a[0] > ps->stack_a[1]
			&& ps->stack_a[1] < ps->stack_a[2]))
		algo_thre_norme(ps);
	algo_three_next(ps);
}
