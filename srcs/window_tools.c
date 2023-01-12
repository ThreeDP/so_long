/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 03:42:07 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/12 09:50:13 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "utils.h"
#include "so_long.h"
#include "./libft/srcs/libft.h"

int	end_game(t_info *info)
{
	mlx_destroy_image(info->mlx, info->exit->img);
	mlx_destroy_image(info->mlx, info->collec->img);
	mlx_destroy_image(info->mlx, info->wall->img);
	mlx_destroy_image(info->mlx, info->floor->img);
	mlx_destroy_image(info->mlx, info->player->img);
	clear_map(&info->map, free);
	free(info->exit);
	free(info->collec);
	free(info->wall);
	free(info->floor);
	free(info->player);
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
	if (info->map->back)
		back = info->map->back;
	else
		back = info->map;
	if (info->map->next)
		next = info->map->next;
	else
		next = info->map;
	if (keycode == A || keycode == LEFT)
		move_player(pos, info, pos - 1, info->map->cols);
	else if (keycode == W || keycode == UP)
		move_player(pos, info, pos, next->cols);
	else if (keycode == D || keycode == RIGHT)
		move_player(pos, info, pos + 1, info->map->cols);
	else if (keycode == S || keycode == DOWN)
		move_player(pos, info, pos, back->cols);
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
}
