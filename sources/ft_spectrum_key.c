/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spectrum_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 21:14:21 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/20 21:26:07 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_spectrum_key(int key, t_map *map)
{
	if (key == 23)
	{
		map->top_color = 0x6C3483;
		map->base_color = 0xE67E22;
		map->middle_color = 0x1E8449;
	}
	else if (key == 22)
	{
		map->top_color = 0xFF0000;
		map->base_color = 0x0000FF;
		map->middle_color = 0x00FF00;
	}
	else
	{
		map->base_color = 0x873600;
		map->middle_color = 0x00FF00;
		map->top_color = 0xFFFFFF;
	}
}
