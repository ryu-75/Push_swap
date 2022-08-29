# ------------- [ COMPILER FLAGS ] ------------------ #

PREFIXE			= push_swap
EXEC			= $(PREFIXE)

# ------------- [ IMPORT LIBRARY ] ------------------ #

DEPENDS			= includes/push_swap.h
LBFLAGS			= Libft/*.c

SRC				= $(wildcard src/*.c)

OBJ				= $(SRC:.c=.o)

$(EXEC)			: $(OBJ)
			$(CC) $(CFLAGS) -o $@ $^ $(LBFLAGS)

# --------- [ All files to compile ] ---------------- #

%.o				: %.c $(DEPENDS)
			$(CC) $(CFLAGS) -o $@ -c $<

# ------------ [ Compiler flags ] ------------------- #

CC				= gcc 
CFLAGS			= -g -Wall -Werror -Wextra 

all				: $(EXEC)

# ---------------- [ Delete ] ---------------------- #

clean			: 
	find . -type f | xargs touch
	rm -rf src/*.o

fclean			: clean
	rm -rf $(EXEC)

# ------------ [ Del & Recomp ] -------------------- #

re				: fclean all

.PHONY			: all clean fclean re