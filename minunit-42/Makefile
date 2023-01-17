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
DIR_OUTS		=			./outs/
DIR				=			../srcs/
SRCSSL			=			$(addprefix $(DIR), create_initial.c err.c game_tools.c map_images.c map_utils.c map_validation.c  utils.c window_tools.c)
SRCS 			= 			$(wildcard ./*.c)
RUN				=			$(addprefix $(DIR_OUTS), $(srcs))
GNL				=			$(DIR)get_next_line/get_next_line.c $(DIR)/get_next_line/get_next_line_utils.c
LIBFT_PATH		=			../srcs/libft/srcs/

HEADERS_TEST 	= 			minunit.h
MLX				=			-I$(DIR)mlx_linux -lXext -lX11 -lm -lz
MLX_ALL			=			-L $(DIR)mlx_linux -l mlx_Linux -L /usr/lib $(MLX)
HEADERS			=			../srcs/utils.h
TESTS			=			get_map check_extension cpy_map map_path map_validation path_validation 
FLAGS 			= 			-Wall -Werror -Wextra
################ RULES		##################

all: 		$(SRCS:.c=.o) $(RUN) clean_outs

%.o: 		%.c $(HEADERS)
	@echo  "$(L_YELLOWB)[COMPILE $@]$(L_WHITE)"

$(RUN):
	@echo  "$(L_YELLOWB)[TEST $@]$(L_WHITE)"
	@$@
	@echo  "$(L_WHITEB)"*******************************************************************"$(L_WHITEB)"

norm:
	@cd 		$(DIR) && $(MAKE) $@

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

u:	$(HEADERS)
	$(CC) utils_test.c $(DIR)utils.c $(FLAGS) -o utils.o
	@echo	"$(L_YELLOWB)[RUN utils_test.c]$(L_WHITE)"
	@./utils.o

a: u $(TESTS)

$(TESTS):	$(HEADERS)
	$(MAKE) -C $(LIBFT_PATH) --no-print-directory
	$(CC) 	-g $@_test.c $(SRCSSL) $(GNL) $(MLX_ALL) $(LIBFT_PATH)libft.a $(FLAGS) -o $@.o
	@echo	"$(L_YELLOWB)[RUN $@_test.c]$(L_WHITE)"
	@valgrind -s --track-origins=yes --error-exitcode=42 --leak-check=full ./$@.o