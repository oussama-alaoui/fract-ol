

#include "fract.h"

void	zoom_in(t_vars *vars)
{
	vars->range -= vars->range * 0.1;
}

void	zoom_out(t_vars *vars)
{
	vars->range += vars->range * 0.1;
}

int	zoom(int key, int x, int y, t_vars *vars)
{
	x = vars->dr;
	y = 0;
	if (key == 5)
		zoom_in(vars);
	else if (key == 4)
		zoom_out(vars);
	else
		return (0);
	if (x == 1)
		ft_draw(vars);
	if (x == 0)
		ft_draw_1(vars);
	return (1);
}
