/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:03:31 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/17 20:32:27 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/srcs/libft.h"
#include "utils.h"

int	check_extension(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*s;

	if (!s1 || !set)
		return (0);
	j = ft_strlen(set);
	s = ft_strrchr(s1, '/');
	if (!s)
		s = (char *)s1;
	else
		s++;
	i = ft_strlen(s);
	if (i <= 4)
		return (1);
	while (j > 0 && s[i - 1] == set[j - 1])
	{
		i--;
		j--;
	}
	if (j != 0)
		return (1);
	return (0);
}

size_t	search_elems(char *str, t_info **info)
{
	size_t	size;

	size = 0;
	if (!is_wall(str[size]))
		return ((*info)->err += ERRW, 0);
	size++;
	while (str[size])
	{
		if (is_collec(str[size]))
			(*info)->c += 1;
		else if (is_exit(str[size]))
			(*info)->e += 1;
		else if (is_player(str[size]))
			(*info)->p += 1;
		else if (is_wall(str[size]) || is_path(str[size]))
			;
		else
			break ;
		size++;
	}
	if (!is_wall(str[size - 1]))
		return ((*info)->err += ERRW, 0);
	return (size);
}

int	path_validation(t_map *map, t_info *info)
{
	char	*p;
	int		x;

	p = NULL;
	x = find_player(&map, 'P');
	map_path(map, x);
	while (map->back)
		map = map->back;
	while (map)
	{
		if (ft_strchr(map->cols, 'E') || ft_strchr(map->cols, 'C'))
		{
			info->err += ERRF;
			return (1);
		}
		map = map->next;
	}
	return (0);
}

int	map_validation(t_map *map, t_info **info)
{
	int		i;
	size_t	n_cols;

	i = 0;
	n_cols = map->n_cols;
	while (map && map->next)
	{
		if (map->n_cols != n_cols || !n_cols)
			return ((*info)->err += ERRS, 0);
		if (map->line == 1 && map->n_cols != all_wall(map->cols))
			return ((*info)->err += ERRW, 0);
		else if (map->n_cols != search_elems(map->cols, info))
			return ((*info)->err += ERRS, 0);
		map = map->next;
	}
	if (elems_validation(info))
		return (0);
	if (map->n_cols != all_wall(map->cols))
		return ((*info)->err += ERRW, 0);
	if (map->n_cols != n_cols)
		return ((*info)->err += ERRS, 0);
	(*info)->n_lines = map->line;
	return (1);
}

void	map_path(t_map *map, int x)
{
	if (map->cols[x] == '1' || map->cols[x] == 'X' || map->cols[x] == 'S')
		return ;
	if (map->cols[x] == 'E')
	{
		map->cols[x] = 'S';
		return ;
	}
	else
		map->cols[x] = 'X';
	map_path(map->next, x);
	map_path(map->back, x);
	map_path(map, x + 1);
	map_path(map, x - 1);
}
