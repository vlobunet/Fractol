/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:24:53 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/19 14:25:01 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "../libmlx/includes/mlx.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include "pthread.h"

# define K_ESC 53
# define K_Q 12
# define K_W 13
# define K_E 14
# define K_A 0
# define K_S 1
# define K_D 2
# define K_Z 50
# define K_X 60
# define K_N 46
# define K_M 45

# define COLOR_FON 0x202020
# define COLOR_RED 0xff0000
# define COLOR_LIME 0x00ff00
# define COLOR_BLUE 0x0000ff
# define COLOR_YELLOW 0xffff00
# define COLOR_AQUA 0x00ffff
# define UI_CLR COLOR_LIME

# define GRAY_00 0x000000
# define GRAY_19 0x191919
# define GRAY_32 0x323232
# define GRAY_4B 0x4B4B4B
# define GRAY_64 0x646464
# define GRAY_7D 0x7D7D7D
# define GRAY_96 0x969696
# define GRAY_AF 0xAFAFAF
# define GRAY_C8 0xC8C8C8
# define GRAY_FA 0xFAFAFA

# define P_1 0.190476
# define P_2 0.380952
# define P_3 0.523810
# define P_4 0.809524

# define G_1 0.142857
# define G_2 0.238095
# define G_3 0.333333
# define G_4 0.428571
# define G_5 0.523810
# define G_6 0.619048
# define G_7 0.714286
# define G_8 0.809524
# define G_9 0.904762

# define C_RED "\033[01;38;05;196;48;05;232m"
# define C_ORANG "\033[01;38;05;214;48;05;232m"
# define C_RESET "\033[0m"

# define M_MEMORRY "Memory Allocation Error.\n"
# define M_NUMBER "Invalid number of attributes.\n"
# define M_OPTION "Invalid arguments.\n"
# define M_OPTION_SHORT "Invalid fractol's name: "
# define M_NOF "Fractal not found.\n"
# define M_UN "./fractol [-x] [641..1443] [-y] [361..899]] [-n] name_fractal\n"
# define M_SIZE "Incorrect display sizes.\n"
# define M_USAGE_MOR_SIZE "Min display size: 640 x 360\n"
# define M_USAGE_MIN_SIZE "Max display size: 1444 x 900\n"

# define WINX 1280
# define WINY 720
# define MINWINX 640
# define MINWINY 360
# define MAXW 1440
# define MAXH 900

# define D (double)

# define INTERFACE_WDTH 200
# define INTERFACE_HGHT 260
# define FONT_SIZE 20
# define INTER(i) (33 + (FONT_SIZE * i++))

# define GET_COEFFICIENT_X(x) ((x / 3.2  * 0.01) - 3.20)
# define GET_COEFFICIENT_Y(y) ((y / 1.1 * 0.01) - 3.20)
# define KOSTIL(p, p_num, color) (color * (p - p_num) * 4.0)

# define THREADS_NUM 8

typedef struct
{
	int				win_x;
	int				win_y;
}					t_size_window;

typedef struct
{
	int				julia;
	int				mandelbrot;
	int				leaf;
	int				rhombus;
}					t_variety;

typedef struct
{
	long double		x;
	long double		y;
}					t_coef;

typedef struct
{
	int				size_line;
	int				endian;
	void			*img;
	void			*mlx;
	void			*win;
	char			*data_addr;
	int				bpixel;
}					t_mlx;

typedef struct
{
	int				x;
	int				y;
	t_variety		name;
	t_size_window	wsize;
	t_mlx			m;
	int				color;
	int				rot;
	double			z;
	int				e;
	float			minx;
	float			miny;
	double			padx;
	double			pady;
	double			imax;
	t_coef			coef;
	double			i;
	long double		zr;
	long double		zi;
	long double		mr;
	long double		mi;
	long double		tmp;
	long double		mod;
	int				clr;
	int				cursor_x;
	int				cursor_y;
	int				motion;
	int				invert;
	uint8_t			color_mode;
}					t_fractol;

int					g_w;
int					g_h;

t_fractol			*print_error (char *str);
int					print_warning (char *str, char *name);
uint8_t				check_data(uint8_t res, t_fractol *f);
int					attribute_check(char **v, char *tmp, t_fractol *f);
void				check_name_fractol(char *name, t_fractol *f);
t_fractol			*struct_init (int c, t_fractol *f);
int					expose_func(t_fractol *f);
void				draw_fractal(t_fractol *f);
void				set_color(t_fractol *f);
void				reset_values(t_fractol *f);
void				init_window(t_fractol *f);
void				set_zum(t_fractol *f, int key);
void				rotate_fractal(t_fractol *f, int rot);
int					put_pixel(t_fractol *f, int type, int i, char *rgb);
void				reset_values(t_fractol *f);
void				set_zum(t_fractol *f, int key);
#endif
