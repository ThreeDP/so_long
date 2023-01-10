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
SRCSSL			=			$(addprefix $(DIR), map_validation.c create.c err.c game_tools.c map_utils.c utils.c)
SRCS 			= 			$(wildcard ./*.c)
RUN				=			$(addprefix $(DIR_OUTS), $(srcs))
GNL				=			$(DIR)/get_next_line/get_next_line.c $(DIR)/get_next_line/get_next_line_utils.c
LIBFT_PATH		=			../srcs/libft/srcs/

HEADERS_TEST 	= 			minunit.h
HEADERS			=			../srcs/utils.h
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

mu:	$(HEADERS)
	$(MAKE) -C $(LIBFT_PATH) --no-print-directory
	$(CC) 	-g map_utils_test.c $(SRCSSL) $(GNL) $(LIBFT_PATH)libft.a $(FLAGS) -o map_utils.o
	@echo	"$(L_YELLOWB)[RUN map_utils_test.c]$(L_WHITE)"
	@valgrind -s --track-origins=yes --error-exitcode=42 --leak-check=full ./map_utils.o

mv:	$(HEADERS)
	$(MAKE) -C $(LIBFT_PATH) --no-print-directory
	$(CC) 	-g map_validation_test.c $(SRCSSL) $(GNL) $(LIBFT_PATH)libft.a $(FLAGS) -o map_validation.o
	@echo	"$(L_YELLOWB)[RUN map_validation_test.c]$(L_WHITE)"
	@valgrind -s --track-origins=yes --error-exitcode=42 --leak-check=full ./map_validation.o

mp:	$(HEADERS)
	$(MAKE) -C $(LIBFT_PATH) --no-print-directory
	$(CC) 	-g map_path_test.c $(SRCSSL) $(GNL) $(LIBFT_PATH)libft.a $(FLAGS) -o map_path.o
	@echo	"$(L_YELLOWB)[RUN map_path_test.c]$(L_WHITE)"
	@valgrind -s --track-origins=yes --error-exitcode=42 --leak-check=full ./map_path.o

cpy:	$(HEADERS)
	$(MAKE) -C $(LIBFT_PATH) --no-print-directory
	$(CC) 	-g cpy_map_test.c $(SRCSSL) $(GNL) $(LIBFT_PATH)libft.a $(FLAGS) -o cpy_map.o
	@echo	"$(L_YELLOWB)[RUN cpy_map_test.c]$(L_WHITE)"
	@valgrind -s --track-origins=yes --error-exitcode=42 --leak-check=full ./cpy_map.o

pv:	$(HEADERS)
	$(MAKE) -C $(LIBFT_PATH) --no-print-directory
	$(CC) 	-g path_validation_test.c $(SRCSSL) $(GNL) $(LIBFT_PATH)libft.a $(FLAGS) -o path_validation.o
	@echo	"$(L_YELLOWB)[RUN path_validation_test.c]$(L_WHITE)"
	@valgrind -s --track-origins=yes --error-exitcode=42 --leak-check=full ./path_validation.o

a: u mu mv mp cpy vp