#include "../../../includes/checker.h"

static int	pb_necessary(t_ps *ps, int i)
{
	if (ps->max >= 4)
	{
		ft_push_b(ps);
		printf("pb\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
		if (ps->max >= 5)
		{
			i++;
			ft_push_b(ps);
			printf("pb\n");
			if (ps->op_v)
				print_stack(ps, 0, 0);
			if (ps->max >= 6)
			{
				i++;
				ft_push_b(ps);
				printf("pb\n");
				if (ps->op_v)
					print_stack(ps, 0, 0);
				i = if_forrest_one(ps, i);
			}
		}
	}
	return (i);
}

void	ft_algo_til_ten(t_ps *ps)
{
	int	i;

	i = 0;
	i = pb_necessary(ps, i);
	ft_algo_three(ps);
	if (ps->max >= 4)
	{
		ft_sort_stack_a(ps);
		ft_push_a(ps);
		printf("pa\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
		pa_til_end(ps, i);
	}
}
