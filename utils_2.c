#include "push_swap.h"

void    add_to_struct(t_data *data)
{
    int i;
    t_stack  *stack_a;
    t_stack *tmp;

    i = 0;
    stack_a = NULL;
    // stack_a = malloc(sizeof(t_stack));
    if (!stack_a)
        return ;
    stack_a->previous = NULL;
    while (i < (int)data->data_size)
    {
        add_new_node(stack_a);
        stack_a->num = data->num[i++];
        tmp = stack_a;
        stack_a = stack_a->next;
        stack_a->previous = tmp;
    }
    stack_a = NULL;
}

void  print_data(t_stack *data)
{
    while (data)
    {
        printf("%d\n", data->num);
        data = data->next;
    }
}

int main(int argc, char **argv)
{
    t_data *data;
    data = malloc(sizeof(t_data));
    t_stack *dataa;
    dataa = malloc(sizeof(t_stack));

    if (argc >= 2)
    {
        add_list(data, argc, argv);
        add_to_struct(data);
        print_data(dataa);
    }
    return (0);
}
