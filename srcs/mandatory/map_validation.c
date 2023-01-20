/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:03:31 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/19 21:32:32 by dapaulin         ###   ########.fr       */
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

int	elems_validation(t_info **info)
{
	if ((*info)->p != 1)
		return ((*info)->err = ERRP, 1);
	if ((*info)->e != 1)
		return ((*info)->err = ERRE, 1);
	if ((*info)->c < 1)
		return ((*info)->err = ERRC, 1);
	return (0);
}

size_t	search_elems(char *str, t_info **info)
{
	size_t	size;

	size = 0;
	if (!is_wall(str[size]))
		return ((*info)->err = ERRW, 0);
	size++;
	while (str[size])
	{
		if (is_collec(str[size]))
			(*info)->c = 1;
		else if (is_exit(str[size]))
			(*info)->e = 1;
		else if (is_player(str[size]))
			(*info)->p = 1;
		else if (is_wall(str[size]) || is_path(str[size]))
			;
		else
			break ;
		size++;
	}
	if (!is_wall(str[size - 1]))
		return ((*info)->err = ERRW, 0);
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
			return (info->err = ERRF, 1);
		map = map->next;
	}
	return (0);
}

int	map_validation(t_info **info)
{
	int		i;
	size_t	n_cols;
	t_map	*map;

	i = 0;
	map = (*info)->map;
	n_cols = map->n_cols;
	while (map && map->next)
	{
		if (map->n_cols != n_cols || !n_cols)
			return ((*info)->err = ERRS, 1);
		if (map->line == 1 && map->n_cols != all_wall(map->cols))
			return ((*info)->err = ERRW, 1);
		else if (map->n_cols != search_elems(map->cols, info))
			return (1);
		map = map->next;
	}
	if (elems_validation(info))
		return (1);
	if (map->n_cols != all_wall(map->cols))
		return ((*info)->err = ERRW, 1);
	if (map->n_cols != n_cols)
		return ((*info)->err = ERRS, 1);
	(*info)->n_lines = map->line;
	return (0);
}




