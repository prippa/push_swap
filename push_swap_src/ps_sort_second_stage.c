#include "push_swap.h"

static void	ps_sort_spin_drum_up(t_push_swap *ps, int max)
{
	int op;

	while (ps->a_end->n < ps->a->n && ps->a_end->n > max)
	{
		op = ps_sort_if_can_move_up(ps->b, ps->size_b, max);
		if (op == 2)
			ps_sort_make_op(ps, RRR);
		else
			ps_sort_make_op(ps, RRA);
	}
}

static void	ps_sort_spin_drum_down(t_push_swap *ps, int max)
{
	int op;

	while (ps->a->n < max)
	{
		op = ps_sort_if_can_move_up(ps->b, ps->size_b, max);
		if (op == 1 || op == 3)
			ps_sort_make_op(ps, RR);
		else
			ps_sort_make_op(ps, RA);
	}
}

static void	ps_sort_search_and_push_a(t_push_swap *ps)
{
	int max;
	int op;

	max = ps_sort_get_op_num(ps, 2);
	if (ps_sort_in_half_case(ps->b, max, 2))
	{
		if (ps->a_end->n < ps->a->n && ps->a_end->n > max)
			ps_sort_spin_drum_up(ps, max);
		if (ps->a->n < max)
			ps_sort_spin_drum_down(ps, max);
		while ((op = ps_sort_if_can_move_up(ps->b, ps->size_b, max)) > 0)
		{
			if (op == 1 || op == 3)
				ps_sort_make_op(ps, RB);
			else if (op == 2)
				ps_sort_make_op(ps, RRB);
		}
		ps_sort_make_op(ps, PA);
	}
	else
		ps_sort_make_op(ps, RB);
}

void		ps_sort_second_stage(t_push_swap *ps)
{
	while (ps->b)
		ps_sort_search_and_push_a(ps);
}
