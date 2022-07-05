#include "push_swap.h"

t_data  *add_newlst(t_data *new, int el)
{
    new = malloc(sizeof(t_data));
    if (!new)
        return (NULL);
    new->content = el;
    new->next = NULL;
    return (new);
}

// void    add_backlst(t_data **value, int el)
// {
//     t_data  *last;
//     t_data  *tmp;

//     last = malloc(sizeof(t_data));
//     if (!value)
//         return (NULL);
//     last->content = el;
//     last->next = NULL;
//     if (!last)
//     {
//         *value = new;
//         return (NULL);
//     }
//     while (value->next)
//         last = last->next;
//     last->next = new;
// }

void	ft_lstadd_back_value(t_data **lst, t_data *new)
{
	t_data	*last;

	if (!lst || !new)
		return ;
	last = *lst;
	if (!last)
	{
		*lst = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}

void    ft_printlst(t_data *stack_a)
{
    int i;

    i = 0;
    if (!stack_a)
        stack_a = malloc(sizeof(t_data));
    printf("%d\n", stack_a->content);
}

// int main(void)
// {
//     t_data  *add;
//     t_data  *new;
//     t_data  *newnew;
//     t_data  *back;
//     int value;

//     back = NULL;
//     new = NULL;
//     newnew = NULL;

//     add = add_newlst(new, 4);
//     newnew = add_newlst(new, 9);
//     back = add_backlst(&new, newnew);

//     ft_printlst(add);
//     ft_printlst(back);
//     return (0);
// }