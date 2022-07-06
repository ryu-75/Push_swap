#include "push_swap.h"

void    ft_swap(t_data *data, t_op *stack, char *str)
{
    int tmp;

    if (!stack || !stack->next)
        return ;
    tmp = stack->content;
    stack->content = stack->next->content;
    stack->next->content = tmp;
    if (str)
    {
        ft_add_value(data, str);
        printf("stack : %d\n", stack->content);
    }
}

void    ft_add_value(t_data *data, char *str)
{
    t_mov   *tmp;
    t_mov   *new;

    new = malloc(sizeof(t_mov));
    if (!new)
        return ;
    new->value = str;
    new->next = NULL;
    if (!data->mov_list)
    {
        data->mov_list = new;
        return ;
    }
    tmp = data->mov_list;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    printf("tmp : %s\n", tmp->value);
}

int main(int argc, char **argv)
{
    t_data  *data;
    t_op    *stack;
    char    **str;
    int i;
    
    i = 0;
    data = malloc(sizeof(t_data));
    stack = NULL;
    if (argc >= 2)
    {
        while (i < argc)
        {
            str = split_av(argc, argv);
            ft_add_value(data, str[i]);
            i++;
        }
        while (i < argc)
            ft_swap(data, stack, str[i++]);
    }
    return (0);
}