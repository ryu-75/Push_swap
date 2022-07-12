#include "include/push_swap.h"

int main(int ac, char **av)
{
    t_data  *a;
    t_data  *b;

    a = convert_av(&a, av);
    b = convert_av(&b, av);
    rrr_movement(&a, &b);
    if (ac > 1)
    {
        printf("----- STACK A -----\n\n");
        while (a)
        {
            printf("\t%d\n\n", a->content);
            a = a->next;
        }
        printf("----- STACK B -----\t\n\n");
        while (b)
        {
            printf("\t%d\n\n", b->content);
            b = b->next;
        }
    }
    return (0);
}