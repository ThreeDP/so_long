################  COLORS	##################
L_RED			=			\033[0;31m
L_REDB			=			\033[1;31m
L_WHITE			=			\033[0;37m
L_WHITEB		=			\033[1;37m
L_YELLOW		=			\033[0;33m
L_YELLOWB		=			\033[1;33m
L_GREEN			=			\033[0;32m
L_GREENB		=			\033[1;32m
################ CONFIG		##################
NAME			=			so_long
SRCS			=			so_long.c
FLAGS 			= 			-Wall -Werror -Wextra
MLX				=			-Imlx -lXext -lX11 -lm -lz
################ RULES		##################

all: $(NAME)

%.o: %.c
	$(CC) -I/usr/include -Imlx -O3 -c $< -o $@

$(NAME): $(SRCS:.c=.o)
	$(CC) $(SRCS:.c=.o) -Lmlx -lmlx_Linux -L/usr/lib $(MLX) -o $(NAME)