/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:36:59 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/09 01:15:17 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_vars *env, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = env->fractol.min_r - env->fractol.max_r;
	center_i = env->fractol.max_i - env->fractol.min_i;
	env->fractol.max_r = env->fractol.max_r + (center_r - zoom * center_r) / 2;
	env->fractol.min_r = env->fractol.max_r + zoom * center_r;
	env->fractol.min_i = env->fractol.min_i + (center_i - zoom * center_i) / 2;
	env->fractol.max_i = env->fractol.min_i + zoom * center_i;
}

void	move(t_vars *env, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = env->fractol.min_r - env->fractol.max_r;
	center_i = env->fractol.max_i - env->fractol.min_i;
	if (direction == 'R')
	{
		env->fractol.min_r += center_r * distance;
		env->fractol.max_r += center_r * distance;
	}
	else if (direction == 'L')
	{
		env->fractol.min_r -= center_r * distance;
		env->fractol.max_r -= center_r * distance;
	}
	else if (direction == 'D')
	{
		env->fractol.min_i -= center_i * distance;
		env->fractol.max_i -= center_i * distance;
	}
	else if (direction == 'U')
	{
		env->fractol.min_i += center_i * distance;
		env->fractol.max_i += center_i * distance;
	}
}
