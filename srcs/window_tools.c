/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 03:42:07 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/17 10:13:06 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "utils.h"
#include "so_long.h"
#include "./libft/srcs/libft.h"

void	destroy_elems(void *mlx, t_data *data[])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(mlx, data[i]->img);
		free(data[i++]);
	}
}

int	end_game(t_info *info)
{
	int	i;

	i = 0;
	mlx_destroy_image(info->mlx, info->floor->img);
	destroy_elems(info->mlx, info->exit);
	destroy_elems(info->mlx, info->wall);
	destroy_elems(info->mlx, info->collec);
	while (i < 4)
		destroy_elems(info->mlx, info->player[i]);
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
	if (info->map->back)
		back = info->map->back;
	else
		back = info->map;
	if (info->map->next)
		next = info->map->next;
	else
		next = info->map;
	if (keycode == A || keycode == LEFT)
	{
		info->pos = 1;
		move_player(pos, info, pos - 1, info->map->cols);
	}
	else if (keycode == W || keycode == UP)
	{
		info->pos = 2;
		move_player(pos, info, pos, next->cols);
	}
	else if (keycode == D || keycode == RIGHT)
	{
		info->pos = 3;
		move_player(pos, info, pos + 1, info->map->cols);
	}
	else if (keycode == S || keycode == DOWN)
	{
		info->pos = 0;
		move_player(pos, info, pos, back->cols);
	}
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
