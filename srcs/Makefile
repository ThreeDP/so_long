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
HEADERS			=			so_long.h
LIBS_PATH		=			./libft/srcs/
GNL_PATH		=			./get_next_line/
SRCS_GNL		=			$(addprefix $(GNL_PATH), get_next_line.c get_next_line_utils.c)

SRCS			=			window_tools.c game_tools.c so_long.c utils.c map_images.c \
							create_initial.c err.c map_utils.c map_validation.c
							
LIBS			=			-L $(LIBS_PATH) -lft
FLAGS 			= 			-Wall -Werror -Wextra
MLX				=			-Imlx_linux -lXext -lX11 -lm -lz
################ RULES		##################

all: libft $(NAME)

%.o: %.c $(HEADERS)
	$(CC) -I /usr/include -I mlx_linux -I $(LIBS_PATH) $(LIBS) -O3 -c $< -o $@

$(NAME): $(SRCS_GNL:.c=.o) $(SRCS:.c=.o)
	$(CC) -g $(SRCS:.c=.o) $(SRCS_GNL:.c=.o) -L mlx_linux -l mlx_Linux -L /usr/lib $(MLX) -I $(LIBS_PATH) $(LIBS) -o $(NAME)

libft:
	$(MAKE) -C $(LIBS_PATH) --no-print-directory

n:
	norminette $(SRCS)

v:
	valgrind --track-origins=yes --error-exitcode=42 --leak-check=full --show-leak-kinds=all ./so_long ../minunit-42/maps_test/valid_map.ber

clean:
	@rm	-f *.o

fclean: clean
	@rm	-f $(NAME)
	@$(MAKE) $@ -C $(LIBS_PATH) --no-print-directory

re: fclean all

.PHONY: libft re fclean clean all

