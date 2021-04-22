#include "../../../includes/checker.h"

void	pa_til_end(t_ps *ps, int i)
{
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
				if_forrest_two(ps, i);
			}
		}
	}
	ft_final_sort_stack_a(ps);
}
