/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:30:17 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/08 04:53:54 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "utils.h"

t_map   *ft_mapnew(int line, char *cols, size_t amount_cols)
{
    t_map   *map;

    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->line = line;
    map->cols = cols;
    map->amount_cols = amount_cols ;
    if (cols[map->amount_cols - 1] == '\n')
        map->cols[map->amount_cols -= 1] = '\0';
    map->back = NULL;
    map->next = NULL;
    return (map);
}

t_info  *ft_newinfo(void)
{
    t_info  *info;

    info = (t_info *)malloc(sizeof(t_info));
    if (!info)
        return (NULL);
    info->p = 0;
    info->c = 0;
    info->e = 0;
    info->walk = 0;
    info->err = 'A';
    return (info);  
}