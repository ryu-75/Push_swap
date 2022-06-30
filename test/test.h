#ifndef TEST_H
# define TEST_H

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
# include <string.h>
#include "Libft/libft.h"

typedef struct s_tst
{
	char			*content;
    int             nb;
	struct s_tst	*next;
}			t_tst;

#endif
