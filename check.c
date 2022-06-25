#include "push_swap.h"

// Ajouter les valeurs dans des pointeurs temporaire pour coupler chaque arguments entre eux
// Ajouter des espaces entres chaques valeurs;
// Penser a gerer les cas d erreurs puis a free derriere
// Split le tableau **nb quand on rencontre un espace
// Retourner la nb

int ft_tablen(char **tab)
{
    int i;

    i = 0;
    if (!(*tab))
        return (0);
    while (*tab++)
        i++;
    return (i);
}

char **convert_av(int ac, char **av)
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

int main(int argc, char **argv)
{
    int     i;
    // char    **str;

    i = 1;
    if (argc >= 2)
    {
        while (i < argc)
        {
            printf("%s\n", *convert_av(argc, argv));
            i++;
        }
    }
    return (0);
}
