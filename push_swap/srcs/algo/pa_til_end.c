#include "../../../includes/checker.h"

static void	pa_til_end_next(t_ps *ps, int i)
{
	if (i >= 3)
	{
		ft_sort_stack_a(ps);
		ft_push_a(ps);
		printf("pa\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
		if_forrest_two(ps, i);
	}
}

void	pa_til_end(t_ps *ps, int i)
{
	if (i >= 1)
	{
		ft_sort_stack_a(ps);
		ft_push_a(ps);
		printf("pa\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
		if (i >= 2)
		{
			ft_sort_stack_a(ps);
			ft_push_a(ps);
			printf("pa\n");
			if (ps->op_v)
				print_stack(ps, 0, 0);
			pa_til_end_next(ps, i);
		}
	}
	ft_final_sort_stack_a(ps);
}
