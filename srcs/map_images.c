/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:42:35 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/12 09:36:06 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "utils.h"
#include "so_long.h"
#include "./libft/srcs/libft.h"

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

void	put_images(t_info *d, char *cols, int y)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (cols[i])
	{
		if (is_path(cols[i]))
			mlx_put_image_to_window(d->mlx, d->win, d->floor->img, x, y);
		else if (is_wall(cols[i]))
			mlx_put_image_to_window(d->mlx, d->win, d->wall->img, x, y);
		else if (is_collec(cols[i]))
			mlx_put_image_to_window(d->mlx, d->win, d->collec->img, x, y);
		else if (is_exit(cols[i]))
			mlx_put_image_to_window(d->mlx, d->win, d->exit->img, x, y);
		else if (is_player(cols[i]))
			mlx_put_image_to_window(d->mlx, d->win, d->player->img, x, y);
		x += PXL;
		i++;
	}
}

int	put_in_window(t_info *info)
{
	int		y;
	t_map	*map;
	char	*walk;

	y = 0;
	map = info->map;
	while (map)
	{
		put_images(info, map->cols, y);
		y += PXL;
		if (!map->next)
			break ;
		map = map->next;
	}
	walk = ft_itoa(info->walk);
	mlx_string_put(info->mlx, info->win, 8, 12, 99999999, walk);
	free(walk);
	return (0);
}