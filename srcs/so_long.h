#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "utils.h"

# define MAX_W 1720
# define MAX_H 1080
# define MIN_W 159
# define MIN_H 159

# define NAME "Other Game: A history of nothing"

enum {
	A = 97,
	D = 100,
	W = 115,
	S = 119,
	LEFT = 65361,
	UP = 65362,
	RIGHT = 65363,
	DOWN = 65364,
	ESC = 65307
};

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
# define ERREXT "Extension not valid!\n"
# define ERRNOF "Map File not reporting or does not exist!\n"
# define ERROUTRANGE "The map overflow the max screen view!\n"
# define ERRMINRANGE "The map is too small!\n"

# define PATHP "./textures/player.xpm"
# define PATHW "./textures/wall.xpm"
# define PATHF "./textures/floor.xpm"
# define PATHC "./textures/collec.xpm"
# define PATHE "./textures/exit.xpm"

typedef struct  s_data {
	void	*img;
	int		w;
	int		h;
}               t_data;

typedef struct a_map
{
	int             line;
	char            *cols;
	size_t          n_cols;
	struct a_map    *back;
	struct a_map    *next;
}               t_map;

typedef struct s_info 
{
	int     p;
	int     e;
	int     c;
	char    err;
	int     walk;
	int		n_lines;
	void	*mlx;
	void	*win;
	t_map	*map;
	t_data	*exit;
	t_data	*collec;
	t_data	*wall;
	t_data	*floor;
	t_data	*player;

}               t_info;

// Map utils
t_map       *ft_maplast(t_map *map);
void        ft_mapadd_back(t_map **map, t_map *new);
void        clear_map(t_map **map, void (*del)(void *));
t_map       *cpy_map(t_map *map);
t_map       *get_map(int fd);

// Create Initial
t_map       *ft_mapnew(int line, char *cols, size_t n_cols);
t_info      *ft_newinfo(void);
void		check_screen_size(char **av);
void		open_map(t_map **map, t_map **cpy, char **av);

// Game tools
void		my_swap(char *p, char *w, int *c, int *e);
void		move_player(int pos, t_info *info, int x, char *y);
int			find_player(t_map **map, char c);

// Map Images
void		set_elem(void *mlx, t_data *elem, char *path);
void		set_elems(t_info *info);
void		put_images(t_info *d, char *cols, int y);
int			put_in_window(t_info *info);

// Game windows
void		start_game(t_map *map, t_info *info);
int			end_game(t_info *info);
int			key_hook(int keycode, t_info *info);

// Validations
int         map_validation(t_map *map, t_info **info);
int         path_validation(t_map *map, t_info *info);
size_t  	search_elems(char *str, t_info **info);
void        map_path(t_map *map, int x);
int			check_extension(char const *s1, char const *set);

// Error Handle
void        merr(char *err);
void        handle_err(t_map **map, t_info **info);

#endif
