/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:42:29 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/20 19:32:01 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_line_low(t_point *a, t_val *val, t_mlx mlx)
{
	int i;
	int d;
	int	start;

	val->flag = 1;
	start = a->x;
	d = -val->len_x;
	i = val->length + 1;
	while (i--)
	{
		if ((a->x > 0 && a->x < WIN_WIDTH) && (a->y > 0 && a->y < WIN_HEIGHT))
			mlx.img.img_data[a->x + a->y * WIN_WIDTH] =
				ft_gradient(start, *a, *val);
		a->x += val->dx;
		d += 2 * val->len_y;
		if (d > 0)
		{
			d -= 2 * val->len_x;
			a->y += val->dy;
		}
	}
}

static void	ft_draw_line_high(t_point *a, t_val *val, t_mlx mlx)
{
	int i;
	int d;
	int	start;

	start = a->y;
	d = -val->len_y;
	i = val->length + 1;
	while (i--)
	{
		if ((a->x > 0 && a->x < WIN_WIDTH) && (a->y > 0 && a->y < WIN_HEIGHT))
			mlx.img.img_data[a->x + a->y * WIN_WIDTH] =
				ft_gradient(start, *a, *val);
		a->y += val->dy;
		d += 2 * val->len_x;
		if (d > 0)
		{
			d -= 2 * val->len_y;
			a->x += val->dx;
		}
	}
}

void		ft_draw_line(t_point a, t_point b, t_mlx mlx)
{
	t_val val;

	val.color = b.color;
	val.dx = (b.x - a.x >= 0 ? 1 : -1);
	val.dy = (b.y - a.y >= 0 ? 1 : -1);
	val.len_x = ABS(b.x - a.x);
	val.len_y = ABS(b.y - a.y);
	val.length = MAX(val.len_y, val.len_x);
	val.flag = 0;
	if (val.len_y <= val.len_x)
		ft_draw_line_low(&a, &val, mlx);
	else
		ft_draw_line_high(&a, &val, mlx);
}
