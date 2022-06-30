#include "push_swap.h"
/*
void    ft_rotate(t_data **stack_a, char *num)
{
    t_data  *tmp;

    tmp->next = NULL;
    if (!(*stack_a) || !stack_a || !(*stack_a)->next)
        return ;
    (*stack_a)->next->next = NULL;
    tmp = ft_lstlast(*stack_a);
    (*stack_a)->next = tmp;
    (*stack_a)->next = (*stack_a)->next;
    tmp->next->next = NULL;
    ft_putendl_fd(num, STDOUT_FILENO);
}
*/

void    ft_add_value(t_data *data, char *str)
{
    t_mov   *tmp;
    t_mov   *new;

    new = malloc(sizeof(t_mov));
    if (!new)
        return ;
    tmp = new;
    while (new)
    {
        new->value = str;
        if (!new->value)
            return ;
        new->next = NULL;
    }
}

// void  print_data(t_data *data)
// {
//     size_t i;

//     i = 0;
//     while (i < data->data_size)
//     {
//         printf("%d\n", data->num[i]);
//         i++;
//     }
// }

int main(int argc, char **argv)
{
    t_data  *data;
    char    **str;

    str = split_av(argc, argv);
    data = malloc(sizeof(t_data));
    if (argc >= 2)
    {
        ft_add_value(data, str);
        print_data(data);
    }
    return (0);
}
