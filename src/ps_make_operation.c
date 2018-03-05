#include "push_swap.h"

void	ps_make_operation(t_push_swap *ps, int op)
{
	if (op == SA)
		ps_op_swap(&ps->a);
	else if (op == SB)
		ps_op_swap(&ps->b);
	else if (op == SS)
		ps_op_swap_duo(&ps->a, &ps->b);
	else if (op == PA)
		ps_op_push(&ps->b, &ps->a);
	else if (op == PB)
		ps_op_push(&ps->a, &ps->b);
	else if (op == RA)
		ps_op_rotate(&ps->a);
	else if (op == RB)
		ps_op_rotate(&ps->b);
	else if (op == RR)
		ps_op_rotate_duo(&ps->a, &ps->b);
	else if (op == RRA)
		ps_op_reverse_rotate(&ps->a);
	else if (op == RRB)
		ps_op_reverse_rotate(&ps->b);
	else if (op == RRR)
		ps_op_reverse_rotate_duo(&ps->a, &ps->b);
}
