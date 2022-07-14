#include "include/push_swap.h"

// Delete the first element of list
void	ft_del_firstel(t_data **stack)
{
	t_data	*tmp;

	tmp = NULL;
	if (!stack || !(*stack))
		return ;
	tmp = (*stack);
	tmp = tmp->next;
	ft_lstdel(*stack, 0);
	(*stack) = tmp;
}

// Delete the last element of list
void	ft_del_lastel(t_data **stack)
{
	t_data	*tmp;

	if (!stack || !(*stack))
		return ;
	tmp = (*stack);
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstdel(tmp->next, 0);
	tmp->next = NULL;
}

int ft_lstmin(t_data **stack)
{
    t_data  *tmp;
    int min;

    if (!stack || !(*stack))
        return (0);
    tmp = (*stack);
    min = tmp->content;
    while (tmp)
    {
        if (min > tmp->content)
            min = tmp->content;
        tmp = tmp->next;
    }
    return (min);
}