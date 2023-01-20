/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:57:16 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/20 16:30:55 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/srcs/libft.h"
#include "../get_next_line/get_next_line.h"
#include "utils.h"

int	check_screen_size(char **av)
{
	int		fd;
	char	*str;
	int		lines;
	int		cols;

	lines = 0;
	cols = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		merr(ERR, 2, ERRA);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		free(str);
		lines++;
		cols++;
	}
	if (str)
		free(str);
	close(fd);
	if ((PXL * lines) > MAX_H || (PXL * cols) > MAX_W)
		return (ERRO);
	if ((PXL * lines) < MIN_H && (PXL * cols) < MIN_W)
		return (ERRN);
	return (0);
}

void	clean_window(t_info *info)
{
	if (info->win)
	{
		mlx_clear_window(info->mlx, info->win);
		mlx_destroy_window(info->mlx, info->win);
		info->win = NULL;
	}
	if (info->mlx)
	{
		mlx_destroy_display(info->mlx);
		free(info->mlx);
		info->mlx = NULL;
	}
}

int	end_game(t_info *info)
{
	clean_elems(info->mlx, info);
	clear_map(&info->map, free);
	clean_all_data(info);
	clean_window(info);
	if (info)
	{
		free(info);
		info = NULL;
	}
	exit(0);
}

void	start_game(t_map *map, t_info *info)
{
	int	n_lines;
	int	n_cols;


	n_lines = info->n_lines;
	n_cols = map->n_cols;
	info->map = map;
	info->mlx = mlx_init();
	if (!info->mlx)
		clean_initial(info, NULL, ERRA);
	set_elems(info);
	info->win = mlx_new_window(info->mlx, PXL * n_cols, PXL * n_lines, NAME);
	if (!info->win)
		clean_initial(info, NULL, ERRA);
	mlx_hook(info->win, 17, 0L, end_game, info);
	mlx_key_hook(info->win, key_hook, info);
	mlx_loop_hook(info->mlx, &put_in_window, info);
	mlx_loop(info->mlx);
	return ;
}
