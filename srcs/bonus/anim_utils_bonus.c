/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:14:54 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/24 10:44:27 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	time_anim(int anim, int stop)
{
	static int	time;

	if (anim < 4 && ++time > stop)
	{
		time = 0;
		anim++;
	}
	if (anim == 4)
		return (0);
	return (anim);
}

int	anim_direction(int keycode, int direc)
{
	if (keycode == A || keycode == LEFT)
		return (1);
	else if (keycode == W || keycode == UP)
		return (0);
	else if (keycode == D || keycode == RIGHT)
		return (3);
	else if (keycode == S || keycode == DOWN)
		return (2);
	return (direc);
}

int	control_frames(int lines, int cols)
{
	int	time;

	time = 0;
	if ((cols * lines) < 60)
		time = (((PXL * PXL) * MAX_F) / ((cols * PXL) * (lines * PXL))) * 20;
	else if (cols * lines < 600)
		time = (((PXL * PXL) * MAX_F) / ((cols * PXL) * (lines * PXL))) * 35;
	else
		time = (((PXL * PXL) * MAX_F) / ((cols * PXL) * (lines * PXL))) * 130;
	return (time);
}

int	frame_anim(t_info *d, int a, char *cols, int i)
{
	if (is_path(cols[i]))
		mlx_put_image_to_window(d->mlx, d->win, d->floor->img, d->x, d->y);
	else if (is_wall(cols[i]))
		mlx_put_image_to_window(d->mlx, d->win, d->wall[a]->img, d->x, d->y);
	else if (is_collec(cols[i]))
		mlx_put_image_to_window(d->mlx, d->win, d->collec[a]->img, d->x, d->y);
	else if (is_exit(cols[i]))
		mlx_put_image_to_window(d->mlx, d->win, d->exit[a]->img, d->x, d->y);
	else if (is_player(cols[i]))
		mlx_put_image_to_window(d->mlx, d->win, d->player[d->direc][a]->img, \
		d->x, d->y);
	else if (is_enemy(cols[i]))
		mlx_put_image_to_window(d->mlx, d->win, d->enemy[a]->img, d->x, d->y);
	return (PXL);
}