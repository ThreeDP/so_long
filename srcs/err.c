/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 04:38:55 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/08 06:53:48 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"
#include "libft/srcs/libft.h"

void    merr(char *err)
{
    write(2, ERR, 6);
    write(2, err, ft_strlen(err));
    exit(1);
}

void    handle_err(t_map **map, t_info **info)
{
    char    err;
    
    err = (*info)->err;
    clear_map(map, free);
    if ((*info))
        free((*info));
    if (err == 'P')
        merr(ERRPLAYER);
    else if (err == 'E')
        merr(ERREXIT);
    else if (err == 'W')
        merr(ERRWALL);
    else if (err == 'C')
        merr(ERRCOLLEC);
    else if (err == 'S')
        merr(ERRSHAPE);
    else if (err == 'F')
        merr(ERRPHATH);
}