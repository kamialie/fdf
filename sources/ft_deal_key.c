/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 13:18:52 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/20 21:21:59 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_projection_key(int key, t_map *map)
{
	if (key == P_1)
		map->projection = (map->projection != 1 ? 1 : 0);
	else if (key == P_2)
		map->projection = (map->projection != 2 ? 2 : 0);
	else
		map->projection = 0;
}

static void	ft_zoom_key(int key, t_map *map)
{
	if (key == PLUS)
		map->zoom += 1;
	else
		map->zoom -= 1;
}

static void	ft_z_key(int key, t_map *map)
{
	if (key == Z)
		map->z += 1;
	else
		map->z -= 1;
}

static void	ft_move_key(int key, t_map *map)
{
	if (key == ARROW_UP)
		map->y_shift -= 10;
	else if (key == ARROW_DOWN)
		map->y_shift += 10;
	else if (key == ARROW_LEFT)
		map->x_shift -= 10;
	else
		map->x_shift += 10;
}

int			ft_deal_key(int key, t_map *map)
{
	if (key == ESC)
		ft_free_list(map->head, 0);
	else if (key == W || key == S || key == A
			|| key == D || key == Q || key == E)
		ft_rotation_key(key, map);
	else if (key == P_1 || key == P_2 || key == P_3)
		ft_projection_key(key, map);
	else if (key == MINUS || key == PLUS)
		ft_zoom_key(key, map);
	else if (key == Z || key == X)
		ft_z_key(key, map);
	else if (key == ARROW_DOWN || key == ARROW_UP || key == ARROW_LEFT || key == ARROW_RIGHT)
		ft_move_key(key, map);
	else if (key == S_1 || key == S_2 || key == S_3)
		ft_spectrum_key(key, map);
	else
		return (0);
	ft_create_image(map, *(map->mlx));
	return (0);
}
