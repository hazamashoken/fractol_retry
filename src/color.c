/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:12:13 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/11 12:08:33 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fractol.h"

void	set_multiple(t_vars *env, int colors[4], int n)
{
	int		i;
	int		j;
	int		x;
	double	fraction;

	i = 0;
	x = 0;
	while (i < MAXINTER)
	{
		j = 0;
		while ((i + j) < MAXINTER && j < (MAXINTER / (n - 1)))
		{
			fraction = (double)j / ((double)MAXINTER / (n - 1));
			env->color.palette[i + j]
				= interpolate(colors[x], colors[x + 1], fraction);
			j++;
		}
		x++;
		i += j;
	}
	env->color.palette[MAXINTER - 1] = 0;
}

void	set_contrasted(t_vars *env, int color)
{
	int	i;
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = (color >> 0) & 0xFF;
	i = -1;
	while (++i < MAXINTER)
	{
		env->color.palette[i] = 0;
		if (r != 0xFF)
			r += i % 0xFF;
		if (g != 0xFF)
			g += i % 0xFF;
		if (b != 0xFF)
			b += i % 0xFF;
		env->color.palette[i] = 0xFF << 24 | r << 16 | g << 8 | b;
	}
	env->color.palette[MAXINTER - 1] = 0;
}

void	set_color_zebra(t_vars *env, int color)
{
	int	color2;

	color2 = get_percent_color(color, 50);
	fill_color_stripe(env, color, 1);
	fill_color_stripe(env, color2, 2);
	env->color.palette[MAXINTER - 1] = 0;
}

void	color_gen_next(t_vars *env)
{
	int	alt_color;

	if (env->color.color == 0xFFFFFF)
		alt_color = 0xCCCCCC;
	else
		alt_color = env->color.color;
	if (env->color.pattern == 2)
		set_contrasted(env, alt_color);
	else if (env->color.pattern == 3)
		set_multiple(env, (int [8]){0xFF0000, 0xFF7F00, 0xFFFF00,
			0x00FF00, 0x0000FF, 0x4B0082, 0x9400D3, 0xFFFFFF}, 8);
}

void	color_gen(t_vars *env)
{
	int	alt_color;

	env->color.pattern = (env->color.pattern + 1) % 4;
	reinit_img(env);
	if (env->color.color == 0x00000)
		alt_color = 0x333333;
	else
		alt_color = env->color.color;
	if (env->color.pattern == 0)
		set_multiple(env, (int [4]){0x333333, alt_color,
			get_percent_color(env->color.color, 50), 0xFFFFFF}, 4);
	else if (env->color.pattern == 1)
		set_color_zebra(env, env->color.color);
	else
		color_gen_next(env);
}
