/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:00:29 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/17 20:06:28 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	W = 119,
	S = 115,
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
# define ERRSHAPE "Map in wrong shape or with invalid characters!\n"
# define ERRPHATH "No valid path!\n"
# define ERREXT "Extension not valid!\n"
# define ERRNOF "Map File not reporting or does not exist!\n"
# define ERROUTRANGE "The map overflow the max screen view!\n"
# define ERRMINRANGE "The map is too small!\n"

# define PATHP_0 "./textures/player-0.xpm"
# define PATHP_A0 "./textures/player-a0.xpm"
# define PATHP_A1 "./textures/player-a1.xpm"
# define PATHP_A2 "./textures/player-a2.xpm"
# define PATHP_A3 "./textures/player-a3.xpm"
# define PATHP_D0 "./textures/player-d0.xpm"
# define PATHP_D1 "./textures/player-d1.xpm"
# define PATHP_D2 "./textures/player-d2.xpm"
# define PATHP_D3 "./textures/player-d3.xpm"
# define PATHP_S0 "./textures/player-s0.xpm"
# define PATHP_S1 "./textures/player-s1.xpm"
# define PATHP_S2 "./textures/player-s2.xpm"
# define PATHP_S3 "./textures/player-s3.xpm"
# define PATHP_W0 "./textures/player-w0.xpm"
# define PATHP_W1 "./textures/player-w1.xpm"
# define PATHP_W2 "./textures/player-w2.xpm"
# define PATHP_W3 "./textures/player-w3.xpm"
# define PATHW_0 "./textures/wall-0.xpm"
# define PATHW_1 "./textures/wall-1.xpm"
# define PATHW_2 "./textures/wall-2.xpm"
# define PATHW_3 "./textures/wall-3.xpm"
# define PATHF "./textures/floor.xpm"
# define PATHM "./textures/move.xpm"
# define PATHC_0 "./textures/collec-0.xpm"
# define PATHC_1 "./textures/collec-1.xpm"
# define PATHC_2 "./textures/collec-2.xpm"
# define PATHC_3 "./textures/collec-3.xpm"
# define PATHE_0 "./textures/exit-0.xpm"
# define PATHE_1 "./textures/exit-1.xpm"
# define PATHE_2 "./textures/exit-2.xpm"
# define PATHE_3 "./textures/exit-3.xpm"

typedef struct s_data
{
	void	*img;
	int		w;
	int		h;
}				t_data;

typedef struct a_map
{
	int				line;
	char			*cols;
	size_t			n_cols;
	struct a_map	*back;
	struct a_map	*next;
}				t_map;

typedef struct s_info
{
	int		p;
	int		e;
	int		c;
	char	err;
	int		walk;
	int		n_lines;
	void	*mlx;
	void	*win;
	t_map	*map;
	t_data	*exit[4];
	t_data	*collec[4];
	t_data	*wall[4];
	t_data	*floor;
	t_data	*player[4][4];
	int		direc;
	t_data	*move;

}				t_info;

// Map utils
t_map		*ft_maplast(t_map *map);
void		ft_mapadd_back(t_map **map, t_map *new);
void		clear_map(t_map **map, void (*del)(void *));
t_map		*cpy_map(t_map *map);
t_map		*get_map(int fd);

// Create Initial
t_map		*ft_mapnew(int line, char *cols, size_t n_cols);
t_info		*ft_newinfo(void);
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
int			map_validation(t_map *map, t_info **info);
int			path_validation(t_map *map, t_info *info);
size_t		search_elems(char *str, t_info **info);
void		map_path(t_map *map, int x);
int			check_extension(char const *s1, char const *set);

// Error Handle
void		merr(char *err);
void		handle_err(t_map **map, t_info **info);
int			elems_validation(t_info **info);

// Anime Utils
int			anim_direction(int keycode, int direc);
int			time_anim(int anim);

//Map Control
size_t		all_wall(char *wall);
void		valid_y_axis(t_map **next, t_map **back, t_map *map);
void		destroy_elems(void *mlx, t_data *data[]);

#endif
