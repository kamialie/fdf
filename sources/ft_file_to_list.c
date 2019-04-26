/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgyles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:36:02 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/20 19:39:18 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_lst	*ft_new_lst(char **line_in)
{
	t_lst	*new;

	if ((new = (t_lst *)malloc(sizeof(*new))) == NULL || line_in == NULL)
		return (NULL);
	new->line = line_in;
	new->next = NULL;
	return (new);
}

static void		ft_add_back_line(t_lst **head, t_lst *new)
{
	t_lst *cur;

	if (*head == NULL)
		*head = new;
	else
	{
		cur = *head;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
	}
}

static int		ft_get_map_height(t_lst *head)
{
	int count;

	count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return (count);
}

static int		ft_get_map_width(t_lst *head)
{
	int count;

	count = 0;
	while (head->line[count] != NULL)
		count++;
	return (count);
}

t_lst			*ft_file_to_lst(t_map *map, int fd)
{
	int		check;
	char	*line;
	t_lst	*new;
	t_lst	*head;

	head = NULL;
	while ((check = get_next_line(fd, &line)))
	{
		if (check == -1)
			ft_error(1);
		if ((new = ft_new_lst(ft_strsplit(line, ' '))) == NULL)
			return (NULL);
		ft_add_back_line(&head, new);
		free(line);
	}
	if (head == NULL)
		ft_error(2);
	map->height = ft_get_map_height(head);
	map->width = ft_get_map_width(head);
	map->zoom = (WIN_WIDTH / map->width) / 2;
	return (head);
}
