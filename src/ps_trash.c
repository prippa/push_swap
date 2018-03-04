#include "push_swap.h"

void				ps_free_error_exit(t_push_swap *ps)
{
	ft_putstr_fd("Error\n", 2);
	ps_free(ps);
	system("leaks checker");
	exit(0);
}
