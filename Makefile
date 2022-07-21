# ------------- [ PROJECT FILES ] ------------- #

# set name
PREFIX		= push_swap
NAME		= $(PREFIX)

# set libriaires
LIB_DIR		= libft
LIB			:= $(LIB_DIR)

INC_DIR			= include
INC 			= $(INC_DIR) \
				  $(LIB:%=%/$(INC_DIR)) $(LIB)

# set sources
SRCS		= push_swap.c				\
					operation.c			\
					parsing.c			\
					pre_sort.c			\
					sorting_small.c		\
					utils_1.c			\
					utils_2.c			\
					lst_utils_1.c 		\
					lst_utils_2.c 		\
					id.c 				\
					b_move.c 			\
					a_b_move.c 			\
					a_move.c 			\

OBJS		= $(SRCS:.c=.o)

# ------------ [ COMPILER FLAGS ] ------------- #

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

AR 			= ar rcs

RM			= rm -rf

.c.o = $(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		 $(AR) $(NAME) $(OBJS)

# ---------------- [ RECIPE ] ----------------- #

.PHONY: all clean fclean re

all: $(NAME)

clean: $(RM) $(OBJS)*.o

fclean: clean
		$(RM) $(NAME)

re: fclean all

