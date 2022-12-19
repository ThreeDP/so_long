#ifndef SO_LONG_H
# define SO_LONG_H

# define W_WIDTH 720
# define w_HEIGHT 420
# define START_X 0
# define START_Y 0

typedef struct  s_data {
    void    *img;
    char    *img_path;
    int     img_w;
    int     img_h;
    char    *addr;
    int     bpp;
    int     llen;
    int     endian;
}               t_data;

