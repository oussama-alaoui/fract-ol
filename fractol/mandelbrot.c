
#include "fract.h"

void	ft_man(t_vars *vars)
{
	vars->a = ft_map(vars->x, WIDTH, -vars->range, vars->range);
	vars->b = ft_map(vars->y, HEIGHT, -vars->range, vars->range);
	vars->c_r = vars->a;
	vars->c_i = vars->b;
	vars->iteration = 0;
}

void	ft_draw(t_vars *vars)
{
	vars->dr = 1;
	vars->y = 0;
	while (vars->y++ < HEIGHT)
	{
		vars->x = 0;
		while (vars->x++ < WIDTH)
		{
			ft_man(vars);
			while (vars->iteration < MAX_ITERATION)
			{
				vars->z_r = pow(vars->a, 2) - pow(vars->b, 2);
				vars->z_i = 2 * vars->a * vars->b;
				vars->a = vars->z_r + vars->c_r;
				vars->b = vars->z_i + vars->c_i;
				if (pow(vars->a, 2) + pow(vars->b, 2) > 4)
					break ;
				vars->iteration++;
			}
			vars->color = 0;
			if (vars->iteration < MAX_ITERATION)
				vars->color = vars->iteration * 0xd50800;
			my_mlx_pixel_put(vars->image, vars->x, vars->y, vars->color);
		}
	}
	mlx_put_image_to_window (vars->mlx, vars->win, vars->image->img, 0, 0);
}
