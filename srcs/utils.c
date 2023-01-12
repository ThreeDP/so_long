/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:27:08 by dapaulin          #+#    #+#             */
/*   Updated: 2022/12/28 10:27:08 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_path(char c)
{
	if (c == '0')
		return (1);
	return (0);
}

int	is_wall(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

int	is_collec(char c)
{
	if (c == 'C')
		return (1);
	return (0);
}

int	is_exit(char c)
{
	if (c == 'E')
		return (1);
	return (0);
}

int	is_player(char c)
{
	if (c == 'P')
		return (1);
	return (0);
}

size_t	all_wall(char *wall)
{
	size_t	i;

	i = 0;
	while (is_wall(wall[i]))
		i++;
	return (i);
}
