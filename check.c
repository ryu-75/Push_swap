#include "push_swap.h"

size_t ft_tablen(char **tab)
{
    int i;

    i = 0;
    if (!(*tab))
        return (0);
    while (*tab++)
        i++;
    return (i);
}

char **split_av(int ac, char **av)
{
    int i;
    char    *str;
    char    *tmp;
    char    **tab;

    i = 0;
    str = NULL;
    while (++i < ac)
    {
        tmp = str;
        if (ft_have_num(av[i]) == 0)
            return (write(2, "Error\n", 6), ft_free(tmp), exit(1), NULL);
        str = ft_strjoin(str, av[i]);
        if (!str)
            return (write(2, "Error\n", 6), ft_free(tmp), exit(1), NULL);
        ft_free(tmp);
        tmp = str;
        str = ft_strjoin(str, " ");
        if (!str)
            return (write(2, "Error\n", 6), ft_free(tmp), exit(1), NULL);
        ft_free(tmp);
    }
    tab = ft_split(str, ' ');
    return (ft_free(str), tab);
}

void    add_list(t_data *data, int ac, char **av)
{
    int     i;
    char    **tab;
    char    **tab_ptr;
    long int    num;
    size_t     tablen;

    i = 0;
    tab = split_av(ac, av);
    if (!data)
        data = malloc(sizeof(t_data));
    if (!tab)
        return (write(1, "Error\n", 6), exit(1));
    tab_ptr = tab;
    tablen = ft_tablen(tab);
    data->data_size = tablen;
    data->num = malloc(sizeof(int) * (size_t)data->data_size + 1);
    if (data->num == NULL)
        return (write(1, "Error\n", 6), ft_free(tab), exit(1));
    while (i < (int)data->data_size)
    {
        if (!data->data_size)
            return (write(1, "Error\n", 6), exit(1));
        num = get_my_nb(tab_ptr[i]);
        if (!ft_isnum(*tab))
            return (write(1, "Error\n", 6), ft_free(tab_ptr), exit(1));
        if (num < INT_MIN || num > INT_MAX || ft_check_db(data->num, i, num))
            return (write(1, "Error\n", 6), exit(1));
        data->num[i++] = (int)num;
        tab++;
    }
    free_tab((void **)tab_ptr);
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

// int main(int argc, char **argv)
// {
//     t_data *data;
//     data = malloc(sizeof(t_data));

//     if (argc >= 2)
//     {
//         add_list(data, argc, argv);
//         print_data(data);
//     }
//     return (0);
// }