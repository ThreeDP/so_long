/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:03:31 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/20 19:28:46 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../libft/srcs/libft.h"
#include "utils_bonus.h"

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
	int	err;

	err = 0;
	if ((*info)->p != 1)
		err = set_err(*info, ERRP, 1);
	else if ((*info)->e != 1)
		err = set_err(*info, ERRE, 1);
	else if ((*info)->c < 1)
		err = set_err(*info, ERRC, 1);
	return (err);
}

size_t	search_elems(char *str, t_info **info)
{
	size_t	size;

	size = 0;
	if (!is_wall(str[size]))
		size = set_err(*info, ERRW, 1);
	if (size)
		return (size);
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
		size = set_err(*info, ERRW, 1);
	return (size);
}

int	path_validation(t_map *map, t_info *info)
{
	char	*p;
	int		x;
	int		err;

	p = NULL;
	err = 0;
	x = find_player(&map, 'P');
	map_path(map, x);
	while (map->back)
		map = map->back;
	while (map)
	{
		if (ft_strchr(map->cols, 'E') || ft_strchr(map->cols, 'C'))
			err = set_err(info, ERRF, 1);
		map = map->next;
	}
	return (err);
}

int	map_validation(t_map *map, t_info **info, int err)
{
	int		i;
	size_t	n_cols;

	i = 0;
	n_cols = map->n_cols;
	while (map && map->next)
	{
		if (map->line == 1 && map->n_cols != all_wall(map->cols))
			err = set_err(*info, ERRW, 1);
		if (map->n_cols != n_cols || !n_cols)
			err = set_err(*info, ERRS, 1);
		else if (map->n_cols != search_elems(map->cols, info))
			return (1);
		if (err)
			return (err);
		map = map->next;
	}
	if (elems_validation(info))
		return (1);
	if (map->n_cols != all_wall(map->cols))
		err = set_err(*info, ERRW, 1);
	else if (map->n_cols != n_cols)
		err = set_err(*info, ERRS, 1);
	(*info)->n_lines = map->line;
	return (err);
}
