/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:15:10 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/12 01:56:57 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/srcs/libft.h"
#include "so_long.h"
#include "utils.h"

size_t  all_wall(char *wall)
{
    size_t  i;

    i = 0;
    while (is_wall(wall[i]))
        i++;
    return (i);
}

int main(int ac, char **av)
{
	int		fd;
    t_map	*map;
	t_map	*cpy;
	t_info	*info;

	if (ac != 2)
		return (1);
	if (check_extension(av[1], ".ber"))
		merr(ERREXT);
	fd = open(av[1], O_RDONLY);
	if (!fd)
		return (1);
    map = get_map(fd);
	close(fd);
	cpy = cpy_map(map);
	info = ft_newinfo();
	if (!map_validation(map, &info))
		handle_err(&map, &info);
	if (path_validation(cpy, info))
	{
		clear_map(&cpy, free);
		handle_err(&map, &info);
	}
	else 
		clear_map(&cpy, free);
	start_game(map, info);
	return (0);
}

