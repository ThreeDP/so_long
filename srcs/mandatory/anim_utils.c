/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:14:54 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/20 11:55:36 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int control_frames(int lines, int cols)
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