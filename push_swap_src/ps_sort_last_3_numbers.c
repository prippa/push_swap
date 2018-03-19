#include "push_swap.h"

void		ps_sort_last_3_numbers_b(t_push_swap *ps, t_stack *stk)
{
	if (stk->n > stk->next->n && stk->n > stk->next->next->n
		   && stk->next->n > stk->next->next->n)
		return ;
	else if (stk->n < stk->next->n && stk->n < stk->next->next->n
		&& stk->next->n < stk->next->next->n)
	{
		ps_sort_make_op(ps, SB);
		ps_sort_make_op(ps, RRB);
	}
	else if (stk->n < stk->next->n && stk->n < stk->next->next->n
			 && stk->next->n > stk->next->next->n)
		ps_sort_make_op(ps, RB);
	else if (stk->n > stk->next->n && stk->n < stk->next->next->n
			 && stk->next->n < stk->next->next->n)
		ps_sort_make_op(ps, RRB);
	else if (stk->n < stk->next->n && stk->n > stk->next->next->n
			 && stk->next->n > stk->next->next->n)
		ps_sort_make_op(ps, SB);
	else if (stk->n > stk->next->n && stk->n > stk->next->next->n
			 && stk->next->n < stk->next->next->n)
	{
		ps_sort_make_op(ps, RRB);
		ps_sort_make_op(ps, SB);
	}
}

void		ps_sort_last_3_numbers_a(t_push_swap *ps, t_stack *stk)
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
