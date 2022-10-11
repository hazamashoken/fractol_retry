/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:15:35 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/11 21:49:18 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fractol.h"

void	control(int code)
{
	ft_putstr_fd("\033[1;33mFractols:\033[1;32m[julia [real, imaginary], mandelbrot, \
mandelbox, burningship, tricorn]\n", 1);
	ft_putstr_fd("\033[1;33mControls: Move: \033[1;32mArrow Keys\n", 1);
	ft_putstr_fd("\033[1;33mZoom: \033[1;32m- \033[1;33m& \033[1;32m+ ", 1);
	ft_putstr_fd("\033[1;33mMouse Zoom: \033[1;32mScrool Wheel\n", 1);
	ft_putstr_fd("\033[1;33mColor Palette: \033[1;32mSpacebar\n", 1);
	ft_putstr_fd("\033[1;33mJulia Change: \033[1;32mRight Click\n", 1);
	if (code == 2)
		exit(1);
}

void	check_args(char *str, t_vars *env)
{
	if (ft_strncmp(str, "julia", ft_strlen(str)) == 0)
		env->fract = 1;
	else if (ft_strncmp(str, "mandelbrot", ft_strlen(str)) == 0)
		env->fract = 2;
	else if (ft_strncmp(str, "burningship", ft_strlen(str)) == 0)
		env->fract = 3;
	else if (ft_strncmp(str, "tricorn", ft_strlen(str)) == 0)
		env->fract = 4;
	else if (ft_strncmp(str, "mandelbox", ft_strlen(str)) == 0)
		env->fract = 5;
	else
		control(2);
}

void	set_julia(t_vars *env, int argc, char **argv)
{
	if (!(env->fract == 1) || argc == 2)
	{
		env->fractol.kr = -0.776767;
		env->fractol.ki = -0.090000;
		return ;
	}
	if (argc == 4)
	{
		env->fractol.kr = ft_atoi(argv[2]);
		env->fractol.ki = ft_atoi(argv[3]);
	}
	if (env->fractol.kr > 2.0 && env->fractol.kr < -2.0)
	{
		ft_putstr_fd("\033[1;33merror your real world is \
			out of range (1.99 to -1.99).\n", 2);
		exit(EXIT_FAILURE);
	}
	if (env->fractol.ki >= 2.0 && env->fractol.ki <= -2.0)
	{
		ft_putstr_fd("\033[1;33merror your imaginary world is \
			out of range (2.00 to -2.00).\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_vars	env;

	init_env(&env);
	(void)argv;
	if (argc >= 2)
	{
		check_args(argv[1], &env);
		init_env(&env);
		set_julia(&env, argc, argv);
		init(&env);
		render(&env);
		mlx_key_hook(env.win.win, keyhooks, &env);
		mlx_mouse_hook(env.win.win, mousehooks, &env);
		mlx_hook(env.win.win, EVENT_DESTORY_NOTIFY, 0, close_hooks, &env);
		mlx_loop(env.win.mlx);
	}
	else
		control(2);
}
