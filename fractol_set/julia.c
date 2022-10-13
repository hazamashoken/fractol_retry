/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:57:53 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/13 22:06:16 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_shift(int x, int y, t_vars *env)
{
	env->fractol.kr = env->fractol.min_r + (double)x * (env->fractol.max_r
			- env->fractol.min_r) / WIDTH;
	env->fractol.ki = env->fractol.max_i + (double)y * (env->fractol.min_i
			- env->fractol.max_i) / HEIGHT;
	return (0);
}

int	julia(t_vars *env, double r, double i)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < MAXINTER)
	{
		if ((i * i + r * r) > 4.0)
			break ;
		tmp = 2 * r * i + env->fractol.ki;
		r = r * r - i * i + env->fractol.kr;
		i = tmp;
		n++;
	}
	return (n);
}
