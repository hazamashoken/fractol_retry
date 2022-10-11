/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:10:08 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/11 13:34:33 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include <stdio.h>

# include "setting.h"

# define PI 3.1415926535

# if __linux__
#  include "keys_linux.h"
# else
#  include "keys_macos.h"
# endif

typedef unsigned char	t_unchar;

typedef struct s_color
{
	int			*palette;
	int			pattern;
	int			color;
	t_unchar	r;
	t_unchar	g;
	t_unchar	b;
}	t_color;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	int		mouseclick;
}	t_win;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
	double	zoom;
	int		inter;
	int		maxiter;
	double	movex;
	double	movey;

}	t_img;

typedef struct s_fract
{
	double	ki;
	double	kr;
	double	sx;
	double	rx;
	double	fx;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
}	t_fract;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_vars
{
	t_color	color;
	t_win	win;
	t_img	img;
	t_point	point;
	t_fract	fractol;
	int		fract;
}	t_vars;

//libft.c
int		ft_putstr_fd(char *str, int fd);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t nmeb, size_t size);
int		ft_atoi(const char *nptr);

//hooks.c
int		keyhooks(int key, t_vars *env);
int		mousehooks(int key, int x, int y, t_vars *env);
int		loophooks(t_vars *env);
int		close_hooks(t_vars *env);
//zoom.c
void	zoom(t_vars *env, double zoom);
void	move(t_vars *env, double distance, char direction);

//warp_my_ass_minilibx.c
void	white_screen(void *mlx, void *win, int w, int h);
void	white_screen_image(t_vars *env, int w, int h);
void	draw_line_image(t_vars *env, t_point p1, t_point p2, int color);
void	my_mlx_pixel_put(t_vars *env, int x, int y, int color);
void	reinit_img(t_vars *env);

//color.c
void	color_gen(t_vars *env);

//color_utils.c
int		get_percent_color(int color, double percent);
int		interpolate(int startcolor, int endcolor, double fraction);
void	fill_color_stripe(t_vars *env, int color, int stripe);
//julia.c
int		julia(t_vars *env, double r, double i);
int		julia_shift(int x, int y, t_vars *env);

//mandelbrot.c
int		mandelbrot(double r, double i);

//burning_ship.c
int		burning_ship(double cr, double ci);

//tricorn.c
int		tricorn(double cr, double ci);

//mandelbox.c
int		mandelbox(t_vars *env, double cr, double ci);

//utils.c
int		close_window(t_vars *env, int exit_code);
void	init_env(t_vars *env);

//initiator.c
void	init(t_vars *env);

//render.c
void	render(t_vars *env);

#endif
