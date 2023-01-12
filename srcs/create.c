/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:30:17 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/12 02:16:39 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "utils.h"

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
	info->map = NULL;
	info->exit = (t_data *) malloc(sizeof(t_data));
	info->collec = (t_data *) malloc(sizeof(t_data));
	info->wall = (t_data *) malloc(sizeof(t_data));
	info->floor = (t_data *) malloc(sizeof(t_data));
	info->player = (t_data *) malloc(sizeof(t_data));
	return (info);
}
