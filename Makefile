# ------------- [ COMPILER FLAGS ] ------------------ #

PREFIXE			= push_swap
EXEC			= $(PREFIXE)
# INCLUDES		= -I

# ------------- [ IMPORT LIBRARY ] ------------------ #

LBFLAGS			= -L/Libft/

SRC				= push_swap.c			\
					a_b_move.c			\
					a_move.c 			\
					b_move.c 			\
					id.c 				\
					lst_utils_1.c 		\
					lst_utils_2.c 		\
					utils_1.c 			\
					utils_2.c 			\
					sorting_small.c 	\
					pre_sort.c 			\
					parsing.c 			\
					operation.c 		\

OBJ				= $(SRC:.c=.o)

$(EXEC)			: $(OBJ)
			$(CC) -o $(LBFLAGS) $@ $^

# -------------------- [ All files to compile ] ----------------------- #

%.o				: %.c Libft/libft.h
			$(CC) $(CFLAGS) -o $@ -c $<

# ------------ [ Delete .o ] ------------- #

clean			: 
	rm -rf *.o

fclean			: clean
	rm -rf exec

# ------------ [ Exec All ] -------------- #

CC				= gcc 
CFLAGS			= -Wall -Werror -Wextra 

all				: $(EXEC)

.PHONY			: all clean fclean