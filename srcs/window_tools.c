/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 03:42:07 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/17 16:55:29 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "utils.h"
#include "so_long.h"
#include "./libft/srcs/libft.h"

int	end_game(t_info *info)
{
	int	i;

	i = 0;
	while (info->map->back)
		info->map = info->map->back;
	mlx_destroy_image(info->mlx, info->floor->img);
	free(info->floor);
	destroy_elems(info->mlx, info->exit);
	destroy_elems(info->mlx, info->wall);
	destroy_elems(info->mlx, info->collec);
	while (i < 4)
		destroy_elems(info->mlx, info->player[i++]);
	clear_map(&info->map, free);
	mlx_clear_window(info->mlx, info->win);
	mlx_destroy_window(info->mlx, info->win);
	mlx_destroy_display(info->mlx);
	free(info->mlx);
	free(info);
	exit(0);
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
		move_player(pos, info, pos, next->cols);
	else if (keycode == D || keycode == RIGHT)
		move_player(pos, info, pos + 1, info->map->cols);
	else if (keycode == S || keycode == DOWN)
		move_player(pos, info, pos, back->cols);
	while (info->map->back)
		info->map = info->map->back;
	return (0);
}

void	start_game(t_map *map, t_info *info)
{
	int	created;
	int	n_lines;
	int	n_cols;

	created = 0;
	n_lines = info->n_lines;
	n_cols = map->n_cols;
	info->map = map;
	info->mlx = mlx_init();
	if (!created)
	{
		set_elems(info);
		created = 1;
	}
	info->win = mlx_new_window(info->mlx, PXL * n_cols, PXL * n_lines, NAME);
	mlx_hook(info->win, 17, 0L, end_game, info);
	mlx_key_hook(info->win, key_hook, info);
	mlx_loop_hook(info->mlx, &put_in_window, info);
	if (map)
		mlx_loop(info->mlx);
	return ;
}
