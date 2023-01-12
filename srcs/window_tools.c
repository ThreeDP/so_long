/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 03:42:07 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/12 01:53:01 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "utils.h"
#include "so_long.h"
#include "./libft/srcs/libft.h"

void	my_swap(char *p, char *w, int *c)
{
	char	x;

	x = '0';
	if (*w == 'C')
	{
		*w = '0';
		*c -= 1;
	}
	else if (*w == 'E' && *c == 0)
		*w = '0';
	x = *p;
	*p = *w;
	*w = x;
}

int end_game(t_info *info)
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
	char x;
	int		pos;
	t_map	*map;
	t_map	*back;
	t_map	*next;

	if (keycode == ESC)
		end_game(info);
	map = info->map;
	pos = find_player(&map, 'P');
	if (map->back)
		back = map->back;
	else
		back = map;
	if (next->next)
		next = map->next;
	else
		next = map;
	info->walk++;
	printf("\n%i\t%i\t%i\n", keycode, info->c, info->walk);
	if (keycode == A && !(map->cols[pos - 1] == '1') && (!(map->cols[pos - 1] == 'E') || info->c == 0))
		my_swap(&map->cols[pos], &map->cols[pos - 1], &info->c);
	else if (keycode == D && !(map->cols[pos + 1] == '1') && (!(map->cols[pos + 1] == 'E') || info->c == 0))
		my_swap(&(map->cols[pos]), &(map->cols[pos + 1]), &info->c);
	else if (keycode == W && !(next->cols[pos] == '1') && (!(next->cols[pos] == 'E') || info->c == 0))
		my_swap(&(map->cols[pos]), &(next->cols[pos]), &info->c);
	else if (keycode == S && !(back->cols[pos] == '1') && (!(back->cols[pos] == 'E') || info->c == 0))
		my_swap(&(map->cols[pos]), &(back->cols[pos]), &info->c);
	return (0);
}

void	set_elem(void *mlx, t_data *elem, char *path)
{
	elem->w = 0;
	elem->h = 0;
	elem->img = mlx_xpm_file_to_image(mlx, path, &elem->w, &elem->h);
	
}

void	set_elems(t_info *info)
{
	set_elem(info->mlx, info->player, PATHP);
	set_elem(info->mlx, info->wall, PATHW);
	set_elem(info->mlx, info->floor, PATHF);
	set_elem(info->mlx, info->collec, PATHC);
	set_elem(info->mlx, info->exit, PATHE);
}

int    draw_img(t_info *info)
{
	int i;
	int	x;
	int y;
	t_map	*map;
	
	y = 0;
	x = 0;
	map = info->map;
	while (map)
	{
		x = 0;
		i = 0;
		while (map->cols[i])
		{
			if ('0' == map->cols[i])
				mlx_put_image_to_window(info->mlx, info->win, info->floor->img, x, y);
			else if ('1' == map->cols[i])
				mlx_put_image_to_window(info->mlx, info->win, info->wall->img, x, y);
			else if ('C' == map->cols[i])
				mlx_put_image_to_window(info->mlx, info->win, info->collec->img, x, y);
			else if ('E' == map->cols[i])
				mlx_put_image_to_window(info->mlx, info->win, info->exit->img, x, y);
			else if ('P' == map->cols[i])
				mlx_put_image_to_window(info->mlx, info->win, info->player->img, x, y);
			x += PXL;
            i++;
		}
		i++;
		y += PXL;
		if (!map->next)
			break ;
		map = map->next;
	}
	return (0);
}



void	start_game(t_map *map, t_info *info)
{
	int		created;
	
	created = 0;
	info->map = map;
	info->mlx = mlx_init();
	if (!created)
	{
		set_elems(info);
		created = 1;
	}
    info->win = mlx_new_window(info->mlx, PXL * map->n_cols, PXL * info->n_lines, "so_long");
	mlx_hook(info->win, 17, 0L, end_game, info);
	mlx_key_hook(info->win, key_hook, info);
	mlx_loop_hook(info->mlx, &draw_img, info);
	if (map)
		mlx_loop(info->mlx);
}
