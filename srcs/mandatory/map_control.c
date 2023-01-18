/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:19:12 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/18 11:56:56 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "so_long.h"
#include "../libft/srcs/libft.h"

void	destroy_elems(void *mlx, t_data *data[])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data[i]->img)
			mlx_destroy_image(mlx, data[i]->img);
		if (data[i])
			free(data[i++]);
	}
}

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
