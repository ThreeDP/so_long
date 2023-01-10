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

# define PXL 40

# define ERR "Error\n"
# define ERRPLAYER "No player in the map!\n"
# define ERREXIT "No exit in the map!\n"
# define ERRWALL "The wall is broken!\n"
# define ERRCOLLEC "No collecs in the map!\n"
# define ERRSHAPE "Map in wrong shape!\n"
# define ERRPHATH "No valid path!\n"

typedef struct  s_data {
	void	*img;
	char	*img_path;
	int		img_w;
	int		img_h;
}               t_data;

typedef struct a_map
{
	int             line;
	char            *cols;
	size_t          amount_cols;
	struct a_map    *back;
	struct a_map    *next;
}               t_map;

typedef struct s_info 
{
	int     p;
	int     e;
	int     c;
	int     walk;
	char    err;
	int		n_lines;
}               t_info;

// Map utils
t_map       *cpy_map(t_map *map);
void        clear_map(t_map **map, void (*del)(void *));
void        ft_mapadd_back(t_map **map, t_map *new);
t_map       *ft_maplast(t_map *map);
t_map       *get_map(int fd);

// Created Structs
t_map       *ft_mapnew(int line, char *cols, size_t amount_cols);
t_info      *ft_newinfo(void);

// Game tools
int			find_player(t_map **map, char c);

// Game windows
void		start_game(t_map *map, t_info *info);

// Validations
int         map_validation(t_map *map, t_info **info);
int         path_validation(t_map *map, t_info *info);
size_t  	search_elems(char *str, t_info **info);
void        map_path(t_map *map, int x);

// Error Handle
void        merr(char *err);
void        handle_err(t_map **map, t_info **info);

// Utils
size_t  	all_wall(char *wall);

#endif
