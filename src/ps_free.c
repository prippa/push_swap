#include "push_swap.h"

static void	ps_stack_free(t_stack **stack)
{
	while (*stack)
	{
		free(*stack);
		*stack = (*stack)->next;
	}
}

void		ps_free(t_push_swap *ps)
{
	if (ps->a)
		ps_stack_free(&ps->a);
	if (ps->b)
		ps_stack_free(&ps->b);
}
