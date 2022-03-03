/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:11:13 by zcherkao          #+#    #+#             */
/*   Updated: 2022/02/17 18:16:09 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_jul(t_vars *vars)
{
	vars->a = ft_map(vars->x, WIDTH, -vars->range, vars->range);
	vars->b = ft_map(vars->y, HEIGHT, -vars->range, vars->range);
	vars->c_r = -0.8;
	vars->c_i = 0.156;
	vars->iteration = 0;
}

void	ft_draw_1(t_vars *vars)
{
	vars->dr = 0;
	vars->y = 0;
	while (vars->y++ < HEIGHT)
	{
		vars->x = 0;
		while (vars->x++ < WIDTH)
		{
			ft_jul(vars);
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
				vars->color = vars->iteration * 0xd55800;
			my_mlx_pixel_put(vars->image, vars->x, vars->y, vars->color);
		}
	}
	mlx_put_image_to_window (vars->mlx, vars->win, vars->image->img, 0, 0);
}
