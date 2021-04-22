#include "../../../includes/checker.h"

int	if_forrest_one(t_ps *ps, int i)
{
	if (ps->max >= 7)
	{
		i++;
		ft_push_b(ps);
		printf("pb\n");
		if (ps->max >= 8)
		{
			i++;
			ft_push_b(ps);
			printf("pb\n");
			if (ps->max >= 9)
			{
				i++;
				ft_push_b(ps);
				printf("pb\n");
				if (ps->max == 10)
				{
					i++;
					ft_push_b(ps);
					printf("pb\n");
				}
			}
		}
	}
	return (i);
}

void	if_forrest_two(t_ps *ps, int i)
{
	if (i >= 4)
	{
		ft_sort_stack_a(ps);
		ft_push_a(ps);
		printf("pa\n");
		if (i >= 5)
		{
			ft_sort_stack_a(ps);
			ft_push_a(ps);
			printf("pa\n");
			if (i == 6)
			{
				ft_sort_stack_a(ps);
				ft_push_a(ps);
				printf("pa\n");
			}
		}
	}
}
