#include "push_swap.h"

// void    add_node_front(t_lst *stack_a, char *num)
// {
//     t_lst    *new;

//     new = malloc(sizeof(t_lst));
//     if (!new)
//         return ;
//     new->content = num;
//     new->next = stack_a;
//     if (!new->content)
//         return ;
//     stack_a = new;
// }

// void    add_node_back(t_lst **add_lst, t_lst *new)
// {
//     new = malloc(sizeof(t_lst));
//     if (!new)
//         return ;
//     new->next = NULL;
//     while (new->next != NULL)
//         new->next = new;
//     *add_lst = new->next;
//     new->next = new;
//     *add_lst = new;
// }

// void    add_new_node(t_lst *new)
// {
//     new = malloc(sizeof(t_lst));
//     if (!new)
//         return ;
//     new->next = NULL;
// }

// int main(int argc, char *argv[])
// {
//     char    **str;
//     int     i;
//     t_lst   *tst;

//     tst = malloc(sizeof(t_lst));
//     i = 0;
//     str = split_av(argc, argv);
//     if (argc >= 2)
//     {
//         while (i < argc)
//             add_node_back(tst, str);
//     }
//     return (0);
// }