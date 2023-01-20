/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:15:10 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/20 15:35:17 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/srcs/libft.h"
#include "so_long.h"
#include "utils.h"

int	main(int ac, char **av)
{
	t_info	*info;

	//if (open(PATHP_A0, O_RDONLY) < 0)
	//	return (perror("NO PATH"), 1);
	info = NULL;
	if (ac != 2)
		merr(ERR, 1, ERRF);
	if (check_extension(av[1], ".ber"))
		merr(ERR, 1, ERRT);
	info = ft_newinfo();
	handle_err(&info, av);
	start_game(info->map, info);
	return (0);
}
