#include "push_swap.h"

void	ps_stack_push(t_stack **stk, int n)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		exit(0);
	new->n = n;
	new->next = *stk;
	*stk = new;
}

void	ps_stack_pop(t_stack **stk)
{
	t_stack *tmp;

	tmp = *stk;
	*stk = (*stk)->next;
	free(tmp);
}
