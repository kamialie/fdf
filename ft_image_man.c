/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_man.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:17:38 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/20 21:24:03 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_create_image(t_map *map, t_mlx mlx)
{
	ft_bzero(mlx.img.img_data, 4 * WIN_WIDTH * WIN_HEIGHT);
	mlx_clear_window(mlx.mlx_ptr, mlx.win_ptr);
	ft_draw_map(map, mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 20, 20, 0xFFFFFF,
			"motion up/down/left/right: arrows");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 20, 40, 0xFFFFFF,
			"x axis rotatio:            4 / 6 numpad");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 20, 60, 0xFFFFFF,
			"y axis rotation:           2 / 8 numpad");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 20, 80, 0xFFFFFF,
			"z axis rotation:           7 / 9 numpad");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 450, 20, 0xFFFFFF,
			"increase/decrease z:    * or /");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 450, 40, 0xFFFFFF,
			"zoom in/out:            + / - numpad");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 450, 60, 0xFFFFFF,
			"2:1 projection toggle:  1");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 450, 80, 0xFFFFFF,
			"true projection toggle: 2");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 850, 20, 0xFFFFFF,
			"spectrum: 5 / 6 / 7");
}
