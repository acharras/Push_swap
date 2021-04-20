#include "../../../includes/checker.h"

void	ft_final_sort_stack_b(t_ps *ps)
{
	int	len;

	find_max(ps, 0);
	len = ps->max_b / 2;
	if (ps->rank > len)
	{
		while (ps->rank < ps->max_b)
		{
			ft_reverse_rotate_b(ps);
			ps->rank++;
		}
	}
	else
	{
		while (ps->rank >= 0)
		{
			ft_rotate_b(ps);
			ps->rank--;
		}
	}
}

void	ft_sort_stack_b(t_ps *ps)
{
	int	i;
	int	save_pos;
	int	save_max;
	int	save_sup;

	i = -1;
	save_max = 0;
	save_pos = 0;
	save_sup = 0;
	while (++i < ps->max_b)
	{
		if (save_max < ps->stack_b[i])
		{
			save_max = ps->stack_b[i];
			save_pos = i;
		}
	}
	i = -1;
	if (save_max > ps->stack_a[0])
	{
		save_sup = save_max;
		while (++i < ps->max_b)
		{
			if (ps->stack_b[i] > ps->stack_a[0] && save_max > ps->stack_b[i])
			{
				save_max = ps->stack_b[i];
				save_sup = ps->stack_b[i];
				save_pos = i;
			}
		}
	}
	i = -1;
	if ((int)(ps->max_b / 2) >= save_pos)
	{
		while (++i < save_pos)
		{
			ft_rotate_b(ps);
			printf("rb\n");
		}
		if (save_sup != 0)
		{
			ft_rotate_b(ps);
			printf("rb\n");
		}
	}
	else
	{
		i = ps->max_b;
		while (--i > save_pos)
		{
			ft_reverse_rotate_b(ps);
			printf("rrb\n");
		}
		ft_reverse_rotate_b(ps);
		printf("rrb\n");
		if (save_sup != 0)
		{
			ft_rotate_b(ps);
			printf("rb\n");
		}
	}
}
