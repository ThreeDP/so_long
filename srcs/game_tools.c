/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:43:17 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/17 16:55:24 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/srcs/libft.h"

void	my_swap(char *p, char *w, int *c, int *e)
{
	char	x;

	if (*w == 'C')
	{
		*w = '0';
		*c -= 1;
	}
	else if (*w == 'E' && *c == 0)
	{
		*w = '0';
		*e = 0;
	}
	x = *p;
	*p = *w;
	*w = x;
}

void	move_player(int pos, t_info *info, int x, char *new_pos)
{
	char		*map_cols;
	static int	l;

	map_cols = info->map->cols;
	if (info->direc != l)
	{
		l = info->direc;
	}
	else if (new_pos[x] != '1' && (new_pos[x] != 'E' || info->c == 0))
	{
		my_swap(&map_cols[pos], &new_pos[x], &info->c, &info->e);
		info->walk++;
	}
	if (!info->c && !info->e)
	{
		write(1, "You Win!\n", 9);
		end_game(info);
	}
}

int	find_player(t_map **map, char c)
{
	char	*cols;

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
