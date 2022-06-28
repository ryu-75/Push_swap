#include "push_swap.h"

// Ajouter les valeurs dans des pointeurs temporaire pour coupler chaque arguments entre eux
// Ajouter des espaces entres chaques valeurs;
// Penser a gerer les cas d erreurs puis a free derriere
// Split le tableau **nb quand on rencontre un espace
// Retourner la nb

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

// Tant que count est inferieur a ac, on ajoute les donnees dans le nouveau tableau de int
// On alloue de la place dans le tableau de int de la structure stack_a->num
// On recupere la taille du tableau genere par split_av avec ft_tablen

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
    {
        data = malloc(sizeof(t_data));
        //return (write(1, "Error\n", 6), exit(1));
    }
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
        // if (!ft_isnum(*tab))
        //     return (write(1, "Error\n", 6), free_tab(tab_ptr), exit(1));
        if (num < INT_MIN || num > INT_MAX)
            return (write(1, "Error\n", 6), exit(1));
        data->num[i++] = (int)num;
        tab++;
    }
    free_tab((void **)tab_ptr);
}

void  print_data(t_data *data)
{
    size_t i;

    i = 0;
    while (i < data->data_size)
    {
        printf("%d\n", data->num[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    t_data *data;
    data = malloc(sizeof(t_data));

    if (argc >= 2)
    {
        add_list(data, argc, argv);
        if (data->num[0] == data->num[1])
            printf("ERROR");
        print_data(data);
    }
    return (0);
}