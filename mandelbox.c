/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 10:40:13 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/10 00:01:19 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fractol.h"

static double	box_fold(double v)
{
	if (v > 1)
		v = 2 - v;
	else if (v < -1)
		v = -2 - v;
	return (v);
}

static double	ball_fold(double r, double m)
{
	if (m < r)
		m = m / (r * r);
	else if (m < 1)
		m = 1 / (m * m);
	return (m);
}

int	mandelbox(t_vars *env, double cr, double ci)
{
	int		n;
	double	vr;
	double	vi;
	double	mag;

	vr = cr;
	vi = ci;
	mag = 0;
	n = 0;
	while (n < MAXINTER)
	{
		vr = env->fractol.fx * box_fold(vr);
		vi = env->fractol.fx * box_fold(vi);
		mag = sqrt(vr * vr + vi * vi);
		vr = vr * env->fractol.sx * ball_fold(env->fractol.rx, mag) + cr;
		vi = vi * env->fractol.sx * ball_fold(env->fractol.rx, mag) + ci;
		if (sqrt(mag) > 2)
			break ;
		n++;
	}
	return (n);
}
