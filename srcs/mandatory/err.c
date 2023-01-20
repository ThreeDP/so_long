/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 04:38:55 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/20 05:11:31 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"
#include "../libft/srcs/libft.h"

int	print_message(char *str, char *msg)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(msg, 2);
	return (1);
}

int	print_err(char *str, int err)
{
	int ret;

	ret = 0;
	if (err == 'P')
		ret = print_message(str, ERRPLAYER);
	else if (err == 'E')
		ret = print_message(str, ERREXIT);
	else if (err == 'W')
		ret = print_message(str, ERRWALL);
	else if (err == 'C')
		ret = print_message(str, ERRCOLLEC);
	else if (err == 'S')
		ret = print_message(str, ERRSHAPE);
	else if (err == 'F')
		ret = print_message(str, ERRPHATH);
	else if (err == 'O')
		ret = print_message(str, ERROUTRANGE);
	else if (err == 'N')
		ret = print_message(str, ERRMINRANGE);
	return (ret);
}

int	merr(char *str, int code, int err)
{

	if (print_err(str, err))
		exit(code);
	perror(str);
	exit(code);
}

void	handle_err(t_info **info, char **av)
{
	t_map	*cpy;
	int		err;
	t_info	*inf;

	err = 0;
	inf = *info;
	err = open_map(&inf->map, &cpy, av);
	if (err)
		clean_initial(*info, cpy, err);
	err = map_validation(info);
	if (err)
		clean_initial(*info, cpy, err);
	err = path_validation(cpy, *info);
	if (err)
		clean_initial(*info, cpy, err);
	clear_map(&cpy, free);
}