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
SRCS			=			so_long.c
LIBS_PATH		=			./libft
LIBS			=			-L $(LIBS_PATH) -lft
FLAGS 			= 			-Wall -Werror -Wextra
MLX			=			-Imlx -lXext -lX11 -lm -lz
################ RULES		##################

all: $(LIBS_PATH) $(NAME)

%.o: %.c $(HEADERS)
	$(CC) -I/usr/include -Imlx -I $(LIBS_PATH) $(LIBS) -O3 -c $< -o $@

$(NAME): $(SRCS:.c=.o)
	$(CC) $(SRCS:.c=.o) -Lmlx -lmlx_Linux -L/usr/lib $(MLX) -I $(LIBS_PATH) $(LIBS) -o $(NAME)

$(LIBS_PATH):
	$(MAKE) bonus -C $(LIBS_PATH) --no-print-directory

clean:
	@rm	-f *.o

fclean: clean
	@rm	-f $(NAME)
	@$(MAKE) $@ -C $(LIBS_PATH) --no-print-directory

re: fclean all

.PHONY: $(LIBS_PATH)  re fclean clean all

