#include "push_swap.h"

int ft_strlen(int *nb)
{
    int i;

    i = 0;
    while (nb[i] != '\0' && *nb)
        i++;
    return (i);
}

int found_space(int *nb, int c)
{
    while (*nb != '\0' && *nb)
    {
        if (c == *nb++)
            return (1);
    }
    return (0);
}

int is_num(int *nb)
{
    int len;

    len = ft_strlen(nb);
    if (len < INT_MIN || len > INT_MAX)
        return (0);
    while (*nb++)
    {
        if (!(*nb >= 0 && *nb <= 9))
            return (0);
    }
    return (1);
}

void    create_new_element(t_list **nb)
{
    t_list  *tmp_1;
    t_list  *tmp_2;

    tmp_1->nb = nb;
    tmp_2->next = NULL;
    if (tmp_1 == NULL)
        exit_fail();

}



int main(void)
{
    int nb[] = {3, 5, 8, 9, 6, 7, 2};

    printf("%d", is_int(nb));
    return (0);
}
