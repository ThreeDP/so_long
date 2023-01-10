/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:15:10 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/10 11:19:02 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/srcs/libft.h"
#include "so_long.h"
#include "utils.h"

int main(int ac, char **av)
{
	int		fd;
    t_map	*map;
	t_map	*cpy;
	t_info	*info;

	if (ac != 2)
		return (1);
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
	start_game(map, info);
	clear_map(&map, free);
	free(info);
	return (0);
}

