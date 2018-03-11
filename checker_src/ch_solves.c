#include "push_swap.h"

void	ch_solve_list_op(t_push_swap *ps)
{
	t_stack *tmp;

	tmp = ps->op;
	while (tmp)
	{
		ps->flag_is_op_a = 0;
		ps->flag_is_op_b = 0;
		ps_make_operation(ps, tmp->n);
		ch_vis_dispatcher(ps, tmp->n);
		ps->vis.count_op++;
		tmp = tmp->next;
	}
}

void	ch_solve_one_op(t_push_swap *ps, int op)
{
	ps->flag_is_op_a = 0;
	ps->flag_is_op_b = 0;
	ps_make_operation(ps, op);
	ps->vis.count_op++;
}
