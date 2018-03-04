#include "push_swap.h"

void	ps_stack_revers(t_stack **stk)
{
	t_stack *prev;
	t_stack *current;
	t_stack *next;

	prev = NULL;
	current = *stk;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*stk = prev;
}
