#include "push_swap.h"

void    ft_rotate(a_list **stack_a, char *num)
{
    a_list  *tmp;

    tmp->next = NULL;
    if (!(*stack_a) || !stack_a || !(*stack_a)->next)
        return ;
    (*stack_a)->previous->next = NULL;    // 4 8 6 7 9
    tmp = ft_lstlast(*stack_a); // tmp = 9
    (*stack_a)->previous = tmp;     // 9
    (*stack_a)->previous = (*stack_a)->next;
    tmp->previous->previous = NULL;
    ft_putendl_fd(num, STDOUT_FILENO);
}

int main()
{
    char    *num = "3 6 4 5";
    a_list  *stack_a = malloc(sizeof(char *) + 1);
    printf("%zu", ft_rotate(&stack_a, num));
    return (0);
}