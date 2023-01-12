/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_initial.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:30:17 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/12 12:36:29 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "utils.h"
#include "./get_next_line/get_next_line.h"

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

void	check_screen_size(char **av)
{
	int		fd;
	char	*str;
	int		lines;
	int		cols;
	
	lines = 0;
	cols = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		merr(ERRNOF);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		free(str);
		lines++;
		cols++;
	}
	close(fd);
	if ((PXL * lines) > MAX_H || (PXL * cols) > MAX_W)
		merr(ERROUTRANGE);
	if ((PXL * lines) < MIN_H && (PXL * cols) < MIN_W)
		merr(ERRMINRANGE);
}

void	open_map(t_map **map, t_map **cpy, char **av)
{
	int		fd;

	check_screen_size(av);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		merr(ERRNOF);
	*map = get_map(fd);
	close(fd);
	*cpy = cpy_map(*map);
}