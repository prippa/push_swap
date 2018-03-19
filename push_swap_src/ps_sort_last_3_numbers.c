#include "push_swap.h"

void		ps_sort_last_3_numbers_b(t_push_swap *ps, t_stack *stk)
{
	if (stk->n > stk->next->n && stk->n > stk->next->next->n
		   && stk->next->n > stk->next->next->n)
		return ;
	else if (stk->n < stk->next->n && stk->n < stk->next->next->n
		&& stk->next->n < stk->next->next->n)
	{
		ps_sort_make_op(ps, SB, 1);
		ps_sort_make_op(ps, RRB, 1);
	}
	else if (stk->n < stk->next->n && stk->n < stk->next->next->n
			 && stk->next->n > stk->next->next->n)
		ps_sort_make_op(ps, RB, 1);
	else if (stk->n > stk->next->n && stk->n < stk->next->next->n
			 && stk->next->n < stk->next->next->n)
		ps_sort_make_op(ps, RRB, 1);
	else if (stk->n < stk->next->n && stk->n > stk->next->next->n
			 && stk->next->n > stk->next->next->n)
		ps_sort_make_op(ps, SB, 1);
	else if (stk->n > stk->next->n && stk->n > stk->next->next->n
			 && stk->next->n < stk->next->next->n)
	{
		ps_sort_make_op(ps, RRB, 1);
		ps_sort_make_op(ps, SB, 1);
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
		ps_sort_make_op(ps, RRA, 1);
		ps_sort_make_op(ps, SA, 1);
	}
	else if (stk->n > stk->next->n && stk->n < stk->next->next->n
			 && stk->next->n < stk->next->next->n)
		ps_sort_make_op(ps, SA, 1);
	else if (stk->n < stk->next->n && stk->n > stk->next->next->n
			 && stk->next->n > stk->next->next->n)
		ps_sort_make_op(ps, RRA, 1);
	else if (stk->n > stk->next->n && stk->n > stk->next->next->n
			 && stk->next->n < stk->next->next->n)
		ps_sort_make_op(ps, RA, 1);
	else if (stk->n > stk->next->n && stk->n > stk->next->next->n
			 && stk->next->n > stk->next->next->n)
	{
		ps_sort_make_op(ps, SA, 1);
		ps_sort_make_op(ps, RRA, 1);
	}
}
