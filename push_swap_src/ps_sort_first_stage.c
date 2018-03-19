#include "push_swap.h"

static void	ps_sort_search_and_push_b(t_push_swap *ps)
{
	int min;
	int op;

	min = ps_sort_get_op_num(ps, 1);
	if (ps_sort_in_half_case(ps->a, min, 1))
	{
		while ((op = ps_sort_if_can_move_up(ps->a, ps->size_a, min)) > 0)
		{
			if (op == 1 || op == 3)
				ps_sort_make_op(ps, RA);
			else if (op == 2)
				ps_sort_make_op(ps, RRA);
		}
		ps_sort_make_op(ps, PB);
	}
	else
		ps_sort_make_op(ps, RA);
}

int			ps_sort_first_stage(t_push_swap *ps)
{
	int sort;

	while (!(sort = ps_stack_is_sorted(ps->a)) && ps->size_a > 3)
		ps_sort_search_and_push_b(ps);
	if (ps->size_a == 3)
		ps_sort_last_3_numbers_a(ps, ps->a);
	else if (!sort && ps->size_a == 2)
		ps_sort_make_op(ps, SA);
	if (!ps->b && ps_stack_is_sorted(ps->a))
		return (1);
	return (0);
}
