#include "../../../includes/checker.h"

static int	check_dual(t_ps *ps)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = ps->stack_a[0];
	while (i < ps->max)
	{
		j = 0;
		while (j < ps->max)
		{
			if (i != j && tmp == ps->stack_a[j])
				return (0);
			j++;
		}
		i++;
		tmp = ps->stack_a[i];
	}
	return (1);
}

static void	find_max(t_ps *ps, int i)
{
	ps->bigger = ps->stack_a[0];
	while (i < ps->max_a)
	{
		if (ps->stack_a[i] > ps->bigger)
			ps->bigger = ps->stack_a[i];
		i++;
	}
}

int	find_min(t_ps *ps, int i)
{
	if (!check_dual(ps))
		return (0);
	ps->lower = ps->stack_a[0];
	while (i < ps->max_a)
	{
		if (ps->stack_a[i] < ps->lower)
			ps->lower = ps->stack_a[i];
		i++;
	}
	find_max(ps, 1);
	ps->hold_first = ps->stack_a[0];
	ps->hold_second = ps->stack_a[i - 1];
	ps->middle = (i - 1) / 2;
	return (1);
}
