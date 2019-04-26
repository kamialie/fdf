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
	if (key == W || key == S)
	{
		if (key == W)
			map->alpha += 5;
		else
			map->alpha -= 5;
	}
	if (key == Q || key == E)
	{
		if (key == Q)
			map->beta += 5;
		else
			map->beta -= 5;
	}
	if (key == A || key == D)
	{
		if (key == A)
			map->delta += 5;
		else
			map->delta -= 5;
	}
}
