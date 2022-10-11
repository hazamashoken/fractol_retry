/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:11:40 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/11 21:13:08 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fractol.h"
#include "setting.h"
#include <mlx.h>

int	calc_fractol(t_vars *env, double pr, double pi)
{
	int	iter;

	iter = 0;
	if (env->fract == JULIA)
		iter = julia(env, pr, pi);
	else if (env->fract == MANDELBOT)
		iter = mandelbrot(pr, pi);
	else if (env->fract == BURNINGSHIP)
		iter = burning_ship(pr, pi);
	else if (env->fract == TRICORN)
		iter = tricorn(pr, pi);
	else if (env->fract == MANDELBOX)
		iter = mandelbox(env, pr, pi);
	return (iter);
}

void	set_pixel_color(t_vars *env, int x, int y, int color)
{
		env->img.addr[x * 4 + y * WIDTH * 4] = color;
		env->img.addr[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
		env->img.addr[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
		env->img.addr[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

void	render(t_vars *env)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		iter;

	mlx_clear_window(env->win.mlx, env->win.win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = env->fractol.min_r + (double)x
				* (env->fractol.max_r - env->fractol.min_r) / WIDTH;
			pi = env->fractol.max_i + (double)y
				* (env->fractol.min_i - env->fractol.max_i) / HEIGHT;
			iter = calc_fractol(env, pr, pi);
			set_pixel_color(env, x, y, env->color.palette[iter]);
		}
	}
	mlx_put_image_to_window(env->win.mlx, env->win.win, env->img.img, 0, 0);
}
