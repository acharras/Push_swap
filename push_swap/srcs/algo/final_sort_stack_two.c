#include "../../../includes/checker.h"

void	rank_more_len_b(t_ps *ps)
{
	while (ps->rank < ps->max_b)
	{
		ft_reverse_rotate_b(ps);
		printf("rrb\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
		ps->rank++;
	}
}

void	rank_more_len_a(t_ps *ps)
{
	while (ps->rank < ps->max_a - 1)
	{
		ft_reverse_rotate_a(ps);
		printf("rra\n");
		if (ps->op_v)
			print_stack(ps, 0, 0);
		ps->rank++;
	}
}
