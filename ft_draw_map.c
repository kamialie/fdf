/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:41:48 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/20 21:12:09 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_move_image(t_point *p, int x_off, int y_off)
{
	p->x += x_off;
	p->y += y_off;
}

static void		ft_add_projection(t_point *p, int projection)
{
	int p_x;
	int p_y;

	p_x = p->x;
	p_y = p->y;
	if (projection == 1)
	{
		p->x = (p_x - p_y) * cos(RADIAN(26.57));
		p->y = -p->z + (p_x + p_y) * sin(RADIAN(26.57));
	}
	if (projection == 2)
	{
		p->x = (p_x - p_y) * cos(RADIAN(30));
		p->y = -p->z + (p_x + p_y) * sin(RADIAN(30));
	}
}

static void		ft_get_color(t_point *p, t_map *map)
{
	if (p->z == map->z_min)
		p->color = map->base_color;
	else if (p->z > map->z_min && p->z < map->z_max)
		p->color = map->middle_color;
	else if (p->z == map->z_max)
		p->color = map->top_color;
	else
		p->color = 0x5D6D7E;
}

static t_point	ft_get_point(int x, int y, t_map *map)
{
	int		i;
	t_lst	*tmp;
	t_point	p;

	i = 0;
	tmp = map->head;
	while (i++ < y)
		tmp = tmp->next;
	p.z = ft_atoi(tmp->line[x]);
	ft_get_color(&p, map);
	p.z *= map->z;
	p.x = x * map->zoom - (map->width / 2) * map->zoom;
	p.y = y * map->zoom - (map->height / 2) * map->zoom;
	ft_y_axis_rotation(&p, map->beta);
	ft_z_axis_rotation(&p, map->delta);
	ft_x_axis_rotation(&p, map->alpha);
	if (map->projection)
		ft_add_projection(&p, map->projection);
	ft_move_image(&p, WIN_WIDTH_MID, WIN_HEIGHT_MID);
	ft_move_image(&p, map->x_shift, map->y_shift);
	return (p);
}

void			ft_draw_map(t_map *map, t_mlx mlx)
{
	int		x;
	int		y;
	t_lst	*tmp;
	t_point	a;

	y = -1;
	tmp = map->head;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			a = ft_get_point(x, y, map);
			if (tmp->line[x + 1] != NULL)
				ft_draw_line(a, ft_get_point(x + 1, y, map), mlx);
			if (tmp->next != NULL)
				ft_draw_line(a, ft_get_point(x, y + 1, map), mlx);
		}
		tmp = tmp->next;
	}
	mlx.img.img_data[WIN_WIDTH_MID + WIN_HEIGHT_MID * WIN_WIDTH] = 0xFF0000;
}
