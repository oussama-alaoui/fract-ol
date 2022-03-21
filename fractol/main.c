

#include "fract.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*l;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s1;
	l = (unsigned char *)s2;
	if (!s1 && !s2)
		return (0);
	if (n == 0)
		return (0);
	while (p[i] == l[i] && (i < n) && p[i] && l[i])
		i++;
	if (i == n)
		return (0);
	return (p[i] - l[i]);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_image	image;

	if (ac != 2)
	{
		return (1);
	}
	dr(&vars, &image);
	mlx_mouse_hook(vars.win, zoom, &vars);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	if (!ft_strncmp(av[1], "julia", 6))
		ft_draw_1(&vars);
	else if (!ft_strncmp(av[1], "mandelbrot", 11))
		ft_draw(&vars);
	else
	{
		write(1, "julia \n mandelbrot", 19);
		return (0);
	}
	mlx_loop(vars.mlx);
}
