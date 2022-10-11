/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:02:35 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/11 12:04:45 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fractol.h"

int	close_window(t_vars *env, int exit_code)
{
	if (!env)
		exit(exit_code);
	if (env->color.palette)
		free(env->color.palette);
	if (env->img.img)
		mlx_destroy_image(env->win.mlx, env->img.img);
	if (env->win.mlx && env->win.win)
		mlx_destroy_window(env->win.mlx, env->win.win);
	if (env->win.mlx)
	{
		mlx_loop_end(env->win.mlx);
		mlx_destroy_display(env->win.mlx);
		free(env->win.mlx);
	}
	ft_putstr_fd("Exiting...\n", 1);
	exit(exit_code);
}

int	close_hooks(t_vars *env)
{
	close_window(env, 0);
	return (0);
}
