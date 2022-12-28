#ifndef SO_LONG_H
# define SO_LONG_H

# define W_WIDTH 850
# define W_HEIGHT 408
# define START_X 0
# define START_Y 0

# define MAPY "1111111111111111111111111\n1000000000000000000000001\n1000000000000000000000001\n1000000000000000000000001\n1000000000000000000000001\n1000000000000000000000001\n100000000000p000000000001\n1000000000000000000000001\n1000000000000000000000001\n1000000000000000000000001\n1000000000000000000000001\n1111111111111111111111111"

typedef struct  s_data {
    void	*img;
    char	*img_path;
    int		img_w;
    int		img_h;
}               t_data;

/*MAP UTILS*/
typedef struct  a_map
{
    int             line;
    char            *cols;
    struct a_map    *back;
    struct a_map    *next;
}               t_map;

t_map       *ft_mapnew(int line, char *cols);
void        ft_mapadd_back(t_map **map, t_map *new);
t_map       *ft_maplast(t_map *map);
t_map       *get_map(int fd);

#endif
