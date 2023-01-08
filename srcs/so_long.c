/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:15:10 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/07 19:57:30 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include "./libft/srcs/libft.h"
#include "so_long.h"
#include "utils.h"

void    draw_img(t_data *img, t_data *img1, void *mlx, void *mlx_win,  const char *mapy)
{
	int i;
	int	x;
	int y;
	
	i = 0;
	y = 0;
	while (mapy[i])
	{
		x = 0;
		while (mapy[i] != '\n')
		{
			if ('p' == mapy[i])
				mlx_put_image_to_window(mlx, mlx_win, img1->img, x, y);
			if ('1' == mapy[i])
				mlx_put_image_to_window(mlx, mlx_win, img->img, x, y);	
			x += img->img_w;
            i++;
		}
		i++;
		y += img->img_h;
        
	}
}

void	create_img(t_data *data, void *mlx, char *path)
{	
    data->img_path = path;
    data->img = mlx_xpm_file_to_image(mlx, data->img_path, &data->img_w, &data->img_h);
}

int main(int ac, char **av)
{
	int		fd;
    void	*mlx;
    void	*mlx_win;
    t_list	*map;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (!fd)
		return (1);
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "so_long");
    map = get_map(fd);
	
    create_img(map->content, mlx, "./textures/players/t-02.xpm");
    draw_img(map->content, map->content,  mlx, mlx_win, MAPY);
    mlx_loop(mlx);
}

