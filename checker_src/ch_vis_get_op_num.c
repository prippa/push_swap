#include "push_swap.h"

static void	ch_vis_get_swap_num(t_push_swap *ps)
{
	if ((ps->vis.op == SA || ps->vis.op == SS) && ps->flag_is_op_a)
	{
		ps->vis.flag_op_a = 1;
		ps->vis.num_op_a = ps->a->next->n;
	}
	if ((ps->vis.op == SB || ps->vis.op == SS) && ps->flag_is_op_b)
	{
		ps->vis.flag_op_b = 1;
		ps->vis.num_op_b = ps->b->next->n;
	}
}

static void	ch_vis_get_push_or_revrotate_num(t_push_swap *ps)
{
	if ((ps->vis.op == PA || ps->vis.op == RRA || ps->vis.op == RRR)
		&& ps->flag_is_op_a)
	{
		ps->vis.flag_op_a = 1;
		ps->vis.num_op_a = ps->a->n;
	}
	else if ((ps->vis.op == PB || ps->vis.op == RRB || ps->vis.op == RRR)
			 && ps->flag_is_op_b)
	{
		ps->vis.flag_op_b = 1;
		ps->vis.num_op_b = ps->b->n;
	}
}

static int	ch_stack_get_last_num(t_stack *stk)
{
	while (42)
	{
		if (!stk->next)
			return (stk->n);
		stk = stk->next;
	}
}

static void	ch_vis_get_rotate_num(t_push_swap *ps)
{
	if ((ps->vis.op == RA || ps->vis.op == RR) && ps->flag_is_op_a)
	{
		ps->vis.flag_op_a = 1;
		ps->vis.num_op_a = ch_stack_get_last_num(ps->a);
	}
	if ((ps->vis.op == RB || ps->vis.op == RR) && ps->flag_is_op_b)
	{
		ps->vis.flag_op_b = 1;
		ps->vis.num_op_b = ch_stack_get_last_num(ps->b);
	}
}

void		ch_vis_get_op_num(t_push_swap *ps)
{
	if (ps->vis.op == SA || ps->vis.op == SB || ps->vis.op == SS)
		ch_vis_get_swap_num(ps);
	else if (ps->vis.op == PA || ps->vis.op == PB)
		ch_vis_get_push_or_revrotate_num(ps);
	else if (ps->vis.op == RA || ps->vis.op == RB || ps->vis.op == RR)
		ch_vis_get_rotate_num(ps);
	else if (ps->vis.op == RRA || ps->vis.op == RRB || ps->vis.op == RRR)
		ch_vis_get_push_or_revrotate_num(ps);
}
