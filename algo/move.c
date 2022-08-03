#include "../include/push_swap.h"

int ft_largest_value(t_lst **stack)
{
    t_data  *tmp;

    tmp = (*stack)->b;
    while (ft_lstmax(&(*stack)->b)->content != tmp->content)
        tmp = tmp->next;
    return (tmp->id);
}

void    first_b_move(t_lst *stack)
{
    int largest_value;
    int size;
    int largest_id;

    largest_value = ft_lstmax(&(stack)->b)->content;
    largest_id = ft_largest_value(&(stack));
    size = ft_set_id(&(stack)->b);
    if (largest_id > size / 2)
    {
        while (stack->b->content != largest_value)
            ft_rrotate_b(&(stack)->b, "rra", stack);
    }
    else if (largest_id <= size / 2)
    {
        while (stack->b->content != largest_value)
            ft_rotate_b(&(stack)->b, "rb", stack);
    }
    ft_push_a(&stack->b, &stack->a, "pa", stack);
}

void    check_a_b(t_lst *stack)
{
    t_data  *tmp_a;
    t_data  *tmp_b;

    tmp_b = stack->b;
    tmp_a = stack->a;
    while (tmp_b->next)
    {
        if (tmp_b->content > tmp_a->content)
            ft_rrotate_b(&(stack)->b, "rrb", stack);
        else if (tmp_b->content < tmp_a->content)
            ft_push_a(&stack->b, &stack->a, "pa", stack);
        tmp_b = tmp_b->next;
    }
}