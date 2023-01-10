/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:43:17 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/10 11:28:46 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/srcs/libft.h"

int find_player(t_map **map, char c)
{
    char *cols;

    cols = ft_strchr((*map)->cols, c);
    while (!cols)
    {
        if (!(*map)->next)
            break ;
        *map = (*map)->next;
        cols = ft_strchr((*map)->cols, c);
    }
    if (cols)
        return (cols - (*map)->cols);
    return (0);
}