/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:27:15 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/13 22:33:31 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fractol.h"

void	init_fractol(t_vars *env)
{
	if (env->fract == JULIA)
	{
		env->fractol.min_r = -2.0;
		env->fractol.max_r = 2.0;
		env->fractol.min_i = -2.0;
		env->fractol.max_i = env->fractol.min_i
			+ (env->fractol.max_r - env->fractol.min_r) * HEIGHT / WIDTH;
	}
	else if (env->fract == MANDELBOX)
	{
		env->fractol.min_r = -4.0;
		env->fractol.max_r = 4.0;
		env->fractol.min_i = -4.0;
		env->fractol.max_i = env->fractol.min_i
			+ (env->fractol.max_r - env->fractol.min_r) * HEIGHT / WIDTH;
	}
	else
	{
		env->fractol.min_r = -2.0;
		env->fractol.max_r = 1.0;
		env->fractol.min_i = -1.5;
		env->fractol.min_i = env->fractol.max_i
			+ (env->fractol.max_r - env->fractol.min_r) * HEIGHT / WIDTH;
	}
}

void	init(t_vars *env)
{
	env->win.mlx = mlx_init();
	if (env->win.mlx == NULL)
	{
		ft_putstr_fd("error your world is void of mlx.\n", 2);
		close_window(env, 1);
	}
	env->win.win = mlx_new_window(env->win.mlx, WIDTH, HEIGHT, "Frucktol");
	if (env->win.win == NULL)
	{
		ft_putstr_fd("error your world is void of window.\n", 2);
		close_window(env, 1);
	}
	env->fractol.sx = 2.0;
	env->fractol.rx = 0.5;
	env->fractol.fx = 1.0;
	init_fractol(env);
	color_gen(env);
}

void	init_img(t_vars *env)
{
	env->color.palette = ft_calloc((MAXINTER + 1), sizeof(int));
	if (env->color.palette == NULL)
	{
		ft_putstr_fd("error your world is void of color.\n", 2);
		close_window(env, 1);
	}
	env->img.img = mlx_new_image(env->win.mlx, WIDTH, HEIGHT);
	if (env->img.img == NULL)
	{
		ft_putstr_fd("error your world is void of image.\n", 2);
		close_window(env, 1);
	}
	env->img.addr = mlx_get_data_addr(env->img.img, &env->img.bpp,
			&env->img.l_len, &env->img.endian);
	if (env->img.addr == NULL)
	{
		ft_putstr_fd("error your world is void of address.\n", 2);
		close_window(env, 1);
	}
}

void	reinit_img(t_vars *env)
{
	if (env->win.mlx && env->img.img)
		mlx_destroy_image(env->win.mlx, env->img.img);
	if (env->color.palette)
		free(env->color.palette);
	if (env->img.addr)
		env->img.addr = NULL;
	init_img(env);
}

void	init_env(t_vars *env)
{
	env->color.r = 255;
	env->color.g = 0;
	env->color.b = 0;
	env->img.zoom = 1;
	env->win.mlx = NULL;
	env->win.win = NULL;
	env->img.img = NULL;
	env->img.addr = NULL;
	env->fractol.min_r = 0;
	env->fractol.max_r = 0;
	env->fractol.min_i = 0;
	env->fractol.max_i = 0;
	env->fractol.kr = 0;
	env->fractol.ki = 0;
	env->fractol.sx = 0;
	env->fractol.rx = 0;
	env->fractol.fx = 0;
	env->color.palette = NULL;
	env->color.pattern = 0;
	env->color.color = 0;
}
