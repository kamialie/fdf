#include <stdio.h>
#include "fdf.h"

int ft_mouse_movement(int x, int y, t_map *map)
{
    if (x <= 0 || x >= WIN_WIDTH || y <= 0 || y >= WIN_HEIGHT)
        return (0);
    if (map->mouse_click == 1)
    {
    }
    else if (map->mouse_click == 2)
    {
        map->beta += (x - map->mouse_x) / 30;
        map->alpha += (y - map->mouse_y) / 30;
    }
    else
        return (0);
    ft_create_image(map, *(map->mlx));;
    return (0);
}

int ft_mouse_release(int button, int x, int y, t_map *map)
{
    (void)x;
    (void)y;
    if (button == 1 || button == 2)
        map->mouse_click = 0;
    return (0);
}

int ft_mouse_press(int button, int x, int y, t_map *map)
{
    if (button == 1)
    {
        map->mouse_x = x;
        map->mouse_y = y;
        map->mouse_click = 1;
    }
    else if (button == 2)
        map->mouse_click = 2;
    return (0);
}
