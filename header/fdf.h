/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mville <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:10:25 by mville            #+#    #+#             */
/*   Updated: 2026/02/05 12:40:10 by mville           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>

typedef struct s_bresenham
{
	int	x;
	int	y;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
	int	error;
	int	pas_x;
	int	pas_y;
}	t_bresenham;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
}	t_mlx;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	t_point	**tab;
}	t_map;

typedef struct s_file
{
	int		fd;
	char	*line;
}	t_file;

typedef struct s_win
{
	int		win_width;
	int		win_height;
}	t_win;

typedef struct s_fdf
{
	t_map	map;
	t_mlx	mlx;
	t_file	file;
	t_win	win;
	int		zoom;
	int		shift_x;
	int		shift_y;
	double	rot_x;
	double	rot_y;
	double	rot_z;
	double	z_management;
	int		iso;
	int		color;
	double	angle;
}	t_fdf;

/* parsing.c */
int		parsing_core(char *file, t_fdf *fdf);

/* graphic.c */
int		graphic_init(t_fdf *fdf);
void	fdf_init(t_fdf *fdf);

/* draw.c */
void	bresenham_start(t_fdf *fdf, t_point start, t_point end);

/* line.c */
void	draw_image(t_fdf *fdf);

/* hook.c */
int		key_management(int keycode, void *param);
int		exit_hook(void *param);
int		expose_hook(void *param);

/* utils.c */
void	*ft_final_free(t_fdf *fdf);
void	*ft_free(t_point **matrice, int size);
void	clean_fd_line(t_fdf *fdf);
int		ft_abs(int n);
int		count_word(char *str, char sep);
/* utils_error.c */
int		check_file(char *file);
void	map_error(int index_err, int erreur);

/* libft */
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);

/* gnl */
char	*get_next_line(int fd);

/* render */
void	redraw(t_fdf *fdf);

/* color.c */
int		atoi_hexa(const char *str);
void	parse_point(t_point *point, char *str);

/* projection */
void	rotate(t_fdf *fdf, int *x, int *y, int *z);

#endif
