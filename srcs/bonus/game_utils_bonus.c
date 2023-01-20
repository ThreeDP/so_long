/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:57:16 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/20 19:27:41 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../libft/srcs/libft.h"
#include "../get_next_line/get_next_line.h"
#include "utils_bonus.h"

int	check_screen_size(char **av, int lines, int cols, int c)
{
	int		fd;
	char	*str;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		merr(ERR, 2, ERRA);
	str = get_next_line(fd);
	cols = ft_strlen(str);
	while (1)
	{
		if (!str)
			break ;
		if (ft_strlen(str) == 1 && *str == '\n')
			c = ERRS;
		if ((size_t)cols < ft_strlen(str))
			cols = ft_strlen(str);
		free(str);
		lines++;
		str = get_next_line(fd);
	}
	if ((PXL * lines) > MAX_H || (PXL * cols) > MAX_W)
		c = ERRO;
	if ((PXL * lines) < MIN_H && (PXL * cols) < MIN_W)
		c = ERRN;
	return (c);
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

void	end_game_err(t_info *info)
{
	clean_elems(info->mlx, info);
	clean_all_data(info);
	clear_map(&info->map, free);
	mlx_destroy_display(info->mlx);
	if (info->mlx)
		free(info->mlx);
	if (info)
		free(info);
	merr(ERR, 2, ERRA);
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
		end_game_err(info);
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
