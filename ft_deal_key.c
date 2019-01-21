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
	if (key == 18)
		map->projection = (map->projection != 1 ? 1 : 0);
	else if (key == 19)
		map->projection = (map->projection != 2 ? 2 : 0);
	else
		map->projection = 0;
}

static void	ft_zoom_key(int key, t_map *map)
{
	if (key == 33)
		map->zoom += 1;
	else
		map->zoom -= 1;
}

static void	ft_z_key(int key, t_map *map)
{
	if (key == 24)
		map->z += 1;
	else
		map->z -= 1;
}

static void	ft_move_key(int key, t_map *map)
{
	if (key == 126)
		map->y_shift -= 10;
	else if (key == 125)
		map->y_shift += 10;
	else if (key == 123)
		map->x_shift -= 10;
	else
		map->x_shift += 10;
}

int			ft_deal_key(int key, t_map *map)
{
	if (key == 53)
		ft_free_list(map->head, 0);
	else if (key == 12 || key == 13 || key == 14
			|| key == 15 || key == 16 || key == 17)
		ft_rotation_key(key, map);
	else if (key == 18 || key == 19 || key == 20)
		ft_projection_key(key, map);
	else if (key == 33 || key == 34)
		ft_zoom_key(key, map);
	else if (key == 24 || key == 27)
		ft_z_key(key, map);
	else if (key == 126 || key == 125 || key == 123 || key == 124)
		ft_move_key(key, map);
	else if (key == 23 || key == 22 || key == 26)
		ft_spectrum_key(key, map);
	else
		return (0);
	ft_create_image(map, *(map->mlx));
	return (0);
}
