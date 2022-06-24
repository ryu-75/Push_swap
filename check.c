#include "push_swap.h"

// A revoir :
// Erreur de lecture
// Le parsing n est pas fait dans son integralite
int check_double(char **args)
{
    int i;
    int j;

    i = -1;
    while (args[i])
    {
        j = i;
        while (args[j])
        {
            if (ft_strcmp(args[i], args[j]) != 1)
            {
                exit_fail();
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int check_int(int nb)
{
    if (nb < INT_MIN || nb > INT_MAX)
        return (0);
    return (1);
}

// Ajouter les valeurs dans des pointeurs temporaire pour coupler chaque arguments entre eux
// Ajouter des espaces entres chaques valeurs;
// Penser a gerer les cas d erreurs puis a free derriere
// Split le tableau **nb quand on rencontre un espace
// Retourner la nb
int convert_av(int ac, char **av, char **nb)
{
    int i;
    char    *tmp;
    char    *tmp_1;

    tmp_1 = NULL;
    i = 1;
    while (i < ac)
    {
        tmp = nb;
        if (tmp = 0)
        {
            exit_fail();
            free(tmp);
        }
        tmp_1 = ft_strjoin(tmp_1, tmp);
        free(tmp);
        tmp = ft_strjoin(tmp_1, " ");
        tmp_1(free);
        i++;
    }
    return (tmp);
}