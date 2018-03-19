#include "push_swap.h"

int			ps_sort_if_can_move_up(t_stack *stk, int size, int num)
{
	int		pos;

	pos = 1;
	while (stk)
	{
		if (stk->n == num)
			break ;
		pos++;
		stk = stk->next;
	}
	if (pos == 1)
		return (0);
	else if (pos == 2)
		return (3);
	else if (((size / 2) + 1) >= pos)
		return (1);
	else
		return (2);
}

int 		ps_sort_in_half_case(t_stack *stk, int num, int min_or_max)
{
	int less;
	int more;

	less = 0;
	more = 0;
	while (stk)
	{
		if (stk->n > num)
			more++;
		else
			less++;
		stk = stk->next;
	}
	if (min_or_max == 1)
		return ((less <= ((more + less + 1) / 5)) ? 1 : 0);
	else if (min_or_max == 2)
		return ((less >= ((more + less + 1) / 5)) ? 1 : 0);
	return (0);
}

int			ps_sort_get_search_numbers(t_stack *start, t_stack *end,
									int size, int min_or_max)
{
	int	i;
	int	n;

	i = 0;
	n = start->n;
	while (i < (size / 2) && start)
	{
		if (min_or_max == 1 && start->n < n)
			n = start->n;
		else if (min_or_max == 2 && start->n > n)
			n = start->n;
		start = start->next;
		i++;
	}
	while (i < size && end)
	{
		if (min_or_max == 1 && end->n < n)
			n = end->n;
		else if (min_or_max == 2 && end->n > n)
			n = end->n;
		end = end->prev;
		i++;
	}
	return (n);
}

int 		ps_sort_get_op_num(t_push_swap *ps, int min_or_max)
{
	if (min_or_max == 1)
		return (ps_sort_get_search_numbers(ps->a, ps->a_end, ps->search_radius * 2, 1));
	else if (min_or_max == 2)
		return (ps_sort_get_search_numbers(ps->b, ps->b_end, ps->search_radius * 2, 2));
	else
		return (0);
}

void		ps_sort_make_op(t_push_swap *ps, int op)
{
	ps_make_operation(ps, op);
	ps_operation_push(&ps->op, op);
}
