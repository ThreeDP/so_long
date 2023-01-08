#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "utils.h"

# define W_WIDTH 850
# define W_HEIGHT 408
# define START_X 0
# define START_Y 0

# define ERRP 15
# define ERRE 4
# define ERRW 22
# define ERRC 2
# define ERRS 18
# define ERRF 5

# define ERR "Error\n"
# define ERRPLAYER "No player in the map!"
# define ERREXIT "No exit in the map!"
# define ERRWALL "The wall is broken!"
# define ERRCOLLEC "No collecs in the map!"
# define ERRSHAPE "Map in wrong shape!"
# define ERRPHATH "No valid path!"

typedef struct  s_data {
    void	*img;
    char	*img_path;
    int		img_w;
    int		img_h;
}               t_data;

typedef struct s_info 
{
    int     p;
    int     e;
    int     c;
    int     walk;
    char    err;
}               t_info;

typedef struct a_map
{
    int             line;
    char            *cols;
    size_t          amount_cols;
    struct a_map    *back;
    struct a_map    *next;
}               t_map;

/*create structs*/
t_map       *ft_mapnew(int line, char *cols, size_t amount_cols);
t_info      *ft_newinfo(void);

int     map_validation(t_map *map, t_info **info);

/*MAP UTILS*/
void        clear_map(t_map **map, void (*del)(void *));
void        ft_mapadd_back(t_map **map, t_map *new);
t_map       *ft_maplast(t_map *map);
t_map       *get_map(int fd);

void    merr(char *err);

#endif
