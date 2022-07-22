# ------------- [ COMPILER FLAGS ] ------------------ #

PREFIXE			= push_swap
EXEC			= $(PREFIXE)

# ------------- [ IMPORT LIBRARY ] ------------------ #

DEPENDS			= includes/push_swap.h
LBFLAGS			= Libft/*.c

SRC				= $(wildcard *.c)

OBJ				= $(SRC:.c=.o)

$(EXEC)			: $(OBJ)
			$(CC) $(CFLAGS) -o $@ $^ $(LBFLAGS)

# -------------------- [ All files to compile ] ----------------------- #

%.o				: %.c $(DEPENDS)
			$(CC) $(CFLAGS) -o $@ -c $<


# ------------ [ Misc ] -------------- #

CC				= gcc 
CFLAGS			= -Wall -Werror -Wextra 

all				: $(EXEC)

# ------------ [ Delete .o ] ------------- #

clean			: 
	rm -rf *.o

fclean			: clean
	rm -rf $(EXEC)

.PHONY			: all clean fclean