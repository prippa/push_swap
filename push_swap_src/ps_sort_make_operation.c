#include "push_swap.h"

void		ps_sort_make_op(t_push_swap *ps, int op)
{
	ps_make_operation(ps, op);
	ps_operation_push(&ps->op, op);
}
