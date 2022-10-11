/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:59:16 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/10 00:40:16 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fractol.h"

static int	movehooks(int key, t_vars *env)
{
	if (key == KEY_ARROW_UP)
		move(env, 0.2, 'U');
	else if (key == KEY_ARROW_DOWN)
		move(env, 0.2, 'D');
	else if (key == KEY_ARROW_LEFT)
		move(env, 0.2, 'R');
	else if (key == KEY_ARROW_RIGHT)
		move(env, 0.2, 'L');
	else
		return (0);
	render(env);
	return (0);
}

static int	colorhooks(int key, t_vars *env)
{
	if (key == KEY_SPACE)
		color_gen(env);
	else
		return (0);
	render(env);
	return (0);
}

static int	zoomhooks(int key, t_vars *env)
{
	if (key == KEY_EQUAL)
		zoom(env, 0.5);
	else if (key == KEY_DASH)
		zoom(env, 2);
	else
		return (0);
	render(env);
	return (0);
}

int	keyhooks(int key, t_vars *env)
{
	if (key == KEY_ESC)
		close_window(env, 0);
	zoomhooks(key, env);
	colorhooks(key, env);
	movehooks(key, env);
	return (0);
}

int	mousehooks(int key, int x, int y, t_vars *env)
{
	if (key == MOUSE_WHEEL_UP)
	{
		zoom(env, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(env, (double)x * -1.0 / WIDTH, 'R');
		else if (x > 0)
			move(env, (double)x / WIDTH, 'L');
		if (y < 0)
			move(env, (double)y * -1.0 / HEIGHT, 'U');
		else if (y > 0)
			move(env, (double)y / HEIGHT, 'D');
	}
	else if (key == MOUSE_WHEEL_DOWN)
		zoom(env, 2);
	else if (key == MOUSE_ONE)
	{
		if (env->fract == JULIA)
			julia_shift(x, y, env);
	}
	else
		return (0);
	render(env);
	return (0);
}
