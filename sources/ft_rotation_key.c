/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:30:13 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/20 15:30:16 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotation_key(int key, t_map *map)
{
	if (key == 12 || key == 13)
	{
		if (key == 12)
			map->alpha += 5;
		else
			map->alpha -= 5;
	}
	if (key == 14 || key == 15)
	{
		if (key == 14)
			map->beta += 5;
		else
			map->beta -= 5;
	}
	if (key == 17 || key == 16)
	{
		if (key == 17)
			map->delta += 5;
		else
			map->delta -= 5;
	}
}
