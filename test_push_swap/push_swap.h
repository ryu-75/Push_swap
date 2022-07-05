#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "Libft/libft.h"

// ----------------------------- PARSING ------------------------------------ //

int check_arg(int ac, char **av);
int convert_av(int ac, char **av);

// ------------------------------ UTILS ------------------------------------ //

int ft_nblen(int nb);
int ft_strcmp(const char *s1, const char *s2);
int ft_isnumber(int nb);
int have_num(char *nb);

#endif