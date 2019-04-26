/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:48:23 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/20 21:18:28 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

# define WIN_WIDTH 1200
# define WIN_HEIGHT 1200
# define WIN_WIDTH_MID WIN_WIDTH / 2
# define WIN_HEIGHT_MID WIN_HEIGHT / 2
# define ABS(Value) ((Value) < 0 ? -(Value) : (Value))
# define MAX(len_y, len_x) ((len_y) > (len_x) ? (len_y) : (len_x))
# define RADIAN(degree) (degree * (M_PI / 180.0))

typedef struct	s_img
{
	void		*img_ptr;
	int			*img_data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}				t_mlx;

typedef struct	s_lst
{
	char			**line;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_map
{
	int				width;
	int				height;
	int				base_color;
	int				middle_color;
	int				top_color;
	int				x_center;
	int				y_center;
	int				alpha;
	int				beta;
	int				delta;
	int				zoom;
	int				projection;
	int				z;
	int				z_max;
	int				z_min;
	int				x_shift;
	int				y_shift;
	struct s_lst	*head;
	struct s_mlx	*mlx;
}				t_map;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct	s_val
{
	int color;
	int	dx;
	int	dy;
	int len_x;
	int	len_y;
	int	length;
	int	flag;
}				t_val;

t_lst			*ft_file_to_lst(t_map *map, int fd);
int				ft_deal_key(int key, t_map *map);
void			ft_rotation_key(int key, t_map *map);
void			ft_spectrum_key(int key, t_map *map);
void			ft_free_list(t_lst *head, int flag);
void			ft_create_image(t_map *map, t_mlx mlx);
void			ft_draw_map(t_map *map, t_mlx mlx);
void			ft_draw_line(t_point a, t_point b, t_mlx mlx);
void			ft_x_axis_rotation(t_point *p, int alpha);
void			ft_y_axis_rotation(t_point *p, int beta);
void			ft_z_axis_rotation(t_point *p, int delta);
int				ft_gradient(int	start, t_point a, t_val val);
void			ft_error(int ernu);
int				ft_get_max_z(t_lst *head);
int				ft_get_min_z(t_lst *head);

#endif
