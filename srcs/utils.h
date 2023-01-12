#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

int     is_path(char c);
int     is_wall(char c);
int     is_collec(char c);
int     is_exit(char c);
int     is_player(char c);
size_t	all_wall(char *wall);

#endif
