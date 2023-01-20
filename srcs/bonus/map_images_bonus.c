/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:42:35 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/20 19:41:06 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"
#include "so_long_bonus.h"
#include "../libft/srcs/libft.h"

void	set_elem(void *mlx, t_data *elem, char *path, t_info *info)
{
	elem->w = 0;
	elem->h = 0;
	elem->img = mlx_xpm_file_to_image(mlx, path, &elem->w, &elem->h);
	if (!elem->img)
		end_game_err(info);
}

void	set_player_imgs(t_info *info)
{
	set_elem(info->mlx, info->player[0][0], PATHP_W0, info);
	set_elem(info->mlx, info->player[0][1], PATHP_W1, info);
	set_elem(info->mlx, info->player[0][2], PATHP_W2, info);
	set_elem(info->mlx, info->player[0][3], PATHP_W3, info);
	set_elem(info->mlx, info->player[1][0], PATHP_A0, info);
	set_elem(info->mlx, info->player[1][1], PATHP_A1, info);
	set_elem(info->mlx, info->player[1][2], PATHP_A2, info);
	set_elem(info->mlx, info->player[1][3], PATHP_A3, info);
	set_elem(info->mlx, info->player[2][0], PATHP_S0, info);
	set_elem(info->mlx, info->player[2][1], PATHP_S1, info);
	set_elem(info->mlx, info->player[2][2], PATHP_S2, info);
	set_elem(info->mlx, info->player[2][3], PATHP_S3, info);
	set_elem(info->mlx, info->player[3][0], PATHP_D0, info);
	set_elem(info->mlx, info->player[3][1], PATHP_D1, info);
	set_elem(info->mlx, info->player[3][2], PATHP_D2, info);
	set_elem(info->mlx, info->player[3][3], PATHP_D3, info);
}

void	set_elems(t_info *info)
{
	set_player_imgs(info);
	set_elem(info->mlx, info->wall[0], PATHW_0, info);
	set_elem(info->mlx, info->wall[1], PATHW_1, info);
	set_elem(info->mlx, info->wall[2], PATHW_2, info);
	set_elem(info->mlx, info->wall[3], PATHW_3, info);
	set_elem(info->mlx, info->floor, PATHF, info);
	set_elem(info->mlx, info->move, PATHM, info);
	set_elem(info->mlx, info->collec[0], PATHC_0, info);
	set_elem(info->mlx, info->collec[1], PATHC_1, info);
	set_elem(info->mlx, info->collec[2], PATHC_2, info);
	set_elem(info->mlx, info->collec[3], PATHC_3, info);
	set_elem(info->mlx, info->exit[0], PATHE_0, info);
	set_elem(info->mlx, info->exit[1], PATHE_1, info);
	set_elem(info->mlx, info->exit[2], PATHE_2, info);
	set_elem(info->mlx, info->exit[3], PATHE_3, info);
}

void	put_images(t_info *d, char *cols, int y, int time)
{
	int			i;
	int			x;
	int			l;
	static int	a;

	i = 0;
	x = 0;
	l = d->direc;
	while (cols[i])
	{
		if (is_path(cols[i]))
			mlx_put_image_to_window(d->mlx, d->win, d->floor->img, x, y);
		else if (is_wall(cols[i]))
			mlx_put_image_to_window(d->mlx, d->win, d->wall[a]->img, x, y);
		else if (is_collec(cols[i]))
			mlx_put_image_to_window(d->mlx, d->win, d->collec[a]->img, x, y);
		else if (is_exit(cols[i]))
			mlx_put_image_to_window(d->mlx, d->win, d->exit[a]->img, x, y);
		else if (is_player(cols[i]))
			mlx_put_image_to_window(d->mlx, d->win, d->player[l][a]->img, x, y);
		x += PXL;
		i++;
	}
	a = time_anim(a, time);
}

int	put_in_window(t_info *info)
{
	int		y;
	t_map	*map;
	char	*walk;

	y = 0;
	walk = NULL;
	map = info->map;
	while (map)
	{
		put_images(info, map->cols, y, info->time);
		y += PXL;
		if (!map->next)
			break ;
		map = map->next;
	}
	walk = ft_itoa(info->walk);
	mlx_put_image_to_window(info->mlx, info->win, info->move->img, 12, 4);
	mlx_string_put(info->mlx, info->win, 15, 15, 0, walk);
	free(walk);
	return (0);
}
