#include "../../../includes/checker.h"

void	ft_final_sort_stack_b(t_ps *ps)
{
	int	len;

	find_max_b(ps, 0);
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
		while (ps->rank > 0)
		{
			ft_rotate_b(ps);
			ps->rank--;
		}
	}
}

static void	sort_next(t_ps *ps, int i)
{
	i = -1;
	if (ps->save_max > ps->stack_a[0])
	{
		ps->save_sup = ps->save_max;
		while (++i < ps->max_b)
		{
			if (ps->stack_b[i] > ps->stack_a[0]
				&& ps->save_max > ps->stack_b[i])
			{
				ps->save_max = ps->stack_b[i];
				ps->save_sup = ps->stack_b[i];
				ps->save_pos = i;
			}
		}
	}
}

static void	sort_r(t_ps *ps, int i, int tmp_max)
{
	while (++i < ps->save_pos)
	{
		ft_rotate_b(ps);
		printf("rb\n");
	}
	if (ps->save_sup != 0 || tmp_max > ps->stack_a[0])
	{
		ft_rotate_b(ps);
		printf("rb\n");
	}
}

static void	sort_rr(t_ps *ps, int i, int tmp_max)
{
	i = ps->max_b;
	while (--i > ps->save_pos)
	{
		ft_reverse_rotate_b(ps);
		printf("rrb\n");
	}
	ft_reverse_rotate_b(ps);
	printf("rrb\n");
	if (ps->save_sup != 0 || tmp_max > ps->stack_a[0])
	{
		ft_rotate_b(ps);
		printf("rb\n");
	}
}

void	ft_sort_stack_b(t_ps *ps)
{
	int	i;
	int	tmp_max;

	i = -1;
	ps->save_max = 0;
	ps->save_pos = 0;
	ps->save_sup = 0;
	while (++i < ps->max_b)
	{
		if (ps->save_max < ps->stack_b[i])
		{
			ps->save_max = ps->stack_b[i];
			ps->save_pos = i;
		}
	}
	tmp_max = ps->save_max;
	sort_next(ps, i);
	i = -1;
	if ((int)(ps->max_b / 2) >= ps->save_pos)
		sort_r(ps, i, tmp_max);
	else
		sort_rr(ps, i, tmp_max);
}
