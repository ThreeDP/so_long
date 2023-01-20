################  COLORS	##################
L_RED			=			\033[0;31m
L_REDB			=			\033[1;31m
L_WHITE			=			\033[0;37m
L_WHITEB		=			\033[1;37m
L_YELLOW		=			\033[0;33m
L_YELLOWB		=			\033[1;33m
L_GREEN			=			\033[0;32m
L_GREENB		=			\033[1;32m
################ TEST FILES	##################
HEADERS_TEST 	= 			minunit.h
DIR_OUTS		=			./outs/
SRCS 			= 			$(wildcard ./*.c)
TESTS			=			get_map check_extension cpy_map map_path map_validation path_validation
################ LIBS		##################
LIBFT_PATH		=			../srcs/libft/srcs/
GNL_PATH		=			../srcs/get_next_line/
MLX				=			-lmlx -lXext -lX11
FLAGS 			= 			-Wall -Werror -Wextra
LIBFT_A			=			$(addprefix $(LIBFT_PATH), libft.a)
GNL				=			$(addprefix $(GNL_PATH), get_next_line.c get_next_line_utils.c)
################ PROJ SRCS	##################
DIR_MAN			=			../srcs/mandatory/
H_MAN			=			$(addprefix $(DIR_MAN), utils.h so_long.h)
SRCS_MAN		=			$(addprefix $(DIR_MAN),game_tools.c utils.c map_images.c \
							create_initial.c err.c map_utils.c map_validation.c map_control.c anim_utils.c \
							memory_free.c game_utils.c)
DIR_BNS			=			../srcs/bonus/
H_BNS			=			$(addprefix $(DIR_BNS), utils_bonus.h so_long_bonus.h)
SRCS_BNS		=			$(addprefix $(DIR_BNS), anim_utils_bonus.c create_initial_bonus.c err_bonus.c \
							game_tools_bonus.c map_control_bonus.c map_images_bonus.c map_utils_bonus.c \
							map_validation_bonus.c  utils_bonus.c window_tools_bonus.c)
################ RULES		##################

all: 		$(SRCS:.c=.o) $(RUN) clean_outs

%.o: 		%.c $(HEADERS)
	@echo  "$(L_YELLOWB)[COMPILE $@]$(L_WHITE)"

clean_outs:
	@rm 		-f $(DIR_OUTS)/*.o

cleant:
	@rm			-f $(SRCS:.c=.o)
	
clean:		cleant
	@cd 		$(DIR) && $(MAKE) $@

fclean: 	cleant
	@rm 		-f run.exec
	@cd 		$(DIR) && $(MAKE) $@

re: fclean clean clean_outs cleant all

um:	$(HEADERS)
	$(CC) utils_test.c $(DIR_MAN)utils.c $(FLAGS) -o utils.o
	@echo	"$(L_YELLOWB)[RUN utils_test.c]$(L_WHITE)"
	@./utils.o

m: um $(TESTS)

$(TESTS):	$(HEADERS)
	$(MAKE) -C $(LIBFT_PATH) --no-print-directory
	$(CC) 	-g $@_test.c $(SRCS_MAN) $(GNL) $(MLX) $(LIBFT_A) $(FLAGS) -o $@.o
	@echo	"$(L_YELLOWB)[RUN $@_test.c]$(L_WHITE)"
	@valgrind -s --track-origins=yes --error-exitcode=42 --leak-check=full ./$@.o