/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:09:17 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/23 19:31:24 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"
#include "so_long_bonus.h"
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
	clean_data(info->enemy);
	if (info->floor)
	{
		free(info->floor);
		info->floor = NULL;
	}
	if (info->move)
	{
		free(info->move);
		info->move = NULL;
	}
}

void	clean_initial(t_info *info, t_map *cpy, int err)
{
	clean_elems(info->mlx, info);
	clear_map(&info->map, free);
	clear_map(&cpy, free);
	clean_all_data(info);
	clean_window(info);
	cpy = NULL;
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
	if (info->move->img)
	{
		mlx_destroy_image(mlx, info->move->img);
		info->move->img = NULL;
	}
	destroy_elems(info->mlx, info->enemy);
	destroy_elems(info->mlx, info->exit);
	destroy_elems(info->mlx, info->wall);
	destroy_elems(info->mlx, info->collec);
	while (i < 4)
		destroy_elems(info->mlx, info->player[i++]);
}
