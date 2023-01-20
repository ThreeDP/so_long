/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:09:17 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/20 16:29:53 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "so_long.h"
#include "../libft/srcs/libft.h"

void	clean_data(t_data *data[])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data[i])
		{
			free(data[i]);
			data[i] = NULL;
		}
		i++;
	}
}

void	clean_all_data(t_info *info)
{
	int	i;

	i = 0;
	while (i < 4)
		clean_data(info->player[i++]);
	clean_data(info->collec);
	clean_data(info->exit);
	clean_data(info->wall);
	if (info->floor)
	{
		free(info->floor);
		info->floor = NULL;
	}
}

void	clean_initial(t_info *info, t_map *cpy, int err)
{
	clean_elems(info->mlx, info);
	clear_map(&info->map, free);
	clear_map(&cpy, free);
	clean_all_data(info);
	clean_window(info);
	if (info)
		free(info);
	merr(ERR, 2, err);
}

void	destroy_elems(void *mlx, t_data *data[])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data[i]->img)
		{
			mlx_destroy_image(mlx, data[i]->img);
			data[i]->img = NULL;
		}
		i++;
	}
}

void	clean_elems(void *mlx, t_info *info)
{
	int	i;

	i = 0;
	if (info->floor->img)
	{
		mlx_destroy_image(mlx, info->floor->img);
		info->floor->img = NULL;
	}
	destroy_elems(info->mlx, info->exit);
	destroy_elems(info->mlx, info->wall);
	destroy_elems(info->mlx, info->collec);
	while (i < 4)
		destroy_elems(info->mlx, info->player[i++]);
}
