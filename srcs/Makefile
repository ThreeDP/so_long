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

LIBS_PATH		=			./libft/srcs/
GNL_PATH		=			./get_next_line/
SRCS_GNL		=			$(addprefix $(GNL_PATH), get_next_line.c get_next_line_utils.c)
MANP			=			./mandatory/
BONP			=			./bonus/
HEADERS			=			$(addprefix $(MANP), so_long.h utils.h) $(addprefix $(LIBS_PATH), libft.h) $(addprefix $(GNL_PATH), get_next_line.h)
HEADERS_B		=			$(addprefix $(BONP), so_long_bonus.h utils_bonus.h) $(addprefix $(LIBS_PATH), libft.h) $(addprefix $(GNL_PATH), get_next_line.h)
SRCS			=			$(addprefix $(MANP), game_tools.c so_long.c utils.c map_images.c \
							create_initial.c err.c map_utils.c map_validation.c map_control.c anim_utils.c \
							memory_free.c game_utils.c)
SRCS_B			=			$(addprefix $(BONP), window_tools_bonus.c game_tools_bonus.c so_long_bonus.c utils_bonus.c \
							map_images_bonus.c create_initial_bonus.c err_bonus.c map_utils_bonus.c map_validation_bonus.c \
							map_control_bonus.c anim_utils_bonus.c)
LIBS			=			-L $(LIBS_PATH) -lft
FLAGS 			= 			-Wall -Werror -Wextra
MLX				=			-lmlx -lXext -lX11
VALGRI			=			valgrind --track-origins=yes --error-exitcode=42 --leak-check=full --show-leak-kinds=all

################ RULES		##################

all: libft $(NAME)

%.o: %.c
	$(CC) -I $(LIBS_PATH) $(FLAGS) -c $< -o $@

$(NAME): $(SRCS_GNL:.c=.o) $(SRCS:.c=.o) $(HEADERS)
	$(CC) -g $(SRCS:.c=.o) $(SRCS_GNL:.c=.o) $(MLX) -I $(LIBS_PATH) $(LIBS) -o $(NAME)

bonus: libft $(SRCS_GNL:.c=.o) $(SRCS_B:.c=.o) $(HEADERS_B)
	$(CC) -g $(SRCS_B:.c=.o) $(SRCS_GNL:.c=.o) $(MLX) -I $(LIBS_PATH) $(LIBS) -o $(NAME)

libft:
	$(MAKE) -C $(LIBS_PATH) --no-print-directory

n:
	norminette $(SRCS) $(HEADERS)

v: 
#	$(VALGRI) ./so_long ./maps/.ber
#	$(VALGRI) ./so_long ./maps/big_map.ber
#	$(VALGRI) ./so_long ./maps/close_collecs.ber
#	$(VALGRI) ./so_long ./maps/exit_close.ber
#	$(VALGRI) ./so_long ./maps/more_exit.ber
#	$(VALGRI) ./so_long ./maps/more_players.ber
#	$(VALGRI) ./so_long ./maps/no_collecs.ber
#	$(VALGRI) ./so_long ./maps/no_exit.ber
#	$(VALGRI) ./so_long ./maps/no_map.ber
#	$(VALGRI) ./so_long ./maps/no_player.ber
#	$(VALGRI) ./so_long ./maps/no_square.ber
#	$(VALGRI) ./so_long ./maps/player_close.ber
#	$(VALGRI) ./so_long ./maps/space_map.ber
#	$(VALGRI) ./so_long ./maps/space_middle_map.ber
#	$(VALGRI) ./so_long ./maps/x_in_left_wall.ber
#	$(VALGRI) ./so_long ./maps/x_in_right_wall.ber
#	$(VALGRI) ./so_long ./maps/x_in_top_wall.ber
#	$(VALGRI) ./so_long ./maps/y_in_down_wall.ber
	@cd			./maps/  && $(VALGRI) ../so_long valid_map.ber

clean:
	@rm	-f $(SRCS:.c=.o) $(SRCS_B:.c=.o)
	@$(MAKE) $@ -C $(LIBS_PATH) --no-print-directory
	@rm -f $(GNL_PATH)/*.o 

fclean: clean
	@rm	-f $(NAME)
	@$(MAKE) $@ -C $(LIBS_PATH) --no-print-directory

re: fclean all

.PHONY: libft re fclean clean all bonus $(MAPS)
