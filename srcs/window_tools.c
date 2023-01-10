/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 03:42:07 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/10 03:49:25 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "utils.h"
#include "so_long.h"

int	key_hook(int keycode, t_map *map)
{
	printf("'%s \t%i'\n", map->cols, keycode);
	return (0);
}

void	start_game(t_map *map, t_info *info)
{
	void	*mlx;
    void	*mlx_win;
	
	mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, PXL * map->amount_cols, PXL * info->n_lines, "so_long");
    mlx_key_hook(mlx_win, key_hook, map);
    mlx_loop(mlx);
}

/*
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
*/