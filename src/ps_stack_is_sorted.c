#include "push_swap.h"

int 	ps_stack_is_sorted(t_stack *stk)
{
	int tmp;

	if (!stk)
		return (1);
	tmp = stk->n;
	stk = stk->next;
	while (stk)
	{
		if (tmp > stk->n)
			return (0);
		tmp = stk->n;
		stk = stk->next;
	}
	return (1);
}
