/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gradient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 20:44:03 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/20 19:26:53 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	ft_percent(int start, t_point a, t_val val)
{
	double placement;
	double distance;

	if (val.flag == 1)
	{
		placement = a.x - start;
		distance = (double)val.len_x;
	}
	else
	{
		placement = a.y - start;
		distance = (double)val.len_y;
	}
	return (ABS((distance == 0) ? 1.0 : (placement / distance)));
}

static int		ft_get_color(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int				ft_gradient(int start, t_point a, t_val val)
{
	int		red;
	int		blue;
	int		green;
	double	percent;

	if (a.color == val.color)
		return (a.color);
	percent = ft_percent(start, a, val);
	red = ft_get_color((a.color >> 16) & 0xFF,
			(val.color >> 16) & 0xFF, percent);
	green = ft_get_color((a.color >> 8) & 0xFF,
			(val.color >> 8) & 0xFF, percent);
	blue = ft_get_color(a.color & 0xFF, val.color & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}
