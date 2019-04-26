/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:37:13 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/20 19:42:41 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(int ernu)
{
	if (ernu == 1)
		ft_putstr("file does not exist\n");
	else if (ernu == 2)
		ft_putstr("empty file\n");
	else
		ft_putstr("not enough RAM\n");
	exit(1);
}
