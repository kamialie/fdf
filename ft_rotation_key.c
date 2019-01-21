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
	if (key == 91 || key == 84)
	{
		if (key == 91)
			map->alpha += 5;
		else
			map->alpha -= 5;
	}
	if (key == 86 || key == 88)
	{
		if (key == 86)
			map->beta += 5;
		else
			map->beta -= 5;
	}
	if (key == 89 || key == 92)
	{
		if (key == 89)
			map->delta += 5;
		else
			map->delta -= 5;
	}
}
