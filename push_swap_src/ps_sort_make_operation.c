#include "push_swap.h"

static int	ps_sort_make_smart_sb_rb_rrb(t_push_swap *ps, int op)
{
	int flag;
	int num;

	num = ps_sort_get_op_num(ps, 1);
	if (!ps_sort_in_half_case(ps->a, num, 1))
		return (op);
	flag = ps_sort_if_can_move_up(ps->a, ps->size_a, num);
	if (op == SB && flag == 3)
		return (SS);
	else if (op == RB && (flag == 1 || flag == 3))
		return (RR);
	else if (op == RRB && flag == 2)
		return (RRR);
	return (op);
}

static int	ps_sort_make_smart_sa_ra_rra(t_push_swap *ps, int op)
{
	int flag;
	int num;

	num = ps_sort_get_op_num(ps, 2);
	if (!ps_sort_in_half_case(ps->b, num, 2))
		return (op);
	flag = ps_sort_if_can_move_up(ps->b, ps->size_b, num);
	if (op == SA && flag == 3)
			return (SS);
	else if (op == RA && (flag == 1 || flag == 3))
			return (RR);
	else if (op == RRA && flag == 2)
			return (RRR);
	return (op);
}

void		ps_sort_make_op(t_push_swap *ps, int op, int make_smart)
{
	int operation;

	operation = op;
	if (make_smart)
	{
		if (ps->b && (op == SA || op == RA || op == RRA))
			operation = ps_sort_make_smart_sa_ra_rra(ps, op);
		else if (ps->a && (op == SB || op == RB || op == RRB))
			operation = ps_sort_make_smart_sb_rb_rrb(ps, op);
	}
	ps_make_operation(ps, operation);
	ps_operation_push(&ps->op, operation);
}
