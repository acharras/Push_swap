#include "../../../includes/checker.h"

int	check_set_stack(t_ps *ps, int current_nbr, int end)
{
	int	i;

	i = -1;
	while (++i < ps->max_a)
	{
		if (ps->set_stack[i][0] == current_nbr)
			return (-1);
	}
	return (0);
}

static void	set_stack_loop(t_ps *ps, int i, int j)
{
	int	save_min;
	int	save_pos;

	while (++i < ps->max_a)
	{
		ps->set_stack[i][0] = -2147483648;
		ps->set_stack[i][1] = 0;
	}
	i = -1;
	while (++i < ps->max_a)
	{
		save_min = 2147483647;
		j = -1;
		while (++j < ps->max_a)
		{
			if (save_min > ps->stack_a[j]
				&& check_set_stack(ps, ps->stack_a[j], i) == 0)
			{
				save_min = ps->stack_a[j];
				save_pos = j;
			}
		}
		ps->set_stack[save_pos][0] = save_min;
		ps->set_stack[save_pos][1] = i;
	}
}

void	set_stack(t_ps *ps)
{
	int	i;
	int	j;

	i = -1;
	ps->set_stack = malloc(sizeof(int **) * ps->max_a);
	while (++i < ps->max_a)
		ps->set_stack[i] = malloc(sizeof(int *) * 2);
	i = -1;
	set_stack_loop(ps, i, j);
}
