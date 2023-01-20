/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:19:12 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/20 14:53:43 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "so_long.h"
#include "../libft/srcs/libft.h"

void	valid_y_axis(t_map **next, t_map **back, t_map *map)
{
	if (map->back)
		(*back) = map->back;
	else
		(*back) = map;
	if (map->next)
		(*next) = map->next;
	else
		(*next) = map;
}

size_t	all_wall(char *wall)
{
	size_t	i;

	i = 0;
	while (is_wall(wall[i]))
		i++;
	return (i);
}

int	open_map(t_info *info, t_map **cpy, char **av)
{
	int		fd;

	check_screen_size(info, av);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (2);
	info->map = get_map(fd);
	close(fd);
	if (!info->map)
		clean_initial(info, *cpy, ERRA);
	*cpy = cpy_map(info->map);
	if (!*cpy)
		clean_initial(info, *cpy, ERRA);
	return (0);
}

void	map_path(t_map *map, int x)
{
	if (map->cols[x] == '1' || map->cols[x] == 'X' || map->cols[x] == 'S')
		return ;
	if (map->cols[x] == 'E')
	{
		map->cols[x] = 'S';
		return ;
	}
	else
		map->cols[x] = 'X';
	map_path(map->next, x);
	map_path(map->back, x);
	map_path(map, x + 1);
	map_path(map, x - 1);
}

int	key_hook(int keycode, t_info *info)
{
	int		pos;
	t_map	*back;
	t_map	*next;

	if (keycode == ESC)
		end_game(info);
	pos = find_player(&info->map, 'P');
	valid_y_axis(&next, &back, info->map);
	info->direc = anim_direction(keycode, info->direc);
	if (keycode == A || keycode == LEFT)
		move_player(pos, info, pos - 1, info->map->cols);
	else if (keycode == W || keycode == UP)
		move_player(pos, info, pos, back->cols);
	else if (keycode == D || keycode == RIGHT)
		move_player(pos, info, pos + 1, info->map->cols);
	else if (keycode == S || keycode == DOWN)
		move_player(pos, info, pos, next->cols);
	while (info->map->back)
		info->map = info->map->back;
	return (0);
}
