/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:59:26 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/17 20:15:18 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/srcs/libft.h"
#include "utils.h"

t_map	*ft_maplast(t_map *map)
{
	t_map	*tail;

	if (!map)
		return (NULL);
	while (map)
	{
		tail = map;
		map = map->next;
	}
	return (tail);
}

void	ft_mapadd_back(t_map **map, t_map *new)
{
	t_map	*tail;
	t_map	*now;

	if (!map || !new)
		return ;
	tail = ft_maplast(*map);
	if (tail == NULL)
		*map = new;
	else
	{
		now = tail;
		tail->next = new;
		tail = tail->next;
		tail->back = now;
	}
}

void	clear_map(t_map **map, void (*del)(void *))
{
	t_map	*head;
	t_map	*next;

	head = *map;
	next = *map;
	while (next)
	{
		head = next->next;
		if (next->cols)
			del(next->cols);
		if (next)
			del(next);
		next = head;
	}
	*map = NULL;
}

t_map	*cpy_map(t_map *map)
{
	char	*cols;
	t_map	*cpy;

	cpy = NULL;
	while (map)
	{
		cols = ft_strdup(map->cols);
		ft_mapadd_back(&cpy, ft_mapnew(map->line, cols, map->n_cols));
		map = map->next;
	}
	while (cpy->back)
		cpy = cpy->back;
	return (cpy);
}

t_map	*get_map(int fd)
{
	int		i;
	t_map	*map;
	char	*col;

	i = 1;
	map = NULL;
	col = (char *)get_next_line(fd);
	while (col)
	{
		ft_mapadd_back(&map, ft_mapnew(i++, col, ft_strlen(col)));
		col = get_next_line(fd);
	}
	return (map);
}
