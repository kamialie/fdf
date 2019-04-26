/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:32:31 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/20 15:39:52 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_x_axis_rotation(t_point *p, int alpha)
{
	p->y = p->y * cos(RADIAN(alpha)) + p->z * sin(RADIAN(alpha));
}

void	ft_y_axis_rotation(t_point *p, int beta)
{
	p->x = p->x * cos(RADIAN(beta)) + p->z * sin(RADIAN(beta));
}

void	ft_z_axis_rotation(t_point *p, int delta)
{
	int	x_i;
	int	y_i;

	x_i = p->x;
	y_i = p->y;
	p->x = x_i * cos(RADIAN(delta)) - y_i * sin(RADIAN(delta));
	p->y = x_i * sin(RADIAN(delta)) + y_i * cos(RADIAN(delta));
}
