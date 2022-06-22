#include "push_swap.h"

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

int main(int argc, char **argv)
{
    int i;

    i = 1;
    if (argc == 2)
    {
        while (i < argc)
        {
            printf("%d\n", check_double(&argv[i]));
            i++;
        }
    }
    return (0);
}