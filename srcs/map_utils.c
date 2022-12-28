/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:59:26 by dapaulin          #+#    #+#             */
/*   Updated: 2022/12/28 11:59:26 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./get_next_line/get_next_line.h"
#include "utils.h"

t_map   *ft_mapnew(int line, char *cols)
{
    t_map   *map;

    map = malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->line = line;
    map->cols = cols;
    map->back = NULL;
    map->next = NULL;
    return (map);
}

t_map   *ft_maplast(t_map *map)
{
    t_map *tail;

    if (!map)
        return (NULL);
    while (map)
    {
        tail = map;
        map = map->next;
    }
    return (tail);
}

void    ft_mapadd_back(t_map **map, t_map *new)
{
    t_map *tail;

    if (!map || !new)
        return ;
    tail = ft_maplast(*map);
    if (tail == NULL)
        *map = new;
    else
        tail->next = new;
}

t_map   *get_map(int fd)
{
    int     i;
    t_map   *map;
    t_map   *back;
    t_map   *next;
    char    *col;

    i = 1;
    col = get_next_line(fd);
    map = ft_mapnew(i, col);
    if (!map)
        return (NULL);
    next = map;
    back = NULL;
    while (next)
    {
        back = next;
        col = get_next_line(fd);
        next = next->next;
        next = ft_mapnew(i++, col);
        next->back = back;
    }
    return (map);
}