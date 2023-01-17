/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:14:54 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/17 16:27:30 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	time_anim(int anim)
{
	static int	time;

	time++;
	if (anim < 4 && time > 1000)
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
		return (2);
	else if (keycode == D || keycode == RIGHT)
		return (3);
	else if (keycode == S || keycode == DOWN)
		return (0);
	return (direc);
}
