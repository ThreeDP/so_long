/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_initial.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:30:17 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/20 15:10:38 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "utils.h"
#include "../get_next_line/get_next_line.h"

t_map	*ft_mapnew(int line, char *cols, size_t n_cols)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->line = line;
	map->cols = cols;
	map->n_cols = n_cols ;
	if (cols[map->n_cols - 1] == '\n')
		map->cols[--map->n_cols] = '\0';
	map->back = NULL;
	map->next = NULL;
	return (map);
}

void	new_data(t_data *data[], t_info *info)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data[i] = (t_data *) malloc(sizeof(t_data));
		if (!data[i])
		{
			clean_initial(info, NULL, ERRA);
		}
		data[i]->img = NULL;
		i++;
	}
}

void	init_data(t_info **info)
{
	int i;
	
	i = 0;
	(*info)->mlx = NULL;
	(*info)->win = NULL;
	(*info)->floor = (t_data *) malloc(sizeof(t_data));
	if (!(*info)->floor)
		clean_initial(*info, NULL, ERRA);
	(*info)->floor->img = NULL;
	new_data((*info)->exit, *info);
	new_data((*info)->collec, *info);
	new_data((*info)->wall, *info);
	while (i < 4)
		new_data((*info)->player[i++], *info);
	(*info)->direc = 0;
	(*info)->msg = NULL;
	(*info)->time = 0;
}

t_info	*ft_newinfo(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->p = 0;
	info->c = 0;
	info->e = 0;
	info->err = 'A';
	info->walk = 0;
	info->n_lines = 0;
	init_data(&info);
	return (info);
}
