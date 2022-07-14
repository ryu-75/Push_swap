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
    int min;
    a = convert_av(&a, av);
    // print_lst(&a);
    min = ft_lstmin(&a);
    // print_lst(&a);
    if (ac > 1)
        // print_lst(&min);
        printf("%d\n", min);
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