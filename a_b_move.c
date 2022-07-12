#include "include/push_swap.h"

// Stack a and stack b reverse rotate at the same time
void    rrr_movement(t_data **stack_a, t_data **stack_b)
{
    if (!(*stack_a)|| !stack_a || !(*stack_b) || !stack_b)
        return ;
    ft_rrotate_a(stack_a);
    ft_rrotate_b(stack_b);
}

// Stack a and stack b swap at the same time
void    ss_movement(t_data **stack_a, t_data **stack_b)
{
    if (!(*stack_a) || !stack_a || !(*stack_b) || !stack_b)
        return ;
    ft_swap_a(stack_a);
    ft_swap_b(stack_b);
}

// int main(int ac, char **av)
// {
//     t_data  *a;
//     t_data  *b;

//     a = convert_av(&a, av);
//     b = convert_av(&b, av);
//     ss_movement(&a, &b);
//     if (ac > 1)
//     {
//         while (a)
//         {
//             printf("%d\n", a->content);
//             a = a->next;
//         }
//         write(1, "\n", 1);
//         while (b)
//         {
//             printf("%d\n", b->content);
//             b = b->next;
//         }
//     }
//     return (0);
// }