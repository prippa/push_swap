#include "push_swap.h"

void	ch_vis_debug_dispatcher(t_push_swap *ps, int op, char *cm)
{
	ft_clear();
	ft_putstr("\t\tYou are in debug mode.\n\t\tTo leave write \"exit\"\n");
	ps->vis.op = op;
	ch_vis_get_op_num(ps);
	ch_visualize(ps);
	if (cm)
		ft_printf("\n%~s%s", F_BOLD_RED, "Error: command not found: ", cm);
	ft_putstr("\n->");
	ps->vis.flag_op_b = 0;
	ps->vis.flag_op_a = 0;
}

void	ch_vis_dispatcher(t_push_swap *ps, int op)
{
	if (ps->vis.flag_vis || ps->vis.flag_col)
	{
		ft_clear();
		ps->vis.op = op;
		ch_vis_get_op_num(ps);
		ch_visualize(ps);
		ps->vis.flag_op_b = 0;
		ps->vis.flag_op_a = 0;
	}
}
