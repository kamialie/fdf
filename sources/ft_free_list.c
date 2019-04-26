/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:28:28 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/20 19:42:07 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_list(t_lst *head, int flag)
{
	int		i;
	t_lst	*current;
	t_lst	*next;

	current = head;
	while (current != NULL)
	{
		i = -1;
		while (current->line[++i] != NULL)
			free(current->line[i]);
		free(current->line);
		next = current->next;
		free(current);
		current = next;
	}
	if (flag == 1)
		ft_error(3);
	else
		exit(0);
}
