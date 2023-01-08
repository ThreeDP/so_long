/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:03:31 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/08 03:24:20 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/srcs/libft.h"
#include "utils.h"
#include <stdio.h>

size_t  all_wall(char *wall)
{
    size_t  i;

    i = 0;
    while (is_wall(wall[i]))
        i++;
    return (i);
}

size_t  searching(char *str, t_info **info)
{
    size_t  size;

    size = 0;
    if (!is_wall(str[size]))
        return (0);
    size++;
    while (str[size])
    {
        if (is_collec(str[size]))
            (*info)->c += 1;
        else if (is_exit(str[size]))
            (*info)->e += 1;
        else if (is_player(str[size]))
            (*info)->p += 1;
        else if (is_wall(str[size]) || is_path(str[size]))
        {
            size++;
            continue ;
        }
        else
            break ;
        size++;
    }
    if (!is_wall(str[size - 1]))
        return (0);
    return (size);
}

int map_validation(t_map *map, t_info **info)
{
    int     i;
    size_t  amount_cols;

    i = 0;
    amount_cols = map->amount_cols;
    while (map && map->next)
    {
        if(map->line == 1 && map->amount_cols != all_wall(map->cols))
            return (0);
        else if (map->amount_cols != searching(map->cols, info))
            return (0);
        if(map->amount_cols != amount_cols)
            return (0);
        map = map->next;
    }
    if ((*info)->p != 1)
        return (0);
    if ((*info)->e != 1)
        return (0);
    if(map->amount_cols != all_wall(map->cols))
        return (0);
    return (1);
}