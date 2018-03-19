#include "push_swap.h"

static void	ps_sort_last_3_numbers(t_push_swap *ps, t_stack *stk)
{
	if (stk->n < stk->next->n && stk->n < stk->next->next->n
		&& stk->next->n < stk->next->next->n)
		return ;
	else if (stk->n < stk->next->n && stk->n < stk->next->next->n
			 && stk->next->n > stk->next->next->n)
	{
		ps_sort_make_op(ps, RRA);
		ps_sort_make_op(ps, SA);
	}
	else if (stk->n > stk->next->n && stk->n < stk->next->next->n
			 && stk->next->n < stk->next->next->n)
		ps_sort_make_op(ps, SA);
	else if (stk->n < stk->next->n && stk->n > stk->next->next->n
			 && stk->next->n > stk->next->next->n)
		ps_sort_make_op(ps, RRA);
	else if (stk->n > stk->next->n && stk->n > stk->next->next->n
			 && stk->next->n < stk->next->next->n)
		ps_sort_make_op(ps, RA);
	else if (stk->n > stk->next->n && stk->n > stk->next->next->n
			 && stk->next->n > stk->next->next->n)
	{
		ps_sort_make_op(ps, SA);
		ps_sort_make_op(ps, RRA);
	}
}

static int	ps_sort_if_rr_ss_sa(t_push_swap *ps)
{
	if (ps->size_b > 2 && ps->b->n < ps->b->next->n)
	{
		if (ps->b->n < ps->b->next->next->n)
			return (RR);
		return (SS);
	}
	return (RA);
}

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
				ps_sort_make_op(ps, ps_sort_if_rr_ss_sa(ps));
			else if (op == 2)
				ps_sort_make_op(ps, RRA);
		}
		ps_sort_make_op(ps, PB);
	}
	else
		ps_sort_make_op(ps, ps_sort_if_rr_ss_sa(ps));
}

int			ps_sort_first_stage(t_push_swap *ps)
{
	int sort;

	while (!(sort = ps_stack_is_sorted(ps->a)) && ps->size_a > 3)
		ps_sort_search_and_push_b(ps);
	if (ps->size_a == 3)
		ps_sort_last_3_numbers(ps, ps->a);
	else if (!sort && ps->size_a == 2)
		ps_sort_make_op(ps, SA);
	if (!ps->b && ps_stack_is_sorted(ps->a))
		return (1);
	return (0);
}
