#include "push_swap.h"

static void	ps_duplicate_num_valid(t_push_swap *ps, int n)
{
	t_stack *stk;

	stk = ps->a;
	while (stk)
	{
		if (stk->n == n)
			ps_free_error_exit(ps);
		stk = stk->next;
	}
}

static int	ps_get_num(t_push_swap *ps, char *n)
{
	long long int num;
	int i;
	int flag;

	i = 0;
	flag = 1;
	while (n[i])
	{
		if (!ft_isdigit(n[i]) && !ft_isspace(n[i]))
			ps_free_error_exit(ps);
		if (ft_isdigit(n[i]))
			flag = 0;
		i++;
	}
	if (flag)
		ps_free_error_exit(ps);
	num = ft_atoi_max(n);
	if (num > MAXINT || num < MININT)
		ps_free_error_exit(ps);
	ps_duplicate_num_valid(ps, (int)num);
	return ((int)num);
}

void		ps_parser(t_push_swap *ps, char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		ps_stack_push(&ps->a, ps_get_num(ps, argv[i]));
		i++;
	}
	ps_stack_revers(&ps->a);
}
