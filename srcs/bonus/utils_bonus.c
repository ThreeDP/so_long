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
