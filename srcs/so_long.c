/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:15:10 by dapaulin          #+#    #+#             */
/*   Updated: 2022/12/17 17:15:10 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "so_long.h"

void    draw_img(t_data *img, void *mlx, void *mlx_win)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	while (420 >= y)
	{
		x = 0;
		while (720 >= x)
		{
			mlx_put_image_to_window(mlx, mlx_win, img->img, x, y);
			x += img->img_w;
		}
		y += img->img_h;
	}
}

void	create_img(t_data *data, void *mlx, char *path)
{	
    data->img_path = path;
    data->img = mlx_xpm_file_to_image(mlx, data->img_path, &data->img_w, &data->img_h);
}

int main(void)
{
    void	*mlx;
    void	*mlx_win;
    t_list	*map;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "so_long");
    map = ft_lstnew((t_data *) malloc (sizeof(t_data)));
    create_img(map->content, mlx, "./textures/green.xpm");
    draw_img(map->content, mlx, mlx_win);
    map->content = (t_data *) malloc (sizeof(t_data));
    create_img(map->content, mlx, "./textures/test.xpm");
    draw_img(map->content, mlx, mlx_win);
    mlx_loop(mlx);
}
