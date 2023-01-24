/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:29:25 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/20 19:29:25 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

int	is_enemy(char c)
{
	if (c == 'V')
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
