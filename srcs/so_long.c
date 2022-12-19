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
#include "so_long.h"

/*
void    draw_img(t_data *data, int x, int y)
{

}*/

int main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "so_long");
    printf("\nprimeiro\n");
    img.img_path = "./textures/test.png";
    printf("segundo\n");
    img.img = mlx_xpm_file_to_image(mlx, img.img_path, &img.img_w, &img.img_h);
    printf("terceiro\n");
    //img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.llen, &img.endian);
    //draw_img(&img, START_X, START_Y);
    mlx_put_image_to_window(mlx, mlx_win, img.img, START_X, START_Y);
    printf("quarto\n");
    mlx_loop(mlx);
}
