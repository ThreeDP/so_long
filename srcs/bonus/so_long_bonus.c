/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:15:10 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/17 20:57:16 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/srcs/libft.h"
#include "so_long_bonus.h"
#include "utils_bonus.h"

int	main(int ac, char **av)
{
	t_map	*map;
	t_map	*cpy;
	t_info	*info;

	if (ac != 2)
		merr(ERRNOF);
	if (check_extension(av[1], ".ber"))
		merr(ERREXT);
	open_map(&map, &cpy, av);
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
