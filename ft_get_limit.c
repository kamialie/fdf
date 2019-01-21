/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_limit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 21:02:32 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/20 21:08:55 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_max_z(t_lst *head)
{
	int		i;
	int		z;
	int		max;
	t_lst	*tmp;

	max = 0;
	tmp = head;
	while (tmp != NULL)
	{
		i = -1;
		while (tmp->line[++i] != NULL)
		{
			z = ft_atoi(tmp->line[i]);
			if (z > max)
				max = z;
		}
		tmp = tmp->next;
	}
	return (max);
}

int	ft_get_min_z(t_lst *head)
{
	int		i;
	int		z;
	int		min;
	t_lst	*tmp;

	min = 1000;
	tmp = head;
	while (tmp != NULL)
	{
		i = -1;
		while (tmp->line[++i] != NULL)
		{
			z = ft_atoi(tmp->line[i]);
			if (z < min)
				min = z;
		}
		tmp = tmp->next;
	}
	return (min);
}
