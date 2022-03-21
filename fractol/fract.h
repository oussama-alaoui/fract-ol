
#ifndef FRACT_H
# define FRACT_H
# include <string.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 500
# define HEIGHT 500
# define XMAX 2
# define XMIN -2
# define YMAX 2
# define YMIN -2
# define MAX_ITERATION 100

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	double	x;
	double	y;
	float	c_r;
	float	c_i;
	double	z_r;
	double	z_i;
	double	a;
	double	b;
	double	range;
	double	dr;
	double	iteration;
	double	color;
	t_image	*image;
}	t_vars;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void	ft_draw(t_vars *vars);
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
double	ft_map(int in, double in_end, double out_start, double out_end);
int		draw_julia(t_vars *vars);
int		draw_mandelbrot(t_vars *vars);
void	ft_draw_1(t_vars *vars);
void	ft_jul(t_vars *vars);
void	ft_man(t_vars *vars);
void	zoom_in(t_vars *vars);
void	zoom_out(t_vars *vars);
int		zoom(int key, int x, int y, t_vars *vars);
void	dr(t_vars *vars, t_image *image);
#endif
