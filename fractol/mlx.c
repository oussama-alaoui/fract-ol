
#include "fract.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	ft_map(int in, double in_end, double out_start, double out_end)
{
	double	mapped_val;

	mapped_val = out_start + ((out_end - out_start) / in_end) * in;
	return (mapped_val);
}

void	dr(t_vars *vars, t_image *image)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "fractol");
	image->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->range = 2;
	vars->image = image;
}
