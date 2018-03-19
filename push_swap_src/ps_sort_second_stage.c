#include "push_swap.h"
#define SMART 1
static void	ps_sort_spin_drum_up(t_push_swap *ps)
{
	while (ps->a_end->n < ps->a->n && ps->a_end->n > ps->b->n)
		ps_sort_make_op(ps, RRA, 0);
}

static void	ps_sort_spin_drum_down(t_push_swap *ps)
{
	while (ps->a->n < ps->b->n)
		ps_sort_make_op(ps, RA, 0);
}

static void	ps_sort_search_and_push_a(t_push_swap *ps)
{
	int max;
	int op;

	max = ps_sort_get_op_num(ps, 2);
	if (ps_sort_in_half_case(ps->b, max, 2))
	{
		while ((op = ps_sort_if_can_move_up(ps->b, ps->size_b, max)) > 0)
		{
			if (op == 1 || op == 3)
				ps_sort_make_op(ps, RB, SMART);
			else if (op == 2)
				ps_sort_make_op(ps, RRB, SMART);
		}
		if (ps->a_end->n < ps->a->n && ps->a_end->n > ps->b->n)
			ps_sort_spin_drum_up(ps);
		if (ps->a->n < ps->b->n)
			ps_sort_spin_drum_down(ps);
		ps_sort_make_op(ps, PA, SMART);
	}
	else
		ps_sort_make_op(ps, RB, SMART);
}

void		ps_sort_second_stage(t_push_swap *ps)
{
	int sort;

	while (!(sort = ps_stack_is_rev_sorted(ps->b)) && ps->size_b > 3)
		ps_sort_search_and_push_a(ps);
	if (ps->size_b == 3)
		ps_sort_last_3_numbers_b(ps, ps->b);
	else if (!sort && ps->size_b == 2)
		ps_sort_make_op(ps, SB, SMART);
	while (ps->b)
		ps_sort_make_op(ps, PA, SMART);
}
