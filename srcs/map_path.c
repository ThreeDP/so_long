/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 07:35:41 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/08 09:18:20 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    map_path(t_map **map, int x, int *c)
{

    if ((*map)->cols[x] == '1' || (*map)->cols[x] == 'X' || (*map)->cols[x] == 'S')
        return ;
    if ((*map)->cols[x] == 'E')
    {
        (*map)->cols[x] = 'S';
        return ;
    }
    else
        (*map)->cols[x] = 'X';
    map_path(&(*map)->next, x, c);
    map_path(&(*map)->back, x, c);
    map_path(map, x + 1, c);
    map_path(map, x - 1, c);
}