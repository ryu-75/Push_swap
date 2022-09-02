PREFIXE 				= push_swap
EXEC					= $(PREFIXE)
DEBUG					= yes

SRCS					= src/push_swap.c						\
										src/a_b_move.c 			\
										src/id.c				\
										src/lst_sort.c			\
										src/lst_utils.c			\
										src/min_value.c			\
										src/move.c				\
										src/parsing.c			\
										src/pos.c				\
										src/radix_sort.c		\
										src/sorting_small.c		\
										src/utils_1.c			

OBJ = $(SRCS:.c=.o)

CC = gcc

ifneq ($(DEBUG), yes)
	CFLAGS 				= -Wall -Wextra -Werror -g
else
	CFLAGS 				= -Wall -Wextra -Werror
endif

all: $(EXEC)

$(EXEC) : libft/libft.a $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L libft -lft -o $(EXEC)

libft/libft.a:
	make -C libft

clean:
	rm -rf $(OBJ)
	make clean -C libft

fclean: clean
	rm -rf $(EXEC)
	make fclean -C libft

re: fclean all

norme:
	@echo "\033[35;32m\n\n === NORMINETTE PUSH SWAP === \n\n"
	@norminette src/
	@echo "\033[35;35m\n\n === NORMINETTE CHECKER === \n\n"
	@norminette src_bonus/
	@echo "\033[35;33m\n\n === NORMINETTE INCLUDES === \n\n"
	@norminette includes/

.PHONY: all clean fclean re norme bonus