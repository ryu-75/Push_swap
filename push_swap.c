#include "include/push_swap.h"

void    print_lst(t_data **stack)
{
    if (!stack || !(*stack))
        return ;
    while ((*stack) != NULL)
    {
        printf("%d\n", (*stack)->content);
        (*stack) = (*stack)->next;
    }
}

int main(int ac, char **av)
{
    t_data  *a;
    int max;
    a = convert_av(&a, av);
    // print_lst(&a);
    max = ft_lstmax(&a);
    // print_lst(&a);
    if (ac > 1)
        printf("%d\n", max);

        // printf("----- STACK A -----\n\n");
        // while (a)
        // {
        //     printf("\t%d\n\n", a->content);
        //     a = a->next;
        // }
        // printf("----- STACK B -----\t\n\n");
        // while (b)
        // {
        //     printf("\t%d\n\n", b->content);
        //     b = b->next;
        // }
    return (0);
}