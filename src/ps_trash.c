#include "push_swap.h"

void				ps_free_error_exit(t_push_swap *ps)
{
	ft_putstr_fd("Error", 2);
	ps_free(ps);
	exit(0);
}

void				ps_free_exit(t_push_swap *ps)
{
	ps_free(ps);
	exit(0);
}
