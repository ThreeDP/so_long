/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 04:38:55 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/20 18:33:40 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"
#include "../libft/srcs/libft.h"

int	set_err(t_info *info, char err, int code)
{
	info->err = err;
	return (code);
}

int	print_message(char *str, char *msg)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(msg, 2);
	return (2);
}

int	print_err(char *str, int err)
{
	int	ret;

	ret = 0;
	if (!str)
		return (0);
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
	else if (err == 'T')
		ret = print_message(str, ERREXT);
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

	err = 0;
	cpy = NULL;
	err = open_map(*info, &cpy, av);
	if (err)
		clean_initial(*info, cpy, (*info)->err);
	err = map_validation((*info)->map, info, err);
	if (err)
		clean_initial(*info, cpy, (*info)->err);
	err = path_validation(cpy, *info);
	if (err)
		clean_initial(*info, cpy, (*info)->err);
	clear_map(&cpy, free);
}
