/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:15:10 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/20 19:53:40 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/srcs/libft.h"
#include "so_long_bonus.h"
#include "utils_bonus.h"

int	main(int ac, char **av)
{
	int		err;
	t_info	*info;

	info = NULL;
	if (ac != 2)
		merr(ERR, 1, ERRF);
	if (check_extension(av[1], ".ber"))
		merr(ERR, 1, ERRT);
	err = check_screen_size(av, 0, 0, 0);
	if (err)
		merr(ERR, 1, err);
	info = ft_newinfo();
	handle_err(&info, av);
	info->time = control_frames(info->n_lines, info->map->n_cols);
	start_game(info->map, info);
	return (0);
}
