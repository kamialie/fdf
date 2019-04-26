/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:47:53 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/20 21:11:46 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_map_init(int fd)
{
	t_map *map;

	if ((map = (t_map *)malloc(sizeof(*map))) == NULL)
		return (NULL);
	map->base_color = 0x873600;
	map->middle_color = 0x00FF00;
	map->top_color = 0xFFFFFF;
	map->x_center = 0;
	map->y_center = 0;
	map->alpha = 0;
	map->beta = 0;
	map->delta = 0;
	map->zoom = 0;
	map->projection = 1;
	map->z = 2;
	map->x_shift = 0;
	map->y_shift = 0;
	map->mouse_click = 0;
	map->mouse_x = 0;
	map->mouse_y = 0;
	map->head = ft_file_to_lst(map, fd);
	map->z_max = ft_get_max_z(map->head);
	map->z_min = ft_get_min_z(map->head);
	return (map);
}

int		main(int args, char *argv[])
{
	int		fd;
	t_map	*map;
	t_mlx	mlx;

	if (args != 2)
		ft_putstr("usage: ./fdf map\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		map = ft_map_init(fd);
		mlx.mlx_ptr = mlx_init();
		mlx.win_ptr = mlx_new_window(mlx.mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "mlx_21");
		map->mlx = &mlx;
		mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
		mlx.img.img_data = (int *)mlx_get_data_addr(mlx.img.img_ptr,
			&mlx.img.bpp, &mlx.img.size_line, &mlx.img.endian);
		ft_create_image(map, mlx);
		mlx_hook(mlx.win_ptr, 2, 0, &ft_deal_key, map);
		mlx_hook(mlx.win_ptr, 4, 0, &ft_mouse_press, map);
		mlx_hook(mlx.win_ptr, 5, 0, &ft_mouse_release, map);
		mlx_hook(mlx.win_ptr, 6, 0, &ft_mouse_movement, map);
		mlx_loop(mlx.mlx_ptr);
	}
	return (0);
}
